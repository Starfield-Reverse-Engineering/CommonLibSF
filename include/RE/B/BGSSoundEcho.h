#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class BGSSoundEcho : public TESBoundAnimObject
	{
	public:
		SF_RTTI_VTABLE(BGSSoundEcho);
		SF_FORMTYPE(SECH);

		~BGSSoundEcho() override;  // 00

		// members
		BSTArray<void*>          unk0E0;  // 0E0
		BGSAudio::WwiseSoundHook unk128;  // 0F0
	};
	static_assert(sizeof(BGSSoundEcho) == 0x128);
}
