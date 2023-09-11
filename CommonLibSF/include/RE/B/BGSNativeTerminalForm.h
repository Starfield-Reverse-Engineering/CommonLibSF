#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/B/BGSTerminal.h"

namespace RE
{
	class BGSNativeTerminalForm : public BaseFormComponent
	{
	public:
		BGSTerminal* terminal;  // 08
	};
	static_assert(sizeof(BGSNativeTerminalForm) == 0x10);
}

