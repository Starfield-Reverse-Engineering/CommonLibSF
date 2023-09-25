#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class TESWorldSpace :
		public TESForm,     // 00
		public TESFullName  // 20
	{
	public:
		SF_FORMTYPE(WRLD);
	};
}
