#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class MenuOpenCloseEvent
	{
	public:
		// members
		BSFixedString menuName;  // 00
		bool          opening;   // 08
	};
	static_assert(sizeof(MenuOpenCloseEvent) == 0x10);
}
