#pragma once

#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSMenuDisplayObject.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/M/MagicItem.h"
#include "RE/T/TESDescription.h"

namespace RE
{
	class BGSPerk;

	class SpellItem :
		public MagicItem,               // 000
		public BGSEquipType,            // 150
		public BGSMenuDisplayObject,    // 160
		public BGSPickupPutdownSounds,  // 170
		public TESDescription           // 1D8
	{
	public:
		SF_RTTI_VTABLE(SpellItem);
		SF_FORMTYPE(SPEL);

		class Data :
			public MagicItem::Data  // 00
		{
		public:
			// members
			REX::Enum<MagicSystem::SpellType, std::uint8_t>   spellType;     // 08
			float                                             chargeTime;    // 0C
			REX::Enum<MagicSystem::CastingType, std::uint8_t> castingType;   // 10
			REX::Enum<MagicSystem::Delivery, std::uint8_t>    delivery;      // 11
			float                                             castDuration;  // 14
			float                                             range;         // 18
			BGSPerk*                                          castingPerk;   // 20
		};
		static_assert(sizeof(Data) == 0x28);

		~SpellItem() override;  // 00

		// add
		virtual bool IsSpell();                                         // 9E - return { GetSpellType() == 0; }
		virtual void SetSpellType(MagicSystem::SpellType a_spellType);  // 9F

		// members
		Data data;  // 1F0
	};
	static_assert(sizeof(SpellItem) == 0x220);
}
