#pragma once

#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESLeveledList.h"

namespace RE
{
	class BGSLevGenericBaseForm :
		public TESBoundAnimObject,   // 000
		public TESLeveledList,       // 118
		public BGSModelMaterialSwap  // 178
	{
	public:
		SF_RTTI_VTABLE(BGSLevGenericBaseForm);
		SF_FORMTYPE(LVLB);

		~BGSLevGenericBaseForm() override;  // 00
	};
	static_assert(sizeof(BGSLevGenericBaseForm) == 0x170);
}
