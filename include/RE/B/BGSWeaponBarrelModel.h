#pragma once

#include "RE/B/BGSBaseForm.h"
#include "RE/I/IBGSBaseFormData.h"

namespace RE
{
	class BGSWeaponBarrelData : public IBGSBaseFormData
	{
	public:
		SF_RTTI_VTABLE(BGSWeaponBarrelData);

		~BGSWeaponBarrelData() override;  // 00

		// override (IBGSBaseFormData)
		void                 Load(std::uint64_t a_arg2, std::uint32_t a_id, TESFile* a_file) override;  // 03
		bool                 Compare(IBGSBaseFormData* a_data) override;                                // 04
		void                 Copy(IBGSBaseFormData* a_data, TESForm* a_owner) override;                 // 05
		const BSFixedString& GetFormDataType() override;                                                // 06 - return { "WeaponBarrelData"; }

		// members
		bool  allowCoverState;                  // 08
		float coverDetectionDistance;           // 0C
		float enterCoverAnimationTime;          // 10
		float hipFireDuringCoverAnimationTime;  // 14
	};
	static_assert(sizeof(BGSWeaponBarrelData) == 0x18);

	class BGSWeaponBarrelModel : public BGSBaseFormT<BGSWeaponBarrelData, FormType::kWBAR>
	{
	public:
		SF_RTTI_VTABLE(BGSWeaponBarrelModel);
		SF_FORMTYPE(WBAR);

		~BGSWeaponBarrelModel() override;  // 00
	};
	static_assert(sizeof(BGSWeaponBarrelModel) == 0x58);
}
