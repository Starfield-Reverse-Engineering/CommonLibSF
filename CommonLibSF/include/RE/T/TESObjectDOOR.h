#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSNativeTerminalForm.h"
#include "RE/B/BGSNavmeshableObject.h"
#include "RE/B/BGSOpenCloseForm.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESMagicTargetForm.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class TESObjectDOOR :
		public TESBoundAnimObject,         // 000
		public TESFullName,                // 118
		public BGSModelMaterialSwap,       // 128
		public TESMagicTargetForm,         // 150
		public BGSDestructibleObjectForm,  // 158
		public BGSOpenCloseForm,           // 168
		public BGSKeywordForm,             // 170
		public BGSNativeTerminalForm,      // 1A0
		public BGSForcedLocRefType,        // 1B0
		public BGSPropertySheet,           // 1C8
		public BGSNavmeshableObject        // 1D8
	{
	public:
		SF_RTTI_VTABLE(TESObjectDOOR);
		SF_FORMTYPE(DOOR);

		enum class Flag
		{
			kNone = 0,
			kAutomatic = 1 << 1,
			kHidden = 1 << 2,
			kMinimalUse = 1 << 3,
			kSliding = 1 << 4,
			kDoNotOpenInCombatSearch = 1 << 5,
			kNoToText = 1 << 6
		};

		~TESObjectDOOR() override;  // 00

		// members
		BGSLocalizedString                   altOpenText;      // 1E0
		BGSLocalizedString                   altCloseText;     // 1E8
		BGSAudio::WwiseSoundHook             openSound;        // 1F0
		BGSAudio::WwiseSoundHook             closeSound;       // 220
		BGSAudio::WwiseSoundHook             lockSound;        // 250
		std::uint32_t                        unk280;           // 280
		std::uint32_t                        unk284;           // 284
		stl::enumeration<Flag, std::uint8_t> flags;            // 288
		BSTArray<TESForm*>                   randomTeleports;  // 290
	};
	static_assert(sizeof(TESObjectDOOR) == 0x2A0);
}
