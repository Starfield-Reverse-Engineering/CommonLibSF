#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class TESRace :
		public TESForm  // 00
	{
	public:
		SF_RTTI_VTABLE(TESRace);
		SF_FORMTYPE(RACE);
	};
}
