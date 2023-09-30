#pragma once

#include "RE/I/IMenu.h"

namespace RE
{
	class GameMenuBase :
		public IMenu  // 00
	{
	public:
		SF_RTTI_VTABLE(GameMenuBase);

		GameMenuBase() = default;

		virtual ~GameMenuBase() = default;  // 00
	};
}
