#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESFullName : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESFullName);

		// members
		BSFixedString fullName;  // 08 - FULL
	};
	static_assert(sizeof(TESFullName) == 0x10);
}
