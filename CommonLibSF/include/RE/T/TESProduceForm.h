#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class TESBoundObject;

	struct SEASON
	{
		enum : std::uint32_t
		{
			kNone = static_cast<std::uint32_t>(-1),
			kSpring = 0,
			kSummer,
			kFall,
			kWinter,

			kTotal,
		};
	};

	class TESProduceForm : public BaseFormComponent
	{
	public:
		SF_RTTI(TESProduceForm);

		~TESProduceForm() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESProduce_Component"; }
		void                 InitializeDataComponent() override;     // 02

		// members
		BGSAudio::WwiseSoundHook harvestSound;                   // 08
		TESBoundObject*          produceItem;                    // 38
		std::int8_t              produceChance[SEASON::kTotal];  // 40
	};
	static_assert(sizeof(TESProduceForm) == 0x48);
}
