#pragma once

#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSNavmeshableObject.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/T/TESBoundObject.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	struct TESObjectSTATData
	{
	public:
		// members
		float unk00;  // 00
		float unk04;  // 04
	};
	static_assert(sizeof(TESObjectSTATData) == 0x8);

	class TESObjectSTAT :
		public TESBoundObject,        // 000
		public BGSModelMaterialSwap,  // 0E0
		public BGSPropertySheet,      // 108
		public BGSForcedLocRefType,   // 118
		public BGSNavmeshableObject   // 130
	{
	public:
		SF_RTTI_VTABLE(TESObjectSTAT);
		SF_FORMTYPE(STAT);

		~TESObjectSTAT() override;  // 00

		// members
		TESObjectSTATData        data;          // 138
		BGSAudio::WwiseSoundHook ambientSound;  // 140
	};
	static_assert(sizeof(TESObjectSTAT) == 0x178);
}
