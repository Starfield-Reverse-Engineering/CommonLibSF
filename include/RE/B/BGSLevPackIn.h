#pragma once

#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESLeveledList.h"

namespace RE
{
	class BGSLevPackIn :
		public TESBoundAnimObject,    // 000
		public TESLeveledList,        // 0E0
		public BGSModelMaterialSwap,  // 140
		public BGSForcedLocRefType    // 168
	{
	public:
		SF_RTTI_VTABLE(BGSLevPackIn);
		SF_FORMTYPE(LVLP);

		~BGSLevPackIn() override;  // 00
	};
	static_assert(sizeof(BGSLevPackIn) == 0x188);
}
