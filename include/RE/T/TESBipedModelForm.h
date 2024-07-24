#pragma once

#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/S/Sexes.h"

namespace RE
{
	class TESBipedModelForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESBipedModelForm);

		~TESBipedModelForm() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESBipedModel_Component"; }
		void                 InitializeDataComponent() override;     // 02}

		// members
		BGSModelMaterialSwap worldModels[SEX::kTotal];  // 08
	};
	static_assert(sizeof(TESBipedModelForm) == 0x58);
}
