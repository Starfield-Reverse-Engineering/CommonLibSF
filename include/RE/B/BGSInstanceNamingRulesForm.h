#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSInstanceNamingRules;

	class BGSInstanceNamingRulesForm : public BaseFormComponent
	{
	public:
		SF_RTTI(BGSInstanceNamingRulesForm);

		~BGSInstanceNamingRulesForm() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSInstanceNamingRulesForm_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BGSInstanceNamingRules* instanceNamingRules;  // 08
	};
	static_assert(sizeof(BGSInstanceNamingRulesForm) == 0x10);
}
