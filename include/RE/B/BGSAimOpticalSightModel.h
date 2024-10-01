#pragma once

#include "RE/B/BGSBaseForm.h"
#include "RE/I/IBGSBaseFormData.h"

namespace RE
{
	class BGSArtObject;
	class TESObjectLIGH;

	class AimOpticalSightData : public IBGSBaseFormData
	{
	public:
		SF_RTTI_VTABLE(AimOpticalSightData);

		~AimOpticalSightData() override;  // 00

		// override (IBGSBaseFormData)
		void                 Load(std::uint64_t a_arg2, std::uint32_t a_id, TESFile* a_file) override;  // 03
		bool                 Compare(IBGSBaseFormData* a_data) override;                                // 04
		void                 Copy(IBGSBaseFormData* a_data, TESForm* a_owner) override;                 // 05
		const BSFixedString& GetFormDataType() override;                                                // 06 - return { "AimOpticalSightData"; }

		// members
		float          unk08;                        // 08
		float          unk0C;                        // 0C
		TESObjectLIGH* light;                        // 10
		BGSArtObject*  beamArt;                      // 18
		BGSArtObject*  dotArt;                       // 20
		BSFixedString  nodeName;                     // 28
		float          beamReactivationDelayReload;  // 30
		float          beamDeactivationDelayReload;  // 34
		float          beamReactivationDelayFiring;  // 38
		float          unk3C;                        // 3C
		bool           unk40;                        // 40
		bool           hideBeamByDefault;            // 41
		bool           showBeamAtHip;                // 42
		bool           unk43;                        // 43
	};
	static_assert(sizeof(AimOpticalSightData) == 0x48);

	class BGSAimOpticalSightModel : public BGSBaseFormT<AimOpticalSightData, FormType::kAOPS>
	{
	public:
		SF_RTTI_VTABLE(BGSAimOpticalSightModel);
		SF_FORMTYPE(AOPS);

		~BGSAimOpticalSightModel() override;  // 00
	};
	static_assert(sizeof(BGSAimOpticalSightModel) == 0x88);
}
