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
		public BGSModelMaterialSwap,  // 0E0
		public TESFullName            // 108
	{
	public:
		SF_RTTI_VTABLE(BGSLegendaryItem);
		SF_FORMTYPE(LGDI);

		~BGSLegendaryItem() override;  // 00

		// members
		TESLevItem*       applicableItemList;  // 118
		BGSLegendaryItem* legendaryTemplate;   // 120
		BSTArray<void*>   unk128[3];           // 128
	};
	static_assert(sizeof(BGSLegendaryItem) == 0x160);
}
