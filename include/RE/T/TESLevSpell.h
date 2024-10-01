#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESLeveledList.h"

namespace RE
{
	class TESLevSpell :
		public TESBoundObject,  // 00
		public TESLeveledList   // E8
	{
	public:
		SF_RTTI_VTABLE(TESLevSpell);
		SF_FORMTYPE(LVSP);

		~TESLevSpell() override;  // 00
	};
	static_assert(sizeof(TESLevSpell) == 0x148);
}
