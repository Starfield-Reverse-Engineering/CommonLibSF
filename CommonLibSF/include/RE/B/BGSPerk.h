#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSPerk :
		public TESForm,        // 00
		public TESFullName,    // 38
		public TESDescription  // 48
	{
	public:
		SF_RTTI_VTABLE(BGSPerk);
		SF_FORMTYPE(PERK);

		~BGSPerk() override;  // 00

		// members
		std::uint16_t   unk60;     // 60
		std::uint8_t    unk62;     // 62
		std::uint8_t    unk63;     // 63
		std::uint8_t    unk64;     // 64
		std::uint64_t   unk68;     // 68
		BSFixedStringCS unk70;     // 70
		BSFixedString   perkIcon;  // 78 - GNAM
		std::uint64_t   unk80;     // 80
		std::uint64_t   unk88;     // 88
		std::uint64_t   unk90;     // 90
		std::uint64_t   unk98;     // 98
		BSTArray<void*> unkA0;     // A0
	};
	static_assert(sizeof(BGSPerk) == 0xB0);
}
