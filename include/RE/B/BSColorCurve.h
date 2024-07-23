#pragma once

#include "RE/B/BSFloatCurve.h"

namespace RE
{
	class BSColorCurve
	{
	public:
		// members
		BSFloatCurve red;    // 00
		BSFloatCurve green;  // 40
		BSFloatCurve blue;   // 80
		BSFloatCurve alpha;  // C0
	};
	static_assert(sizeof(BSColorCurve) == 0x100);
}
