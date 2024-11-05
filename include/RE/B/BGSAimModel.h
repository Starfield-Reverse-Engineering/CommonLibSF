#pragma once

#include "RE/B/BGSBaseForm.h"
#include "RE/I/IBGSBaseFormData.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	class AimModelData : public IBGSBaseFormData
	{
	public:
		SF_RTTI_VTABLE(AimModelData);

		~AimModelData() override;  // 00

		// override (IBGSBaseFormData)
		void                 Load(std::uint64_t a_arg2, std::uint32_t a_id, TESFile* a_file) override;  // 03
		bool                 Compare(IBGSBaseFormData* a_data) override;                                // 04
		void                 Copy(IBGSBaseFormData* a_data, TESForm* a_owner) override;                 // 05
		const BSFixedString& GetFormDataType() override;                                                // 06 - { return "AimModelData"; }

		// members
		NiPoint2      coneOfFireAngle;            // 08
		float         coneOfFireIncreasePerShot;  // 10
		float         coneOfFireDecreasePerShot;  // 14
		float         coneOfFireDecreaseDelay;    // 18
		float         coneOfFireSneakMult;        // 1C
		float         recoilDiminishSpringForce;  // 20
		float         recoilDiminishSpringMult;   // 24
		NiPoint2      recoilPerShot;              // 28
		float         recoilHipMult;              // 30
		std::uint32_t runawayRecoilShots;         // 34
		float         recoilArc;                  // 38
		float         recoilArcRotate;            // 3C
		float         coneOfFireIronSightsMult;   // 40
		float         baseStability;              // 44
	};
	static_assert(sizeof(AimModelData) == 0x48);

	class BGSAimModel : public BGSBaseFormT<AimModelData, FormType::kAMDL>
	{
	public:
		SF_RTTI_VTABLE(BGSAimModel);
		SF_FORMTYPE(AMDL);

		~BGSAimModel() override;  // 00
	};
	static_assert(sizeof(BGSAimModel) == 0x88);
}
