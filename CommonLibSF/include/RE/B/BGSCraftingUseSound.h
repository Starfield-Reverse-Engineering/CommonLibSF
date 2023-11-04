#pragma once

#include "RE/B/BGSSoundReference.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSCraftingUseSound : public BaseFormComponent
	{
	public:
		SF_RTTI(BGSCraftingUseSound);

		~BGSCraftingUseSound() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSCraftingUseSound_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BGSSoundReference craftingUseSound;  // 08
	};
	static_assert(sizeof(BGSCraftingUseSound) == 0x38);
}
