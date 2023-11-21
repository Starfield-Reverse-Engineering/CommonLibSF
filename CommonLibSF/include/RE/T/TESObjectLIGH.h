#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSOpenCloseForm.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class TESObjectLIGH :
		public TESBoundAnimObject,         // 000
		public BGSModelMaterialSwap,       // 118
		public TESWeightForm,              // 140
		public TESValueForm,               // 150
		public BGSDestructibleObjectForm,  // 160
		public BGSEquipType,               // 170
		public BGSPropertySheet,           // 180
		public BGSOpenCloseForm,           // 190
		public BGSKeywordForm              // 198
	{
	public:
		SF_RTTI_VTABLE(TESObjectLIGH);
		SF_FORMTYPE(LIGH);
	};
	//static_assert(sizeof(TESObjectLIGH) == 0x300);
}
