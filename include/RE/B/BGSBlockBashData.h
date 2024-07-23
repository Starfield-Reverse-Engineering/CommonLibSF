#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSImpactDataSet;
	class BGSMaterialType;

	class BGSBlockBashData : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSBlockBashData);

		~BGSBlockBashData() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSBlockBashData_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BGSImpactDataSet* blockBashImpactDataSet;  // 08
		BGSMaterialType*  altBlockMaterialType;    // 10
	};
	static_assert(sizeof(BGSBlockBashData) == 0x18);
}
