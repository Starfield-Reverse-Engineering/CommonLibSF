#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSTerminal;

	class BGSNativeTerminalForm : public BaseFormComponent
	{
	public:
		SF_RTTI(BGSNativeTerminalForm);

		~BGSNativeTerminalForm() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSNativeTerminalForm_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BGSTerminal* terminal;  // 08
	};
	static_assert(sizeof(BGSNativeTerminalForm) == 0x10);
}
