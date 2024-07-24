#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSTransform;

	class BGSPreviewTransform : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSPreviewTransform);

		~BGSPreviewTransform() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSPreviewTransform_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BGSTransform* transforms[8];  // 08
	};
	static_assert(sizeof(BGSPreviewTransform) == 0x48);
}
