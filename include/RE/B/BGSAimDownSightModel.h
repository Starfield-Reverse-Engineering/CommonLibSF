#pragma once

#include "RE/B/BGSBaseForm.h"
#include "RE/I/IBGSBaseFormData.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	class TESImageSpaceModifier;

	class AimDownSightData : public IBGSBaseFormData
	{
	public:
		SF_RTTI_VTABLE(AimDownSightData);

		enum class OVERLAY
		{
			kDefault,
			kFine,
			kDuplex,
			kGerman,
			kDot,
			kMilDot,
			kCircle,
			kOldRangefind,
			kModernRangefind,
			kSVD,
			kHandPainted,
			kBinoculars,
			kCross,
			kDoubleZero,
			kRangefinder1,
			kRangefinder2,
			kRectangle,
			kTactical4x,
			kTactical2x
		};

		~AimDownSightData() override;  // 00

		// override (IBGSBaseFormData)
		void                 Load(std::uint64_t a_arg2, std::uint32_t a_id, TESFile* a_file) override;  // 03
		bool                 Compare(IBGSBaseFormData* a_data) override;                                // 04
		void                 Copy(IBGSBaseFormData* a_data, TESForm* a_owner) override;                 // 05
		const BSFixedString& GetFormDataType() override;                                                // 06 - { return "AimDownSightData"; }

		// members
		TESImageSpaceModifier*              imod;                         // 08
		NiPoint3                            cameraOffset;                 // 10
		float                               distanceFromCameraOffsetADS;  // 1C
		float                               fovMult;                      // 20
		bool                                heightDelayEnabledADS;        // 24
		float                               heightDelayADS;               // 28
		bool                                depthEnabledADS;              // 2C
		float                               depthDelayADS;                // 30
		REX::EnumSet<OVERLAY, std::uint8_t> overlay;                      // 34
	};
	static_assert(sizeof(AimDownSightData) == 0x38);

	class BGSAimDownSightModel : public BGSBaseFormT<AimDownSightData, FormType::kZOOM>
	{
	public:
		SF_RTTI_VTABLE(BGSAimDownSightModel);
		SF_FORMTYPE(ZOOM);

		~BGSAimDownSightModel() override;  // 00
	};
	static_assert(sizeof(BGSAimDownSightModel) == 0x78);
}
