#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSAttackDataForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSAttackDataForm);

		// members
		void* /*NiPointer<BGSAttackDataMap>*/ attackDataMap;  // 08
	};
	static_assert(sizeof(BGSAttackDataForm) == 0x10);
}
