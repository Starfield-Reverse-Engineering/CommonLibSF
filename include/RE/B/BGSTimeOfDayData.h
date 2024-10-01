#pragma once

#include "RE/B/BGSReflectedForm.h"
#include "RE/B/BSColorCurve.h"

namespace RE
{
	class BGSTimeOfDayData : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSTimeOfDayData);
		SF_FORMTYPE(TODD);

		~BGSTimeOfDayData() override;  // 00

		// members
		BSColorCurve colorAtTime;               // 030
		BSFloatCurve luminanceAtTime;           // 130
		float        lightLuminanceMultiplier;  // 170
	};
	static_assert(sizeof(BGSTimeOfDayData) == 0x180);
}
