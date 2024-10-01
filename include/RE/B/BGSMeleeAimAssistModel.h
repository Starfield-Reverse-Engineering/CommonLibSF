#pragma once

#include "RE/B/BGSBaseForm.h"
#include "RE/I/IBGSBaseFormData.h"

namespace RE
{
	class MeleeAimAssistData : public IBGSBaseFormData
	{
	public:
		SF_RTTI_VTABLE(MeleeAimAssistData);

		~MeleeAimAssistData() override;  // 00

		// override (IBGSBaseFormData)
		void                 Load(std::uint64_t a_arg2, std::uint32_t a_id, TESFile* a_file) override;  // 03
		bool                 Compare(IBGSBaseFormData* a_data) override;                                // 04
		void                 Copy(IBGSBaseFormData* a_data, TESForm* a_owner) override;                 // 05
		const BSFixedString& GetFormDataType() override;                                                // 06 - return { "MeleeAimAssistData"; }

		// members
		float outerConeAngle;             // 08
		float innerConeAngle;             // 0C
		float steeringDegreesPerSec;      // 10
		float snapSteeringMultOuterRing;  // 14
		float snapSteeringMultInnerRing;  // 18
		float maxAimAssistDistance;       // 1C
		float unk20;                      // 20
		bool  aimAssistEnabled;           // 24
	};
	static_assert(sizeof(MeleeAimAssistData) == 0x28);

	class BGSMeleeAimAssistModel : public BGSBaseFormT<MeleeAimAssistData, FormType::kMAAM>
	{
	public:
		SF_RTTI_VTABLE(BGSMeleeAimAssistModel);
		SF_FORMTYPE(MAAM);

		~BGSMeleeAimAssistModel() override;  // 00
	};
	static_assert(sizeof(BGSMeleeAimAssistModel) == 0x68);
}
