#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSKeywordForm.h"
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
	class TESWaterForm;

	class TESObjectACTI :
		public TESBoundAnimObject,         // 000
		public TESFullName,                // 118
		public BGSModelMaterialSwap,       // 128
		public TESMagicTargetForm,         // 150
		public BGSDestructibleObjectForm,  // 158
		public BGSOpenCloseForm,           // 168
		public BGSKeywordForm,             // 170
		public BGSPropertySheet,           // 1A0
		public BGSForcedLocRefType,        // 1B0
		public BGSNativeTerminalForm,      // 1C8
		public BGSNavmeshableObject        // 1D8
	{
	public:
		SF_RTTI_VTABLE(TESObjectACTI);
		SF_FORMTYPE(ACTI);

		~TESObjectACTI() override;  // 00

		// members
		BGSAudio::WwiseSoundHook soundLoop;        // 1E0
		BGSAudio::WwiseSoundHook soundActivate;    // 210
		TESWaterForm*            waterForm;        // 240
		std::uint32_t            unk248;           // 248
		std::uint16_t            flags;            // 24C
		std::uint16_t            activationAngle;  // 24E
		std::uint8_t             unk250;           // 250
	};
	static_assert(sizeof(TESObjectACTI) == 0x258);
}
