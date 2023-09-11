#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESFullName : public BaseFormComponent
	{
	public:
		TES_RTTI_VTABLE(TESFullName);

		// members
		void* fullName;  // 08 BSFixedString - FULL
	};
	static_assert(sizeof(TESFullName) == 0x10);
}
