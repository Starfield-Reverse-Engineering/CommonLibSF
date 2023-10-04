#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSPerk;

	struct PerkRankData
	{
		// members
		BGSPerk*    perk;         // 00
		std::int8_t currentRank;  // 08
	};
	static_assert(sizeof(PerkRankData) == 0x10);

	class BGSPerkRankArray : public BaseFormComponent
	{
	public:
		SF_RTTI(BGSPerkRankArray);

		~BGSPerkRankArray() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSPerkRankArray_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		PerkRankData* perks;      // 08
		std::uint32_t perkCount;  // 10
	};
	static_assert(sizeof(BGSPerkRankArray) == 0x18);
}
