#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/T/TESObjectARMO.h"

namespace RE
{
	class BGSSkinForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSSkinForm);

		~BGSSkinForm() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSSkinForm_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		TESObjectARMO* formSkin;  // 08
	};
	static_assert(sizeof(BGSSkinForm) == 0x10);
}
