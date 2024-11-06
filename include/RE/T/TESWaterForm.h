#pragma once

#include "RE/C/Color.h"
#include "RE/N/NiPoint.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class BGSCurve3DForm;
	class BGSMaterialType;
	class MagicItem;
	class SpellItem;
	class TESImageSpace;

	struct WaterShaderData
	{
	public:
		// members
		float         depthAmount;             // 00
		Color         shallowColor;            // 04
		Color         deepColor;               // 08
		float         shallowFogColorRange;    // 0C
		std::uint32_t unk10;                   // 10
		Color         underwaterFogColor;      // 14
		float         underwaterFogAmount;     // 18
		float         underwaterFogDistNear;   // 1C
		float         underwaterFogDistFar;    // 20
		float         normalMagnitude;         // 24
		float         normalFalloffShallow;    // 28
		float         normalFalloffDeep;       // 2C
		float         reflectionAmount;        // 30
		float         fresnelAmount;           // 34
		float         surfaceEffectFalloff;    // 38
		float         displacementForce;       // 3C
		float         displacementVelocity;    // 40
		float         windSpeedLayer2;         // 44
		float         windSpeedLayer3;         // 48
		float         displacementFalloff;     // 4C
		float         displacementDampener;    // 50
		float         displacementSize;        // 54
		Color         reflectionColor;         // 58
		float         sunSpecularPower;        // 5C
		float         sunSpecularMagnitude;    // 60
		float         sunSparklePower;         // 64
		float         sunSparkleMagnitude;     // 68
		float         lightRadius;             // 6C
		float         lightBrightness;         // 70
		float         shininess;               // 74
		float         noiseWindDirections[3];  // 78
		float         windSpeedLayer1;         // 84
		float         deepFogColorRange;       // 88
		float         shallowAlpha;            // 8C
		float         deepAlpha;               // 90
		float         shallowFogAlphaRange;    // 94
	};
	static_assert(sizeof(WaterShaderData) == 0x98);

	class TESWaterForm :
		public TESForm,     // 00
		public TESFullName  // 30
	{
	public:
		SF_RTTI_VTABLE(TESWaterForm);
		SF_FORMTYPE(WATR);

		~TESWaterForm() override;  // 00

		// members
		bool                     needUpdate;              // 040
		float                    unk044;                  // 044
		float                    unk048;                  // 048
		float                    unk04C;                  // 04C
		float                    unk050;                  // 05C
		float                    unk054;                  // 054
		float                    unk058;                  // 058
		float                    unk05C;                  // 05C
		float                    unk060;                  // 060
		float                    unk064;                  // 064
		float                    unk068;                  // 068
		float                    unk06C;                  // 06C
		float                    unk070;                  // 070
		std::uint8_t             alpha;                   // 074
		std::uint8_t             flags;                   // 075
		BGSMaterialType*         materialType;            // 078
		BGSAudio::WwiseSoundHook sound;                   // 080
		WaterShaderData          data;                    // 0B0
		std::uint32_t            unk148;                  // 148
		std::uint32_t            unk14C;                  // 14C
		TESWaterForm*            waterWeatherControl[3];  // 150
		MagicItem*               consumeSpell;            // 168
		SpellItem*               contactSpell;            // 170
		BGSCurve3DForm*          riverAbsorptionCurve;    // 178
		BGSCurve3DForm*          oceanAbsorptionCurve;    // 180
		BGSCurve3DForm*          riverScatteringCurve;    // 188
		BGSCurve3DForm*          oceanScatteringCurve;    // 190
		BGSCurve3DForm*          phytoplanktonCurve;      // 198
		BGSCurve3DForm*          sedimentCurve;           // 1A0
		BGSCurve3DForm*          yellowMatterCurve;       // 1A8
		void*                    unk1B0;                  // 1B0 - smart ptr
		std::uint64_t            unk1B8;                  // 1B8
		bool                     resetNoiseTextures;      // 1C0
		TESImageSpace*           imageSpace;              // 1C8
		NiPoint3                 linearVelocity;          // 1D0
		NiPoint3                 angularVelocity;         // 1DC
	};
	static_assert(sizeof(TESWaterForm) == 0x1F0);
	static_assert(offsetof(TESWaterForm, data) == 0xB8);
}
