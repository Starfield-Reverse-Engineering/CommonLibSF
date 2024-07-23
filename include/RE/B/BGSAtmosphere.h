#pragma once

#include "RE/B/BGSReflectedForm.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSResource;
	class TESClimate;
	class TESImageSpace;

	namespace BSGalaxy
	{
		class BGSSunPresetForm;
	}

	class BGSAtmosphere : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSAtmosphere);
		SF_FORMTYPE(ATMO);

		enum class ATMOSPHERE_TYPE
		{
			kNone = 0,
			kNitrogen,
			kMethane,
			kCarbonDioxide,
			kOxygen,
			kLowOxygen,
			kHighOxygen
		};

		struct alignas(4) ScatteringSettings
		{
		public:
			struct alignas(4) RayleighSettings
			{
				float             moleculesPerUnitVolume;           // 00
				float             refractiveIndexOfAir;             // 04
				float             depolarizationFactor;             // 08
				bool              useOzoneAbsorptionApproximation;  // 0C
				DirectX::XMFLOAT4 ozoneAbsorptionCoef;              // 10
				DirectX::XMFLOAT4 rayleighCoef;                     // 20
			};
			static_assert(sizeof(RayleighSettings) == 0x30);

			struct alignas(4) MieSettings
			{
				float             aerosolDensity;     // 00
				float             aerosolAbsorbtion;  // 04
				DirectX::XMFLOAT4 mieCoef;            // 08
			};
			static_assert(sizeof(MieSettings) == 0x18);

			// members
			std::uint32_t    height;                 // 00
			bool             useCustomCoefficients;  // 04
			RayleighSettings rayleigh;               // 08
			MieSettings      mie;                    // 38
			float            aerosolPhaseFunction;   // 50
			float            scatteringScale;        // 54
			float            edgeEffectExponent;     // 58
			float            edgeEffectCoefficient;  // 5C
		};
		static_assert(sizeof(ScatteringSettings) == 0x60);

		struct alignas(4) StarSettings
		{
			float planetStarfieldBackgroundScale;           // 00
			float planetStarfieldBackgroundGIContribution;  // 04
			float planetStarfieldStarBrightnessScale;       // 08
			float planetStarGlowBackgroundScale;            // 0C
			float horizonScatteringBlendScale;              // 10
			bool  disableSimulatedVisibility;               // 14
			float staticVisibility;                         // 18
		};
		static_assert(sizeof(StarSettings) == 0x1C);

		struct alignas(4) CelestialBodySettings
		{
			float celestialBodyIlluminanceScale;  // 0
		};
		static_assert(sizeof(CelestialBodySettings) == 0x4);

		struct OverrideSettings
		{
			BSGalaxy::BGSSunPresetForm* sunPresetOverride;  // 00
		};
		static_assert(sizeof(OverrideSettings) == 0x8);

		struct MiscSettings
		{
			stl::enumeration<ATMOSPHERE_TYPE, std::uint32_t> atmosphereType;      // 00
			BSTArray<BGSResource*>                           inorganicResources;  // 08
			TESImageSpace*                                   imageSpaceDay;       // 18
			TESImageSpace*                                   imageSpaceNight;     // 20
			TESClimate*                                      climateOverride;     // 28
		};
		static_assert(sizeof(MiscSettings) == 0x30);

		struct AtmosphereSettings
		{
		public:
			// members
			BGSAtmosphere*        parent;           // 00
			ScatteringSettings    scattering;       // 08
			StarSettings          stars;            // 68
			CelestialBodySettings celestialBodies;  // 84
			OverrideSettings      overrides;        // 88
			MiscSettings          misc;             // 90
		};
		static_assert(sizeof(AtmosphereSettings) == 0xC0);

		~BGSAtmosphere() override;  // 00

		// members
		AtmosphereSettings settings;  // 030
		BSTArray<void*>    unk0F0;    // 0F0 - incomplete reflection?
		std::uint64_t      unk100;    // 100
		std::uint32_t      unk108;    // 108
		std::uint32_t      unk10C;    // 10C
		std::uint32_t      unk110;    // 110
		std::uint32_t      unk114;    // 114
		std::uint32_t      unk118;    // 118
		std::uint32_t      unk11C;    // 11C
		std::uint32_t      unk120;    // 120
		std::uint32_t      unk124;    // 124
		std::uint32_t      unk128;    // 128
		std::uint32_t      unk12C;    // 12C
		std::uint32_t      unk130;    // 130
		std::uint32_t      unk134;    // 134
		std::uint32_t      unk138;    // 138
		std::uint32_t      unk13C;    // 13C
		std::uint32_t      unk140;    // 140
		std::uint32_t      unk144;    // 144
		std::uint32_t      unk148;    // 148
	};
	static_assert(sizeof(BGSAtmosphere) == 0x150);
}
