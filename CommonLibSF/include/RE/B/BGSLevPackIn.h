#pragma once

#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESLeveledList.h"

namespace RE
{
	class BGSLevPackIn :
		public TESBoundAnimObject,    // 000
		public TESLeveledList,        // 118
		public BGSModelMaterialSwap,  // 178
		public BGSForcedLocRefType    // 1A0
	{
	public:
		SF_RTTI_VTABLE(BGSLevPackIn);
		SF_FORMTYPE(LVLP);

		~BGSLevPackIn() override;  // 00
	};
	static_assert(sizeof(BGSLevPackIn) == 0x1B8);
}
