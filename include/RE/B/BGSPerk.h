#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSKeyword;

	class BGSPerk :
		public TESForm,        // 00
		public TESFullName,    // 30
		public TESDescription  // 40
	{
	public:
		SF_RTTI_VTABLE(BGSPerk);
		SF_FORMTYPE(PERK);

		~BGSPerk() override;  // 00

		// members
		std::uint16_t   unk58;         // 58
		std::uint8_t    unk5A;         // 5A
		std::uint8_t    unk5B;         // 5B
		std::uint8_t    unk5C;         // 5C
		BGSPerk*        trainingPerk;  // 60
		BSFixedStringCS unk68;         // 68
		BSFixedString   perkIcon;      // 70 - GNAM
		BGSKeyword*     restriction;   // 78
		std::uint64_t   unk80;         // 80
		std::uint64_t   unk88;         // 88
		std::uint64_t   unk90;         // 90
		BSTArray<void*> unk98;         // 98
	};
	static_assert(sizeof(BGSPerk) == 0xB0);
}
