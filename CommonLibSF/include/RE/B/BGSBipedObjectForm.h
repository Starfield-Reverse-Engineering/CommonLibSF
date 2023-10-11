#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	struct BIPED_MODEL
	{
	public:
		// members
		std::uint32_t bipedObjectSlots;  // 0
	};
	static_assert(sizeof(BIPED_MODEL) == 0x4);

	class BGSBipedObjectForm : public BaseFormComponent
	{
	public:
		SF_RTTI(BGSBipedObjectForm);

		~BGSBipedObjectForm() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSBipedObject_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BIPED_MODEL bipedModelData;  // 08
	};
	static_assert(sizeof(BGSBipedObjectForm) == 0x10);
}
