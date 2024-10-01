#pragma once

#include "RE/M/MagicItem.h"

namespace RE
{
	class BGSListForm;

	class EnchantmentItem : public MagicItem
	{
	public:
		SF_RTTI_VTABLE(EnchantmentItem);
		SF_FORMTYPE(ENCH);

		class Data :
			public MagicItem::Data  // 00
		{
		public:
			// members
			REX::Enum<MagicSystem::CastingType, std::int32_t> castingType;       // 00
			std::uint32_t                                     chargeOverride;    // 0C
			REX::Enum<MagicSystem::Delivery, std::uint8_t>    delivery;          // 10
			REX::Enum<MagicSystem::SpellType, std::uint8_t>   spellType;         // 11
			float                                             chargeTime;        // 14
			EnchantmentItem*                                  baseEnchantment;   // 18
			BGSListForm*                                      wornRestrictions;  // 20
		};
		static_assert(sizeof(Data) == 0x28);

		// members
		Data data;  // 150
	};
	static_assert(sizeof(EnchantmentItem) == 0x180);
}
