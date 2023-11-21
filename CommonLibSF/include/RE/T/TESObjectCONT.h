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

		stl::enumeration<Flag, std::uint8_t> contFlags;  // 0
	};
	static_assert(sizeof(CONT_DATA) == 0x1);

	class TESObjectCONT :
		public TESBoundAnimObject,         // 000
		public TESContainer,               // 118
		public TESFullName,                // 130
		public BGSModelMaterialSwap,       // 140
		public TESMagicTargetForm,         // 168
		public BGSDestructibleObjectForm,  // 170
		public BGSOpenCloseForm,           // 180
		public BGSKeywordForm,             // 188
		public BGSForcedLocRefType,        // 1B8
		public BGSPropertySheet,           // 1D0
		public BGSNativeTerminalForm       // 1E0
	{
	public:
		SF_RTTI_VTABLE(TESObjectCONT);
		SF_FORMTYPE(CONT);

		~TESObjectCONT() override;  // 00

		// members
		CONT_DATA                data;              // 1F0
		BGSAudio::WwiseSoundHook openSound;         // 1F8
		BGSAudio::WwiseSoundHook closeSound;        // 228
		BGSAudio::WwiseSoundHook takeAllSound;      // 258
		BGSListForm*             containsOnlyList;  // 288
		BGSAttachParentArray     attachParents;     // 290
		std::uint8_t             unk2B0;            // 2B0
	};
	static_assert(sizeof(TESObjectCONT) == 0x2B8);
}
