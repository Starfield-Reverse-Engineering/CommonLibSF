#pragma once

#include "RE/B/BSFloatCurve.h"

namespace RE
{
	class BSFloat3DCurve
	{
	public:
		// members
		BSFloatCurve curveX;  // 00
		BSFloatCurve curveY;  // 40
		BSFloatCurve curveZ;  // 80
	};
	static_assert(sizeof(BSFloat3DCurve) == 0xC0);
}
