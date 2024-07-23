#pragma once

#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSTTuple3.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSPropertySheet : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSPropertySheet);

		~BGSPropertySheet() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSPropertySheet_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BSTArray<BSTTuple3<TESForm*, TESForm*, BGSTypedFormValuePair::SharedVal>>* properties;  // 08
	};
	static_assert(sizeof(BGSPropertySheet) == 0x10);
}
