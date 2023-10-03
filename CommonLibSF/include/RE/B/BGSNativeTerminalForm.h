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

		// members
		BGSTerminal* terminal;  // 08
	};
	static_assert(sizeof(BGSNativeTerminalForm) == 0x10);
}
