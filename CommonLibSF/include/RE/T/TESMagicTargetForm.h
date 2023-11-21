#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESMagicTargetForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESMagicTargetForm);

		~TESMagicTargetForm() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESMagicTargetForm_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }
	};
	static_assert(sizeof(TESMagicTargetForm) == 0x8);
}
