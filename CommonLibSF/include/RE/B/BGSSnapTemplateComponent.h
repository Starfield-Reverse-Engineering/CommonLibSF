#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSSnapTemplate;
	class BGSSnapBehavior;

	class BGSSnapTemplateComponent : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSSnapTemplateComponent);

		~BGSSnapTemplateComponent() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSSnapTemplateComponent_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BGSSnapTemplate* snapTemplate;  // 08
		BGSSnapBehavior* snapBehavior;  // 10
	};
	static_assert(sizeof(BGSSnapTemplateComponent) == 0x18);
}
