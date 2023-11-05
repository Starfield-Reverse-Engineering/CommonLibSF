#pragma once

#include "RE/W/WwiseGUID.h"

namespace RE
{
	class BGSConditionForm;
	class BGSWwiseEventForm;

	namespace BGSAudio
	{
		class WwiseSoundHook
		{
		public:
			// members
			WwiseGUID          startEvent;  // 00
			WwiseGUID          stopEvent;   // 10
			BGSConditionForm*  conditions;  // 20
			BGSWwiseEventForm* eventData;   // 28
		};
		static_assert(sizeof(WwiseSoundHook) == 0x30);
	}
}
