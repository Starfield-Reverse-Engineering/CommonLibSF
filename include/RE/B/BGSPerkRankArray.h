#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	struct PerkRankData;

	class BGSPerkRankArray : public BaseFormComponent
	{
	public:
		SF_RTTI(BGSPerkRankArray);

		~BGSPerkRankArray() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSPerkRankArray_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BSTArray<PerkRankData> perks;  // 08
	};
	static_assert(sizeof(BGSPerkRankArray) == 0x18);
}
