#pragma once

#include "RE/T/TESObjectACTI.h"

namespace RE
{
	class TESObjectREFR;
	class BGSVoiceType;

	class BGSTalkingActivator : public TESObjectACTI
	{
	public:
		SF_RTTI_VTABLE(BGSTalkingActivator);
		SF_FORMTYPE(TACT);

		~BGSTalkingActivator() override;  // 00

		// add
		virtual bool GetReflectedByAutoWater();  // 82 - { return false; }

		// members
		TESObjectREFR* tempRef;    // 220
		BGSVoiceType*  voiceType;  // 228
	};
	static_assert(sizeof(BGSTalkingActivator) == 0x238);
}
