#pragma once

#include "RE/B/BGSCraftingResourceOwner.h"
#include "RE/B/BGSCraftingUseSound.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/M/MagicItem.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class SpellItem;

	class AlchemyItem :
		public MagicItem,                  // 000
		public BGSModelMaterialSwap,       // 188
		public TESWeightForm,              // 1B0
		public BGSEquipType,               // 1C0
		public BGSDestructibleObjectForm,  // 1D0
		public BGSPickupPutdownSounds,     // 1E0
		public BGSCraftingUseSound,        // 240
		public TESDescription,             // 280
		public BGSCraftingResourceOwner    // 298
	{
	public:
		SF_RTTI_VTABLE(AlchemyItem);
		SF_FORMTYPE(ALCH);

		enum class AlchemyFlag
		{
			kNone = 0,
			kCostOverride = 1 << 0,
			kFoodItem = 1 << 1,
			kExtendDuration = 1 << 3,
			kMedicine = 1 << 16,
			kPoison = 1 << 17
		};

		class Data :
			public MagicItem::Data  // 00
		{
		public:
			// members
			SpellItem*               addictionItem;     // 08
			float                    addictionChance;   // 10
			BGSAudio::WwiseSoundHook consumptionSound;  // 18
			BGSLocalizedString       addictionName;     // 48
		};
		static_assert(sizeof(Data) == 0x50);

		~AlchemyItem() override;  // 00

		// members
		Data data;  // 280
	};
	static_assert(sizeof(AlchemyItem) == 0x2D8);
}
