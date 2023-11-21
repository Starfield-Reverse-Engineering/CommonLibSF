#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESBoundObject.h"
#include "RE/W/WWiseSoundHook.h"

namespace RE
{
	class BGSAmbienceSet;
	class BGSMusicType;
	class BGSReverbParameters;

	class BGSAcousticSpace : public TESBoundObject
	{
	public:
		SF_RTTI_VTABLE(BGSAcousticSpace);
		SF_FORMTYPE(ASPC);

		~BGSAcousticSpace() override;  // 00

		// members
		BGSAudio::WwiseSoundHook sound0;           // 118
		BGSAudio::WwiseSoundHook sound1;           // 148
		BGSAudio::WwiseSoundHook sound2;           // 178
		BGSMusicType*            music;            // 1A8
		BGSAmbienceSet*          ambienceSet;      // 1B0
		BGSReverbParameters*     environmentType;  // 1B8
		std::uint32_t            unk1C0;           // 1C0
		float                    unk1C4;           // 1C4
		float                    unk1C8;           // 1C8
		std::uint8_t             unk1CC;           // 1CC
		std::uint8_t             unk1CD;           // 1CD
		std::uint32_t            unk1D0;           // 1D0
	};
	static_assert(sizeof(BGSAcousticSpace) == 0x1D8);
}
