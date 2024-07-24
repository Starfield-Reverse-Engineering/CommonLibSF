#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESValueForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESValueForm);

		~TESValueForm() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESValue_Component"; }
		void                 InitializeDataComponent() override;     // 02

		// members
		std::int32_t value;  // 08
	};
	static_assert(sizeof(TESValueForm) == 0x10);
}
