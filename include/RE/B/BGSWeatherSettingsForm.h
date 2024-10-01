#pragma once

#include "RE/B/BGSReflectedForm.h"
#include "RE/B/BSBlendable.h"
#include "RE/B/BSTArray.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class BGSArtObject;
	class BGSCloudForm;
	class BGSConditionForm;
	class BGSExplosion;
	class BGSForceData;
	class BGSLensFlare;
	class BGSKeyword;
	class BGSVolumetricLighting;
	class SpellItem;
	class TESImageSpace;

	class BGSWeatherSettingsForm : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSWeatherSettingsForm);
		SF_FORMTYPE(WTHS);

		struct WeatherChoiceSettings
		{
			std::uint32_t                     weight;       // 00
			BSTArray<BGSWeatherSettingsForm*> subWeathers;  // 08
		};
		static_assert(sizeof(WeatherChoiceSettings) == 0x18);

		struct alignas(4) ColorSettings
		{
			BSBlendable::ColorValue effectLighting;  // 00
			BSBlendable::ColorValue fogFar;          // 18
			BSBlendable::ColorValue fogFarHigh;      // 30
			BSBlendable::ColorValue fogNear;         // 48
			BSBlendable::ColorValue fogNearHigh;     // 60
			BSBlendable::ColorValue sun;             // 78
			BSBlendable::ColorValue sunGlare;        // 90
			BSBlendable::ColorValue sunlight;        // A8
			BSBlendable::ColorValue moonGlare;       // C0
			BSBlendable::ColorValue moonlight;       // D8
		};
		static_assert(sizeof(ColorSettings) == 0xF0);

		struct PrecipitationSettings
		{
			BSBlendable::FloatValue precipFadeIn;          // 00
			BSBlendable::FloatValue precipFadeOut;         // 0C
			BSBlendable::FloatValue thunderFadeIn;         // 18
			BSBlendable::FloatValue thunderFadeOut;        // 24
			BSBlendable::ColorValue lightingColor;         // 30
			BGSExplosion*           lightingExplosion;     // 48
			BSBlendable::FloatValue lightningDistanceMin;  // 50
			BSBlendable::FloatValue lightningDistanceMax;  // 5C
			BSBlendable::FloatValue lightningFOV;          // 68
		};
		static_assert(sizeof(PrecipitationSettings) == 0x78);

		struct MagicEffect
		{
			SpellItem* spell;      // 00
			float      threshold;  // 08
		};
		static_assert(sizeof(MagicEffect) == 0x10);

		struct WeatherSound
		{
			enum class SoundType
			{
				kDefault = 0,
				kPrecipitation,
				kWind,
				kThunder
			};

			BGSAudio::WwiseSoundHook            soundHook;  // 00
			REX::Enum<SoundType, std::uint32_t> type;       // 30
			float                               minDelay;   // 34
			float                               maxDelay;   // 38
		};
		static_assert(sizeof(WeatherSound) == 0x40);

		struct SoundEffectSettings
		{
			BGSArtObject*             visualEffect;           // 00
			BSBlendable::FloatValue   beginVisualEffect;      // 08
			BSBlendable::FloatValue   endVisualEffect;        // 14
			MagicEffect               lightningStrikeEffect;  // 20
			MagicEffect               weatherActivateEffect;  // 30
			std::vector<WeatherSound> sounds;                 // 40
		};
		static_assert(sizeof(SoundEffectSettings) == 0x58);

		struct SpellEffect
		{
			SpellItem*        transitionSpell;  // 00
			SpellItem*        mainSpell;        // 08
			BGSConditionForm* conditions;       // 10
		};
		static_assert(sizeof(SpellEffect) == 0x18);

		struct SpellSettings
		{
			float                    transitionThreshold;  // 00
			std::vector<SpellEffect> spellItems;           // 08
		};
		static_assert(sizeof(SpellSettings) == 0x20);

		struct alignas(4) FoliageSettings
		{
			float windStrengthVariationSpeed;  // 00
			float windStrengthVariationMin;    // 04
			float windStrengthVariationMax;    // 08
			float leafSecondaryMotionAmount;   // 0C
			float leafSecondaryMotionCutOff;   // 10
		};
		static_assert(sizeof(FoliageSettings) == 0x14);

		~BGSWeatherSettingsForm() override;  // 00

		// members
		BGSWeatherSettingsForm* parent;                           // 030
		BGSKeyword*             displayKeyword;                   // 038
		WeatherChoiceSettings   weatherChoice;                    // 040
		TESImageSpace*          imageSpace;                       // 058
		TESImageSpace*          imageSpaceNight;                  // 060
		BGSVolumetricLighting*  volumetricLighting;               // 068
		BGSCloudForm*           clouds;                           // 070
		ColorSettings           color;                            // 078
		BGSArtObject*           precipitationEffect;              // 168
		PrecipitationSettings   precipitation;                    // 170
		SoundEffectSettings     soundEffects;                     // 1E8
		BGSArtObject*           optionalPhotoModeEffect;          // 240
		SpellSettings           spellData;                        // 248
		BGSLensFlare*           lensFlare;                        // 268
		float                   lensFlareCloudOcclusionStrength;  // 270
		BGSForceData*           windForce;                        // 278
		FoliageSettings         foliage;                          // 280
		BSBlendable::FloatValue windDirectionRange;               // 294
		BSBlendable::FloatValue windTurbulence;                   // 2A0
		bool                    windDirectionOverrideEnabled;     // 2AC
		BSBlendable::FloatValue windDirectionOverrideValue;       // 2B0
		float                   transDelta;                       // 2BC
		BSBlendable::FloatValue volatilityMultiplier;             // 2C0
		BSBlendable::FloatValue visibilityMultiplier;             // 2CC
		BSTArray<BGSKeyword*>   keywords;                         // 2D8
		std::uint64_t           unk2E8;                           // 2E8
		std::uint64_t           unk2F0;                           // 2F0
	};
	static_assert(sizeof(BGSWeatherSettingsForm) == 0x300);
}
