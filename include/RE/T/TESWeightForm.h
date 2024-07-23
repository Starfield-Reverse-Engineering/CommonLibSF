#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESWeightForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESWeightForm);

		~TESWeightForm() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESWeight_Component"; }
		void                 InitializeDataComponent() override;     // 02

		// members
		float weight;  // 08
	};
	static_assert(sizeof(TESWeightForm) == 0x10);
}
