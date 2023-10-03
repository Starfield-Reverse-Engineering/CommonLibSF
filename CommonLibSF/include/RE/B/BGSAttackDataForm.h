#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BGSAttackDataMap;

	class BGSAttackDataForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSAttackDataForm);

		~BGSAttackDataForm() override;  // 00

		// members
		NiPointer<BGSAttackDataMap> attackDataMap;  // 08
	};
	static_assert(sizeof(BGSAttackDataForm) == 0x10);
}
