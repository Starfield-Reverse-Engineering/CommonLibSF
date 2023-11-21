#pragma once

#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESLeveledList.h"

namespace RE
{
	class TESLevCharacter :
		public TESBoundAnimObject,   // 000
		public TESLeveledList,       // 118
		public BGSModelMaterialSwap  // 178
	{
	public:
		SF_RTTI_VTABLE(TESLevCharacter);
		SF_FORMTYPE(LVLN);

		~TESLevCharacter() override;  // 00
	};
	static_assert(sizeof(TESLevCharacter) == 0x1A0);
}
