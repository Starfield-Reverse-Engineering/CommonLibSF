#pragma once

#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class TESLevItem;

	class BGSLegendaryItem :
		public TESBoundObject,        // 000
		public BGSModelMaterialSwap,  // 118
		public TESFullName            // 140
	{
	public:
		SF_RTTI_VTABLE(BGSLegendaryItem);
		SF_FORMTYPE(LGDI);

		~BGSLegendaryItem() override;  // 00

		// members
		TESLevItem*       applicableItemList;  // 150
		BGSLegendaryItem* legendaryTemplate;   // 158
		BSTArray<void*>   unk160[3];           // 160
	};
	static_assert(sizeof(BGSLegendaryItem) == 0x190);
}
