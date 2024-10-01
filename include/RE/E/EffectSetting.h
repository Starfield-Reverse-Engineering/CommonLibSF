#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BGSMenuDisplayObject.h"
#include "RE/B/BSTArray.h"
#include "RE/E/EffectArchetypes.h"
#include "RE/M/MagicSystem.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class ActorValueInfo;
	class BGSArtObject;
	class BGSDualCastData;
	class BGSExplosion;
	class BGSImpactDataSet;
	class BGSPerk;
	class BGSProjectile;
	class TESEffectShader;
	class SpellItem;
	class TESImageSpaceModifier;
	class TESObjectLIGH;

	class EffectSetting :
		public TESForm,               // 000
		public TESFullName,           // 030
		public BGSMenuDisplayObject,  // 040
		public BGSKeywordForm         // 050
	{
	public:
		SF_RTTI_VTABLE(EffectSetting);
		SF_FORMTYPE(MGEF);

		using FilterValidationFunction_t = bool(EffectSetting*, void*);

		struct EffectSettingData
		{
		public:
			enum class Flag
			{
				kNone = 0,
				kHostile = 1 << 0,
				kRecover = 1 << 1,
				kDetrimental = 1 << 2,
				kSnapToNavMesh = 1 << 3,
				kNoHitEvent = 1 << 4,
				kDispelWithKeywords = 1 << 8,
				kNoDuration = 1 << 9,
				kNoMagnitude = 1 << 10,
				kNoArea = 1 << 11,
				kFXPersist = 1 << 12,
				kGoryVisuals = 1 << 14,
				kHideInUI = 1 << 15,
				kNoRecast = 1 << 17,
				kPowerAffectsMagnitude = 1 << 21,
				kPowerAffectsDuration = 1 << 22,
				kPainless = 1 << 26,
				kNoHitEffect = 1 << 27,
				kNoDeathDispel = 1 << 28
			};

			// members
			TESForm*                                                associatedForm;         // 00
			ActorValueInfo*                                         associatedSkill;        // 08
			BGSArtObject*                                           castingArt;             // 10
			BGSDualCastData*                                        dualCastData;           // 18
			TESEffectShader*                                        effectShader;           // 20
			TESEffectShader*                                        enchantShader;          // 28
			BGSArtObject*                                           enchantEffectArt;       // 30
			SpellItem*                                              equipAbility;           // 38
			BGSExplosion*                                           explosion;              // 40
			BGSArtObject*                                           hitEffectArt;           // 48
			TESImageSpaceModifier*                                  imageSpaceMod;          // 50
			BGSImpactDataSet*                                       impactDataSet;          // 58
			TESObjectLIGH*                                          light;                  // 60
			BGSPerk*                                                perk;                   // 68
			ActorValueInfo*                                         primaryAV;              // 70
			BGSProjectile*                                          projectile;             // 78
			ActorValueInfo*                                         resistVariable;         // 80
			ActorValueInfo*                                         secondaryAV;            // 88
			float                                                   baseCost;               // 90
			float                                                   taperWeight;            // 94
			std::uint32_t                                           spellMakingArea;        // 98
			float                                                   spellMakingChargeTime;  // 9C
			float                                                   taperCurve;             // A0
			float                                                   taperDuration;          // A4
			float                                                   secondaryAVWeight;      // A8
			float                                                   skillUsageMult;         // AC
			float                                                   dualCastScale;          // B0
			float                                                   unkB4;                  // B4
			float                                                   unkB8;                  // B8
			std::uint32_t                                           minimumSkill;           // BC
			REX::EnumSet<Flag, std::uint32_t>                       flags;                  // C0
			REX::Enum<EffectArchetypes::ArchetypeID, std::uint32_t> archetype;              // C4
			REX::Enum<MagicSystem::CastingType, std::uint8_t>       castingType;            // C8
			REX::Enum<MagicSystem::Delivery, std::uint8_t>          deliveryType;           // C9
			std::uint32_t                                           unkCC;                  // CC
		};
		static_assert(sizeof(EffectSettingData) == 0xD0);

		~EffectSetting() override;  // 00

		// members
		FilterValidationFunction_t* filterValidationFunction;  // 080
		void*                       filterValidationItem;      // 088
		EffectSettingData           data;                      // 090
		BSTArray<TESForm*>          unk160;                    // 160
		std::uint8_t                unk170[0x48];              // 170 - ESSH
		std::uint64_t               unk1B8;                    // 1B8
		std::uint64_t               unk1C0;                    // 1C0
		BGSLocalizedString          magicItemDescription;      // 1C8
		std::uint64_t               unk1D0;                    // 1D0
		TESCondition                conditions;                // 1D8
	};
	static_assert(sizeof(EffectSetting) == 0x1F0);
}
