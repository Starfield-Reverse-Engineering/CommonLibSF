#pragma once

#include "RE/U/UICellRenderer.h"

namespace RE
{
	class BGSKeyword;
	class MenuActor;
	class TESObjectREFR;

	class MenuPaperDoll :
		public UICellRenderer
	{
	public:
		SF_RTTI_VTABLE(MenuPaperDoll);

		virtual ~MenuPaperDoll();  // 00

		// members
		std::uint64_t  unk070;                  // 070
		std::uint64_t  unk078;                  // 078
		std::uint64_t  unk080;                  // 080
		std::uint64_t  unk088;                  // 088
		std::uint64_t  unk090;                  // 090
		std::uint64_t  unk098;                  // 098
		std::uint64_t  unk0A0;                  // 0A0
		std::uint64_t  unk0A8;                  // 0A8
		MenuActor*     menuActor;               // 0B0
		std::byte      pad0B8[(0x1A0 - 0xB8)];  // 0B8
		BGSKeyword*    unk1A0;                  // 1A0
		TESObjectREFR* unk1A8;                  // 1A8
	};
	static_assert(offsetof(MenuPaperDoll, menuActor) == 0xB0);
	static_assert(offsetof(MenuPaperDoll, unk1A0) == 0x1A0);
}
