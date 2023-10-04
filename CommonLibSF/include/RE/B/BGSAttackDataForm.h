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

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSAttackData_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		NiPointer<BGSAttackDataMap> attackDataMap;  // 08
	};
	static_assert(sizeof(BGSAttackDataForm) == 0x10);
}
