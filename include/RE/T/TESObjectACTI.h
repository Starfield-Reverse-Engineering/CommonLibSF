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
		public TESFullName,                // 0E0
		public BGSModelMaterialSwap,       // 0F0
		public TESMagicTargetForm,         // 118
		public BGSDestructibleObjectForm,  // 120
		public BGSOpenCloseForm,           // 130
		public BGSKeywordForm,             // 138
		public BGSPropertySheet,           // 168
		public BGSForcedLocRefType,        // 178
		public BGSNativeTerminalForm,      // 190
		public BGSNavmeshableObject        // 1A0
	{
	public:
		SF_RTTI_VTABLE(TESObjectACTI);
		SF_FORMTYPE(ACTI);

		~TESObjectACTI() override;  // 00

		// members
		BGSAudio::WwiseSoundHook soundLoop;        // 1A8
		BGSAudio::WwiseSoundHook soundActivate;    // 1D8
		TESWaterForm*            waterForm;        // 208
		std::uint32_t            unk210;           // 210
		std::uint16_t            flags;            // 214
		std::uint16_t            activationAngle;  // 216
		std::uint8_t             unk218;           // 218
	};
	static_assert(sizeof(TESObjectACTI) == 0x228);
}
