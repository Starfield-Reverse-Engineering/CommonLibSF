#pragma once

#include "RE/B/BGSBaseForm.h"
#include "RE/I/IBGSBaseFormData.h"

namespace RE
{
	class AimAssistData : public IBGSBaseFormData
	{
	public:
		SF_RTTI_VTABLE(AimAssistData);

		~AimAssistData() override;  // 00

		void                 Load(std::uint64_t a_arg2, std::uint32_t a_id, TESFile* a_file) override;  // 03
		bool                 Compare(IBGSBaseFormData* a_data) override;                                // 04
		void                 Copy(IBGSBaseFormData* a_data, TESForm* a_owner) override;                 // 05
		const BSFixedString& GetFormDataType() override;                                                // 06 - { return "AimAssistData"; }

		// members
		float innerConeAngle;                   // 08
		float outerConeAngle;                   // 0C
		float steeringDegreesPerSec;            // 10
		float pitchScale;                       // 14
		float innerSteeringRing;                // 18
		float outerSteeringRing;                // 1C
		float friction;                         // 20
		float moveFollowDegreesPerSec;          // 24
		float snapSteeringMultADS;              // 28
		float snapSecondsADS;                   // 2C
		float snapConeAngleADS;                 // 30
		float noSteering;                       // 34
		float bulletBendingConeAngle;           // 38
		float snapSteeringMultInnerRingADS;     // 3C
		float snapSteeringMultOuterRingADS;     // 40
		float innerConeAngleMultADS;            // 44
		float outerConeAngleMultADS;            // 48
		float innerSteeringRingMultADS;         // 4C
		float outerSteeringRingMultADS;         // 50
		float frictionMultADS;                  // 54
		float steeringDegreesPerSecondMultADS;  // 58
		bool  aimAssistEnabled;                 // 5C
	};
	static_assert(sizeof(AimAssistData) == 0x60);

	class BGSAimAssistModel : public BGSBaseFormT<AimAssistData, FormType::kAAMD>
	{
	public:
		SF_RTTI_VTABLE(BGSAimAssistModel);
		SF_FORMTYPE(AAMD);

		~BGSAimAssistModel() override;  // 00
	};
	static_assert(sizeof(BGSAimAssistModel) == 0xA0);
}
