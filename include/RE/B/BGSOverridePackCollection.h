#pragma once

#include "RE/B/BGSListForm.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSOverridePackCollection : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSOverridePackCollection);

		~BGSOverridePackCollection() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSOverridePackCollection_Component"; }
		void                 InitializeDataComponent() override;     // 02

		// members
		BGSListForm* unk08;  // 08
		BGSListForm* unk10;  // 10
		BGSListForm* unk18;  // 18
		BGSListForm* unk20;  // 20
		BGSListForm* unk28;  // 28
		BGSListForm* unk30;  // 30
		BGSListForm* unk38;  // 38
		BGSListForm* unk40;  // 40
	};
	static_assert(sizeof(BGSOverridePackCollection) == 0x48);
}
