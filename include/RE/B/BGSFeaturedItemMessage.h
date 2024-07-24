#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSMessage;

	class BGSFeaturedItemMessage : public BaseFormComponent
	{
	public:
		SF_RTTI(BGSFeaturedItemMessage);

		~BGSFeaturedItemMessage() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSFeaturedItemMessage_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BGSMessage* message;  // 08
	};
	static_assert(sizeof(BGSFeaturedItemMessage) == 0x10);
}
