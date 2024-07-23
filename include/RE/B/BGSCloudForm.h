#pragma once

#include "RE/B/BGSReflectedForm.h"

namespace RE
{
	class BGSEffectSequenceForm;

	class BGSCloudForm : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSCloudForm);
		SF_FORMTYPE(CLDF);

		struct ShadowParams
		{
		public:
			// members
			bool          enabled;         // 00
			BSFixedString opacityTexture;  // 08
			float         tilingPerKm;     // 10
			float         elevationKm;     // 14
			float         strength;        // 18
			float         windScale;       // 1C
		};
		static_assert(sizeof(ShadowParams) == 0x20);

		struct CloudLayer
		{
		public:
			// members
			BSFixedString    name;                   // 00
			BSFixedString    colorTexture;           // 08
			BSFixedString    thicknessTexture;       // 10
			BSFixedString    normalTexture;          // 18
			BSFixedString    opacityTexture;         // 20
			float            elevationKm;            // 28
			float            heightKm;               // 2C
			float            distanceKm;             // 30
			float            thickness;              // 34
			float            textureShadowOffset;    // 38
			float            textureShadowStrength;  // 3C
			float            normalShadowStrength;   // 40
			std::uint32_t    tiling;                 // 44
			std::uint32_t    verticalTiling;         // 48
			float            topBlendDistanceKm;     // 4C
			float            topBlendStartKm;        // 50
			float            bottomBlendDistanceKm;  // 54
			float            bottomBlendStartKm;     // 58
			float            windScale;              // 5C
			float            density;                // 60
			float            coverage;               // 64
			float            alphaAdd;               // 68
			float            alphaMultiply;          // 6C
			DirectX::XMCOLOR tint;                   // 70
			bool             enableEditorRendering;  // 74
		};
		static_assert(sizeof(CloudLayer) == 0x78);

		struct CloudPlane
		{
		public:
			// members
			BSFixedString    name;                   // 00
			BSFixedString    colorTexture;           // 08
			BSFixedString    thicknessTexture;       // 10
			BSFixedString    normalTexture;          // 18
			BSFixedString    opacityTexture;         // 20
			float            elevationKm;            // 28
			float            fadeStartKm;            // 2C
			float            fadeDistanceKm;         // 30
			float            thickness;              // 34
			float            textureShadowOffset;    // 38
			float            textureShadowStrength;  // 3C
			float            normalShadowStrength;   // 40
			float            tilingPerKm;            // 44
			float            windScale;              // 48
			float            density;                // 4C
			float            coverage;               // 50
			float            alphaAdd;               // 54
			float            alphaMultiply;          // 58
			DirectX::XMCOLOR tint;                   // 5C
			bool             enableEditorRendering;  // 60
		};
		static_assert(sizeof(CloudPlane) == 0x68);

		~BGSCloudForm() override;  // 00

		// members
		ShadowParams              shadows;            // 030
		std::array<CloudLayer, 4> layers;             // 050
		std::array<CloudPlane, 4> planes;             // 230
		BGSEffectSequenceForm*    cloudCardSequence;  // 3D0
	};
	static_assert(sizeof(BGSCloudForm) == 0x3D8);
}
