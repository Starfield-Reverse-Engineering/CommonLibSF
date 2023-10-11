#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSAimAssistPoseData;
	class BGSBodyPartData;

	struct FACEFX_BONESET;

	class BGSBodyPartInfo : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSBodyPartInfo);

		~BGSBodyPartInfo() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSBodyPartInfo_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BGSBodyPartData*      unk08;  // 08
		FACEFX_BONESET*       unk10;  // 10
		FACEFX_BONESET*       unk18;  // 18
		BGSAimAssistPoseData* unk20;  // 20
	};
	static_assert(sizeof(BGSBodyPartInfo) == 0x28);
}
