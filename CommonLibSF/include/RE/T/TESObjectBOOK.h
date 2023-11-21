#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSFeaturedItemMessage.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class ActorValueInfo;
	class BGSPerk;
	class BGSScene;
	class TESObjectSTAT;
	class SpellItem;

	struct OBJ_BOOK
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kAdvancesActorValue = 1 << 0,
			kCantTake = 1 << 1,
			kTeachesSpell = 1 << 2,
			kHasBeenRead = 1 << 3,
			kTeachesPerk = 1 << 4,
		};

		union Teaches
		{
			ActorValueInfo* actorValueToAdvance;
			SpellItem*      spell;
			BGSPerk*        perk;
		};
		static_assert(sizeof(Teaches) == 0x8);

		// members
		stl::enumeration<Flag, std::uint8_t> flags;        // 00
		Teaches                              teaches;      // 08
		std::uint32_t                        textOffsetX;  // 10
		std::uint32_t                        textOffsetY;  // 14
		std::uint64_t                        unk18;        // 18
	};
	static_assert(sizeof(OBJ_BOOK) == 0x20);

	class TESObjectBOOK :
		public TESBoundObject,             // 000
		public TESFullName,                // 118
		public BGSModelMaterialSwap,       // 128
		public TESValueForm,               // 150
		public TESWeightForm,              // 160
		public TESDescription,             // 170
		public BGSDestructibleObjectForm,  // 188
		public BGSPickupPutdownSounds,     // 198
		public BGSKeywordForm,             // 200
		public BGSFeaturedItemMessage      // 230
	{
	public:
		SF_RTTI_VTABLE(TESObjectBOOK);
		SF_FORMTYPE(BOOK);

		// members
		OBJ_BOOK           data;                 // 240
		TESObjectSTAT*     inventoryModel;       // 260
		TESDescription     itemCardDescription;  // 268
		BGSScene*          scene;                // 280
		BGSLocalizedString unk288;               // 288
		BGSLocalizedString unk290;               // 290
	};
	static_assert(sizeof(TESObjectBOOK) == 0x298);
}
