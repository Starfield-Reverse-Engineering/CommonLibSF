#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSCraftingUseSound : public BaseFormComponent
	{
	public:
		SF_RTTI(BGSCraftingUseSound);

		~BGSCraftingUseSound() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSCraftingUseSound_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		std::uint64_t unk08;  // 08
		std::uint64_t unk10;  // 10
		std::uint64_t unk18;  // 18
		std::uint64_t unk20;  // 20
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
	};
	static_assert(sizeof(BGSCraftingUseSound) == 0x38);
}
