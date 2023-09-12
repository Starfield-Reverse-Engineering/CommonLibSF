#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class BGSLocation :
		public TESForm  // 00
						// ...
	{
	public:
		SF_RTTI_VTABLE(BGSLocation);
		SF_FORMTYPE(LCTN);
	};
}
