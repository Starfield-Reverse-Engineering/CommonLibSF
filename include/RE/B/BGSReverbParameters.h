#pragma once

#include "RE/T/TESForm.h"
#include "RE/W/WwiseGUID.h"

namespace RE
{
	class BGSReverbParameters : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSReverbParameters);
		SF_FORMTYPE(REVB);

		enum class ReverbClass
		{
			kDefault,
			kClassA,
			kClassB,
			kClassC,
			kClassD,
			kClassE
		};

		~BGSReverbParameters() override;  // 00

		// members
		REX::Enum<ReverbClass, std::uint32_t> reverbClass;  // 30
		BGSAudio::WwiseGUID                   audioBus;     // 38
	};
	static_assert(sizeof(BGSReverbParameters) == 0x50);
}
