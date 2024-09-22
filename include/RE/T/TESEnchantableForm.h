#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/M/MagicSystem.h"

namespace RE
{
	class EnchantmentItem;

	class TESEnchantableForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESEnchantableForm);

		~TESEnchantableForm() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESEnchantableForm_Component"; }
		void                 InitializeDataComponent() override;     // 02

		// add
		[[nodiscard]] virtual MagicSystem::CastingType GetCastingType() const;  // 04 - { return castingType; }

		// members
		EnchantmentItem*                                   formEnchanting;       // 08
		REX::Enum<MagicSystem::CastingType, std::uint16_t> castingType;          // 10
		std::uint16_t                                      amountofEnchantment;  // 12
	};
	static_assert(sizeof(TESEnchantableForm) == 0x18);
}
