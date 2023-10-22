#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSPickupPutdownSounds : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSPickupPutdownSounds);

		~BGSPickupPutdownSounds() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSPickupPutdownSounds_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		std::uint64_t unk08;  // 08
		std::uint64_t unk10;  // 10
		std::uint64_t unk18;  // 18
		std::uint64_t unk20;  // 20
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
		std::uint64_t unk38;  // 38
		std::uint64_t unk40;  // 40
		std::uint64_t unk48;  // 48
		std::uint64_t unk50;  // 50
		std::uint64_t unk58;  // 58
		std::uint64_t unk60;  // 60
	};
	static_assert(sizeof(BGSPickupPutdownSounds) == 0x68);
}
