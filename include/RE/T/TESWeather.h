#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class TESWeather :
		public TESForm,        // 00
		public BGSKeywordForm  // 30
	{
	public:
		SF_RTTI_VTABLE(TESWeather);
		SF_FORMTYPE(WTHR);

		~TESWeather() override;  // 00
	};
	//static_assert(sizeof(TESWeather) == 0xFC0);
}
