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
			stl::enumeration<MagicSystem::CastingType, std::int32_t> castingType;       // 00
			std::uint32_t                                            chargeOverride;    // 0C
			stl::enumeration<MagicSystem::Delivery, std::uint8_t>    delivery;          // 10
			stl::enumeration<MagicSystem::SpellType, std::uint8_t>   spellType;         // 11
			float                                                    chargeTime;        // 14
			EnchantmentItem*                                         baseEnchantment;   // 18
			BGSListForm*                                             wornRestrictions;  // 20
		};
		static_assert(sizeof(Data) == 0x28);

		// members
		Data data;  // 188
	};
	static_assert(sizeof(EnchantmentItem) == 0x1B0);
}
