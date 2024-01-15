#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/T/TESForm.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class BGSTimeOfDayData;

	namespace BSGalaxy
	{
		class BGSSunPresetForm;

		class BGSStar :
			public TESForm,        // 00
			public BGSKeywordForm  // 30
		{
		public:
			SF_RTTI_VTABLE(BSGalaxy__BGSStar);
			SF_FORMTYPE(STDT);

			~BGSStar() override;  // 00

			// members
			std::uint32_t            uniqueID;   // 60
			BGSStar*                 unk68;      // 68
			BGSSunPresetForm*        sunPreset;  // 70
			BGSTimeOfDayData*        timeOfDay;  // 78
			BGSAudio::WwiseSoundHook unk80;      // 80
		};
		static_assert(sizeof(BGSStar) == 0xB0);
	}
}
