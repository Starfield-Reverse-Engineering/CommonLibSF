#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESWorldSpace.h"

namespace RE
{
	class TESObjectCELL :
		public TESForm,     // 00
		public TESFullName  // 20
	{
	public:
		SF_RTTI_VTABLE(TESObjectCELL);
		SF_FORMTYPE(CELL);
    	UInt16					flags;				// 48
    	bool pad[22];
    	TESWorldSpace* CellWorldspace; // 60
	};
}
