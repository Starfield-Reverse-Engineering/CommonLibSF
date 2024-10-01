#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESLeveledList.h"

namespace RE
{
	class BGSLevSpaceCell :
		public TESForm,        // 00
		public TESLeveledList  // 30
	{
	public:
		SF_RTTI_VTABLE(BGSLevSpaceCell);
		SF_FORMTYPE(LVSC);

		~BGSLevSpaceCell() override;  // 00
	};
	static_assert(sizeof(BGSLevSpaceCell) == 0x98);
}
