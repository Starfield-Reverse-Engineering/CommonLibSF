#pragma once

#include "RE/B/BGSAttachParentArray.h"
#include "RE/T/TESObjectACTI.h"
#include "RE/T/TESProduceForm.h"

namespace RE
{
	class BGSExplosion;
	class TESGlobal;

	class TESFlora :
		public TESObjectACTI,  // 000
		public TESProduceForm  // 220
	{
	public:
		SF_RTTI_VTABLE(TESFlora);
		SF_FORMTYPE(FLOR);

		~TESFlora() override;  // 00

		// members
		BGSAttachParentArray     attachParents;  // 268
		BGSAudio::WwiseSoundHook sound;          // 288
		BGSKeyword*              actionKeyword;  // 2B8
		TESGlobal*               maxGlobal;      // 2C0
		TESGlobal*               minGlobal;      // 2C8
		BGSExplosion*            explosion;      // 2D0
		float                    unk2D8;         // 2D8
		float                    unk2DC;         // 2DC
		std::uint32_t            unk2E0;         // 2E0
	};
	static_assert(sizeof(TESFlora) == 0x2F0);
}
