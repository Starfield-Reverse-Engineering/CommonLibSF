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
		public TESFullName,                // 0E0
		public BGSModelMaterialSwap,       // 0F0
		public TESValueForm,               // 118
		public TESWeightForm,              // 128
		public BGSDestructibleObjectForm,  // 138
		public BGSCraftingUseSound,        // 148
		public BGSPickupPutdownSounds,     // 180
		public BGSKeywordForm,             // 1E8
		public BGSFeaturedItemMessage,     // 218
		public BGSCraftingResourceOwner    // 228
	{
	public:
		SF_RTTI_VTABLE(TESObjectMISC);
		SF_FORMTYPE(MISC);

		~TESObjectMISC() override;  // 00

		// add
		virtual void Unk_82();  // 82 - { return; }

		// members
		BGSLocalizedString shortName;  // 248
		std::uint32_t      flags;      // 250
	};
	static_assert(sizeof(TESObjectMISC) == 0x260);
}
