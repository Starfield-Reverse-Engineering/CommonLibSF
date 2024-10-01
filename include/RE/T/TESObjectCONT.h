#pragma once

#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSNativeTerminalForm.h"
#include "RE/B/BGSOpenCloseForm.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESContainer.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESMagicTargetForm.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class BGSListForm;

	struct CONT_DATA
	{
		enum class Flag
		{
			kNone = 0,
			kAllowsSoundsWhenAnimation = 1 << 0,
			kRespawn = 1 << 1,
			kShowOwner = 1 << 2
		};

		REX::EnumSet<Flag, std::uint8_t> contFlags;  // 0
	};
	static_assert(sizeof(CONT_DATA) == 0x1);

	class TESObjectCONT :
		public TESBoundAnimObject,         // 000
		public TESContainer,               // 0E0
		public TESFullName,                // 0F8
		public BGSModelMaterialSwap,       // 108
		public TESMagicTargetForm,         // 130
		public BGSDestructibleObjectForm,  // 138
		public BGSOpenCloseForm,           // 148
		public BGSKeywordForm,             // 150
		public BGSForcedLocRefType,        // 180
		public BGSPropertySheet,           // 198
		public BGSNativeTerminalForm       // 1A8
	{
	public:
		SF_RTTI_VTABLE(TESObjectCONT);
		SF_FORMTYPE(CONT);

		~TESObjectCONT() override;  // 00

		// members
		CONT_DATA                data;              // 1B8
		BGSAudio::WwiseSoundHook openSound;         // 1C0
		BGSAudio::WwiseSoundHook closeSound;        // 1F0
		BGSAudio::WwiseSoundHook takeAllSound;      // 220
		BGSListForm*             containsOnlyList;  // 250
		BGSAttachParentArray     attachParents;     // 258
		std::uint8_t             unk278;            // 278
	};
	static_assert(sizeof(TESObjectCONT) == 0x288);
}
