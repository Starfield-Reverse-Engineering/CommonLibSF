#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/W/WwiseSoundHook.h"

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
		BGSAudio::WwiseSoundHook pickupSound;   // 08
		BGSAudio::WwiseSoundHook putdownSound;  // 38
	};
	static_assert(sizeof(BGSPickupPutdownSounds) == 0x68);
}
