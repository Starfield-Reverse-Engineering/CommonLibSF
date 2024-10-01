#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESBoundObject.h"
#include "RE/W/WwiseSoundHook.h"

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
		BGSAudio::WwiseSoundHook sound0;           // 0E0
		BGSAudio::WwiseSoundHook sound1;           // 110
		BGSAudio::WwiseSoundHook sound2;           // 140
		BGSMusicType*            music;            // 170
		BGSAmbienceSet*          ambienceSet;      // 178
		BGSReverbParameters*     environmentType;  // 180
		std::uint32_t            unk188;           // 188
		float                    unk18C;           // 18C
		float                    unk190;           // 190
		std::uint8_t             unk194;           // 194
		std::uint8_t             unk195;           // 195
		std::uint32_t            unk198;           // 198
	};
	static_assert(sizeof(BGSAcousticSpace) == 0x1A8);
}
