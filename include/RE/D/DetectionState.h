#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiRefObject.h"

namespace RE
{
	struct DetectionLevels
	{
		std::int16_t visual;
		std::int16_t sound;
	};

	class __declspec(novtable) DetectionState :
		public NiRefObject
	{
	public:
		SF_RTTI_VTABLE(DetectionState);

		// members
		std::byte       pad10[0x6C];     // 10
		DetectionLevels detectionLevel;  // 7C
	};
	static_assert(offsetof(DetectionState, detectionLevel) == 0x7C);
}
