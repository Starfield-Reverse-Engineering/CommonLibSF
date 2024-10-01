#pragma once

#include "RE/B/BGSReflectedForm.h"

namespace RE
{
	struct alignas(4) BGSVolumetricLightingSettings
	{
	public:
		struct alignas(4) ExteriorAndInteriorSettings
		{
			float scatteringVolumeNear;            // 00
			float scatteringVolumeFar;             // 04
			float highFrequencyNoiseScale;         // 08
			float highFrequencyNoiseDensityScale;  // 0C
		};
		static_assert(sizeof(ExteriorAndInteriorSettings) == 0x10);

		struct alignas(4) FogThicknessSettings
		{
			float thicknessNoiseScale;  // 00
			float thicknessNoiseBias;   // 04
			float minFogThickness;      // 08
			float maxFogThickness;      // 0C
		};
		static_assert(sizeof(FogThicknessSettings) == 0x10);

		struct alignas(4) FogDensitySettings
		{
			float densityNoiseScale;        // 00
			float densityNoiseBias;         // 04
			float minFogDensity;            // 08
			float maxFogDensity;            // 0C
			float densityStartDistance;     // 10
			float densityFullDistance;      // 14
			float densityDistanceExponent;  // 18
		};
		static_assert(sizeof(FogDensitySettings) == 0x1C);

		struct alignas(4) HorizonFogSettings
		{
			float fogThickness;        // 00
			float thicknessNoiseBias;  // 04
			float minFogThickness;     // 08
			float maxFogThickness;     // 0C
		};
		static_assert(sizeof(FogThicknessSettings) == 0x10);

		struct alignas(4) ExteriorSettings
		{
			FogThicknessSettings fogThickness;  // 00
			FogDensitySettings   fogDensity;    // 10
			float                unk2C;         // 2C
			float                unk30;         // 30
			float                unk34;         // 34
			float                unk38;         // 38
			float                unk3C;         // 3C
			float                unk40;         // 40
			float                unk44;         // 44
			float                unk48;         // 48
			float                unk4C;         // 4C
			float                unk50;         // 50
			float                unk54;         // 54
			float                unk58;         // 58
			float                unk5C;         // 5C
			float                unk60;         // 60
		};
		static_assert(sizeof(ExteriorSettings) == 0x64);

		struct alignas(4) DistantLightingSettings
		{
			float scatteringTransition;  // 00
			float scatteringFar;         // 04
		};
		static_assert(sizeof(DistantLightingSettings) == 0x08);

		// members
		ExteriorAndInteriorSettings exteriorAndInterior;  // 00
		ExteriorSettings            exterior;             // 10
		DistantLightingSettings     distantLighting;      // 74
	};
	static_assert(sizeof(BGSVolumetricLightingSettings) == 0x7C);

	class BGSVolumetricLighting : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSVolumetricLighting);
		SF_FORMTYPE(VOLI);

		~BGSVolumetricLighting() override;  // 00

		// members
		BGSVolumetricLightingSettings settings;  // 30
	};
	static_assert(sizeof(BGSVolumetricLighting) == 0xB8);
}
