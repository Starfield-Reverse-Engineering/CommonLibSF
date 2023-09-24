#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSLocation :
		public TESForm,     // 00
		public TESFullName  // 20
							// ...
	{
	public:
		SF_RTTI_VTABLE(BGSLocation);
		SF_FORMTYPE(LCTN);
	};
}
