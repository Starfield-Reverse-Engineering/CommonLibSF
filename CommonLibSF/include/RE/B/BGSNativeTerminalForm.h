#pragma once

#include "RE/B/BGSTerminal.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSNativeTerminalForm : public BaseFormComponent
	{
	public:
		BGSTerminal* terminal;  // 08
	};
	static_assert(sizeof(BGSNativeTerminalForm) == 0x10);
}
