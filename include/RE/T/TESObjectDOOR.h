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
		public TESFullName,                // 0E0
		public BGSModelMaterialSwap,       // 0F0
		public TESMagicTargetForm,         // 118
		public BGSDestructibleObjectForm,  // 120
		public BGSOpenCloseForm,           // 130
		public BGSKeywordForm,             // 138
		public BGSNativeTerminalForm,      // 168
		public BGSForcedLocRefType,        // 178
		public BGSPropertySheet,           // 190
		public BGSNavmeshableObject        // 1A0
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
		BGSLocalizedString               altOpenText;      // 1A8
		BGSLocalizedString               altCloseText;     // 1B0
		BGSAudio::WwiseSoundHook         openSound;        // 1B8
		BGSAudio::WwiseSoundHook         closeSound;       // 1E8
		BGSAudio::WwiseSoundHook         lockSound;        // 218
		std::uint32_t                    unk248;           // 248
		std::uint32_t                    unk24C;           // 24C
		REX::EnumSet<Flag, std::uint8_t> flags;            // 250
		BSTArray<TESForm*>               randomTeleports;  // 258
	};
	static_assert(sizeof(TESObjectDOOR) == 0x270);
}
