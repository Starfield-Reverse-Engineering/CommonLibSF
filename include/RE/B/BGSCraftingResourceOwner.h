#pragma once

#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple3.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSCraftingResourceOwner : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSCraftingResourceOwner);

		~BGSCraftingResourceOwner() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSCraftingResourceOwner_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BSTArray<BSTTuple3<TESForm*, TESForm*, BGSTypedFormValuePair::SharedVal>>* componentData;  // 08
		BSTArray<void*>                                                            unk10;          // 10
	};
	static_assert(sizeof(BGSCraftingResourceOwner) == 0x20);
}
