#pragma once

#include "RE/B/BGSCraftingResourceOwner.h"
#include "RE/B/BGSCraftingUseSound.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSFeaturedItemMessage.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class TESObjectMISC :
		public TESBoundObject,             // 000
		public TESFullName,                // 118
		public BGSModelMaterialSwap,       // 128
		public TESValueForm,               // 150
		public TESWeightForm,              // 160
		public BGSDestructibleObjectForm,  // 170
		public BGSCraftingUseSound,        // 180
		public BGSPickupPutdownSounds,     // 1B8
		public BGSKeywordForm,             // 220
		public BGSFeaturedItemMessage,     // 250
		public BGSCraftingResourceOwner    // 260
	{
	public:
		SF_RTTI_VTABLE(TESObjectMISC);
		SF_FORMTYPE(MISC);

		~TESObjectMISC() override;  // 00

		// members
		BGSLocalizedString shortName;  // 280
		std::uint32_t      flags;      // 288
	};
	static_assert(sizeof(TESObjectMISC) == 0x290);
}
