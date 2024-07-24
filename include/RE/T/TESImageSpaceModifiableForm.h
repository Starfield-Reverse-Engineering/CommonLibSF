#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESImageSpaceModifier;

	class TESImageSpaceModifiableForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESImageSpaceModifiableForm);

		~TESImageSpaceModifiableForm() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESImageSpaceModifiableForm_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		TESImageSpaceModifier* imageSpaceModifying;  // 08 - MNAM
	};
	static_assert(sizeof(TESImageSpaceModifiableForm) == 0x10);
}
