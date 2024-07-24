#include "SFSE/Trampoline.h"

#include "SFSE/Logger.h"

// xbyak brings in <Windows.h>
#ifdef SFSE_SUPPORT_XBYAK
#	define NOMINMAX
#	include <xbyak/xbyak.h>
#	undef MEM_COMMIT
#	undef MEM_FREE
#	undef MEM_RESERVE
#	undef PAGE_EXECUTE_READWRITE
#endif

namespace SFSE
{
#ifdef SFSE_SUPPORT_XBYAK
	void* Trampoline::allocate(Xbyak::CodeGenerator& a_code)
	{
		auto result = do_allocate(a_code.getSize());
		log_stats();
		std::memcpy(result, a_code.getCode(), a_code.getSize());
		return result;
	}
#endif

	// https://stackoverflow.com/a/54732489
	void* Trampoline::do_create(const std::size_t a_size, const std::uintptr_t a_address)
	{
		constexpr std::size_t    gigabyte = static_cast<std::size_t>(1) << 30;
		constexpr std::size_t    minRange = gigabyte * 2;
		constexpr std::uintptr_t maxAddr = std::numeric_limits<std::uintptr_t>::max();

		WinAPI::SYSTEM_INFO si;
		WinAPI::GetSystemInfo(&si);
		const std::uint32_t granularity = si.allocationGranularity;

		std::uintptr_t       min = a_address >= minRange ? detail::roundup(a_address - minRange, granularity) : 0;
		const std::uintptr_t max = a_address < (maxAddr - minRange) ? detail::rounddown(a_address + minRange, granularity) : maxAddr;

		WinAPI::MEMORY_BASIC_INFORMATION mbi;
		do {
			if (!WinAPI::VirtualQuery(reinterpret_cast<void*>(min), std::addressof(mbi), sizeof(mbi))) {
				log::error("VirtualQuery failed with code: 0x{:08X}"sv, WinAPI::GetLastError());
				return nullptr;
			}

			const auto baseAddr = reinterpret_cast<std::uintptr_t>(mbi.baseAddress);
			min = baseAddr + mbi.regionSize;

			if (mbi.state == WinAPI::MEM_FREE) {
				const std::uintptr_t addr = detail::roundup(baseAddr, granularity);

				// if rounding didn't advance us into the next region and the region is the required size
				if (addr < min && (min - addr) >= a_size) {
					const auto mem = WinAPI::VirtualAlloc(reinterpret_cast<void*>(addr), a_size, WinAPI::MEM_COMMIT | WinAPI::MEM_RESERVE, WinAPI::PAGE_EXECUTE_READWRITE);
					if (mem) {
						return mem;
					}
					log::warn("VirtualAlloc failed with code: 0x{:08X}"sv, WinAPI::GetLastError());
				}
			}
		} while (min < max);

		return nullptr;
	}

	void Trampoline::log_stats() const
	{
		auto pct = (static_cast<double>(_size) / static_cast<double>(_capacity)) * 100.0;
		log::debug("{} => {}B / {}B ({:05.2f}%)"sv, _name, _size, _capacity, pct);
	}
}
