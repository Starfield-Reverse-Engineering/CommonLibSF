#pragma once

#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESLeveledList.h"

namespace RE
{
	class TESLevItem :
		public TESBoundObject,        // 000
		public TESLeveledList,        // 118
		public BGSModelMaterialSwap,  // 178
		public BGSForcedLocRefType    // 1A0
	{
	public:
		SF_RTTI_VTABLE(TESLevItem);
		SF_FORMTYPE(LVLI);

		~TESLevItem() override;  // 00
	};
	static_assert(sizeof(TESLevItem) == 0x1B8);
}
