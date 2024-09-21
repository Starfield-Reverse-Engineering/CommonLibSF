#pragma once

#include "REL/Version.h"

#include "REX/W32/KERNEL32.h"

namespace REL
{
	class Segment
	{
	public:
		enum Name : std::size_t
		{
			textx,
			idata,
			rdata,
			data,
			pdata,
			tls,
			textw,
			gfids,
			total
		};

		constexpr Segment() noexcept = default;

		constexpr Segment(const std::uintptr_t a_proxyBase, const std::uintptr_t a_address, const std::uintptr_t a_size) noexcept :
			_proxyBase(a_proxyBase), _address(a_address), _size(a_size)
		{}

		[[nodiscard]] constexpr std::uintptr_t address() const noexcept { return _address; }
		[[nodiscard]] constexpr std::size_t    offset() const noexcept { return address() - _proxyBase; }
		[[nodiscard]] constexpr std::size_t    size() const noexcept { return _size; }

		[[nodiscard]] constexpr void* pointer() const noexcept
		{
			return std::bit_cast<void*>(address());
		}

		template <class T>
		[[nodiscard]] constexpr T* pointer() const noexcept
		{
			return static_cast<T*>(pointer());
		}

	private:
		friend class Module;

		std::uintptr_t _proxyBase{};
		std::uintptr_t _address{};
		std::size_t    _size{};
	};

	class Module
	{
	public:
		constexpr Module() = delete;

		explicit Module(const std::uintptr_t a_base)
		{
			stl_assert(a_base, "failed to initializing module info with null module base");

			_base = a_base;

			const auto dosHeader = reinterpret_cast<const REX::W32::IMAGE_DOS_HEADER*>(_base);
			const auto ntHeader = stl::adjust_pointer<REX::W32::IMAGE_NT_HEADERS64>(dosHeader, dosHeader->lfanew);
			const auto sections = REX::W32::IMAGE_FIRST_SECTION(ntHeader);
			const auto size = std::min<std::size_t>(ntHeader->fileHeader.sectionCount, _segments.size());

			for (std::size_t i = 0; i < size; ++i) {
				const auto& section = sections[i];
				if (const auto it = std::ranges::find_if(SEGMENTS.begin(), SEGMENTS.end(), [&](auto&& a_elem) {
						constexpr auto size_s = std::extent_v<decltype(section.name)>;
						const auto     len = (std::min)(a_elem.first.size(), size_s);
						return std::memcmp(a_elem.first.data(), section.name, len) == 0 && (section.characteristics & a_elem.second) == a_elem.second;
					});
					it != SEGMENTS.end()) {
					const auto idx = static_cast<std::size_t>(std::distance(SEGMENTS.begin(), it));
					_segments[idx] = Segment{ _base, _base + section.virtualAddress, section.virtualSize };
				}
			}

			_file = stl::utf8_to_utf16(REX::W32::GetProcPath(nullptr)).value();
			_version = get_file_version(_file).value();
		}

		explicit constexpr Module(std::string_view a_filePath)
		{
			const auto base = AsAddress(REX::W32::GetModuleHandleA(a_filePath.data())) & ~3;
			stl_assert(base,
				"failed to initializing module info with file {}",
				a_filePath);

			*this = Module(base);
		}

		[[nodiscard]] constexpr auto base() const noexcept { return _base; }

		template <typename T = void>
		[[nodiscard]] constexpr auto pointer() const noexcept
		{
			return std::bit_cast<T*>(base());
		}

		[[nodiscard]] constexpr auto segment(const Segment::Name a_segment) const noexcept { return _segments[a_segment]; }

		[[nodiscard]] constexpr auto version() const noexcept { return _version; }

		[[nodiscard]] static Module& get(const std::uintptr_t a_address) noexcept
		{
			static std::unordered_map<std::uintptr_t, Module> managed;

			const auto base = AsAddress(a_address) & ~3;
			if (!managed.contains(base)) {
				managed.try_emplace(base, base);
			}

			return managed.at(base);
		}

		[[nodiscard]] static Module& get(const std::string_view a_filePath = {}) noexcept
		{
			const auto base = AsAddress(REX::W32::GetModuleHandleA(a_filePath.empty() ? REX::W32::GetProcPath(nullptr).data() : a_filePath.data()));
			return get(base);
		}

	private:
		static constexpr std::array SEGMENTS{
			std::make_pair(".text"sv, REX::W32::IMAGE_SCN_MEM_EXECUTE),
			std::make_pair(".idata"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".rdata"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".data"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".pdata"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".tls"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".text"sv, REX::W32::IMAGE_SCN_MEM_WRITE),
			std::make_pair(".gfids"sv, static_cast<std::uint32_t>(0))
		};

		std::uintptr_t                      _base;
		std::array<Segment, Segment::total> _segments;
		Version                             _version;
		std::wstring                        _file;
	};
}
