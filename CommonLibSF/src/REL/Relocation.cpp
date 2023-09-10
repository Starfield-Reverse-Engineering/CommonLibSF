#include "REL/Relocation.h"

#define WIN32_LEAN_AND_MEAN

#define NOGDICAPMASKS
#define NOVIRTUALKEYCODES
// #define NOWINMESSAGES
#define NOWINSTYLES
#define NOSYSMETRICS
#define NOMENUS
#define NOICONS
#define NOKEYSTATES
#define NOSYSCOMMANDS
#define NORASTEROPS
#define NOSHOWWINDOW
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
// #define NOCTLMGR
#define NODRAWTEXT
#define NOGDI
#define NOKERNEL
// #define NOUSER
#define NONLS
// #define NOMB
#define NOMEMMGR
#define NOMETAFILE
#define NOMINMAX
// #define NOMSG
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOWH
#define NOWINOFFSETS
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX

#include <Windows.h>
#include <winreg.h>

namespace REL
{
	Module::Module(std::uintptr_t a_base)
	{
		stl_assert(a_base, "failed to initializing module info with null module base");

		_base = a_base;

		auto        dosHeader = reinterpret_cast<const ::IMAGE_DOS_HEADER*>(_base);
		auto        ntHeader = stl::adjust_pointer<::IMAGE_NT_HEADERS64>(dosHeader, dosHeader->e_lfanew);
		const auto* sections = IMAGE_FIRST_SECTION(ntHeader);
		const auto  size = std::min<std::size_t>(ntHeader->FileHeader.NumberOfSections, _segments.size());

		for (std::size_t i = 0; i < size; ++i) {
			const auto& section = sections[i];
			const auto  it = std::find_if(SEGMENTS.begin(), SEGMENTS.end(), [&](auto&& a_elem) {
                constexpr auto size = std::extent_v<decltype(section.Name)>;
                const auto     len = (std::min)(a_elem.first.size(), size);
                return std::memcmp(a_elem.first.data(), section.Name, len) == 0 && (section.Characteristics & a_elem.second) == a_elem.second;
            });
			if (it != SEGMENTS.end()) {
				const auto idx = static_cast<std::size_t>(std::distance(SEGMENTS.begin(), it));
				_segments[idx] = Segment{ _base, _base + section.VirtualAddress, section.Misc.VirtualSize };
			}
		}
	}

	Module::Module(std::string_view a_filePath)
	{
		const auto base = AsAddress(GetModuleHandle(a_filePath.data())) & ~3;
		stl_assert(base, "failed to initializing module info with file {}", a_filePath);

		*this = Module(base);
	}
}  // namespace REL
