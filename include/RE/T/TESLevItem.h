#pragma once

#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESLeveledList.h"

namespace RE
{
	class TESLevItem :
		public TESBoundObject,        // 000
		public TESLeveledList,        // 0E0
		public BGSModelMaterialSwap,  // 140
		public BGSForcedLocRefType    // 168
	{
	public:
		SF_RTTI_VTABLE(TESLevItem);
		SF_FORMTYPE(LVLI);

		~TESLevItem() override;  // 00
	};
	static_assert(sizeof(TESLevItem) == 0x188);
}
