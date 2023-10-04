#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSSnapTemplateComponent : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSSnapTemplateComponent);

		virtual ~BGSSnapTemplateComponent() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSSnapTemplateComponent_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		std::uint64_t unk08;  // 08
		std::uint64_t unk10;  // 10
	};
	static_assert(sizeof(BGSSnapTemplateComponent) == 0x18);
}
