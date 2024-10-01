#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class TESSound :
		public TESBoundAnimObject,  // 00
		public BGSKeywordForm       // E8
	{
	public:
		SF_RTTI_VTABLE(TESSound);
		SF_FORMTYPE(SOUN);

		~TESSound() override;  // 00

		// members
		BGSAudio::WwiseSoundHook sound;   // 110 - SMLS
		std::uint64_t            unk140;  // 140
	};
	static_assert(sizeof(TESSound) == 0x150);
}
