#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESLeveledList.h"

namespace RE
{
	class TESLevSpell :
		public TESBoundObject,  // 000
		public TESLeveledList   // 118
	{
	public:
		SF_RTTI_VTABLE(TESLevSpell);
		SF_FORMTYPE(LVSP);

		~TESLevSpell() override;  // 00
	};
	static_assert(sizeof(TESLevSpell) == 0x178);
}
