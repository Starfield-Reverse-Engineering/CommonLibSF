#include "REL/Module.h"

namespace REL
{
	Module::Module(const std::uintptr_t a_base)
	{
		stl_assert(a_base, "failed to initializing module info with null module base");

		_base = a_base;

		const auto dosHeader = reinterpret_cast<const WinAPI::IMAGE_DOS_HEADER*>(_base);
		const auto ntHeader = stl::adjust_pointer<WinAPI::IMAGE_NT_HEADERS64>(dosHeader, dosHeader->lfanew);
		const auto sections = WinAPI::IMAGE_FIRST_SECTION(ntHeader);
		const auto size = std::min<std::size_t>(ntHeader->fileHeader.sectionCount, _segments.size());

		for (std::size_t i = 0; i < size; ++i) {
			const auto& section = sections[i];
			const auto  it = std::ranges::find_if(SEGMENTS.begin(), SEGMENTS.end(), [&](auto&& a_elem) {
                constexpr auto size_s = std::extent_v<decltype(section.name)>;
                const auto     len = (std::min)(a_elem.first.size(), size_s);
                return std::memcmp(a_elem.first.data(), section.name, len) == 0 && (section.characteristics & a_elem.second) == a_elem.second;
            });
			if (it != SEGMENTS.end()) {
				const auto idx = static_cast<std::size_t>(std::distance(SEGMENTS.begin(), it));
				_segments[idx] = Segment{ _base, _base + section.virtualAddress, section.virtualSize };
			}
		}

		_file = stl::utf8_to_utf16(WinAPI::GetProcPath(nullptr)).value();
		_version = get_file_version(_file).value();
	}

	constexpr Module::Module(std::string_view a_filePath)
	{
		const auto base = AsAddress(WinAPI::GetModuleHandle(a_filePath.data())) & ~3;
		stl_assert(base,
			"failed to initializing module info with file {}",
			a_filePath);

		*this = Module(base);
	}

	[[nodiscard]] Module& Module::get(const std::uintptr_t a_address) noexcept
	{
		static std::unordered_map<std::uintptr_t, Module> managed;

		const auto base = AsAddress(a_address) & ~3;
		if (!managed.contains(base)) {
			managed.try_emplace(base, base);
		}

		return managed.at(base);
	}

	[[nodiscard]] Module& Module::get(const std::string_view a_filePath) noexcept
	{
		const auto base = AsAddress(WinAPI::GetModuleHandle(a_filePath.empty() ? WinAPI::GetProcPath(nullptr).data() : a_filePath.data()));
		return get(base);
	}
}
