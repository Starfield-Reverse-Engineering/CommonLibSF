#pragma once

#include "RE/B/BGSReflectedForm.h"

namespace RE
{
	class BGSFogVolumeForm : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSFogVolumeForm);
		SF_FORMTYPE(FOGV);

		~BGSFogVolumeForm() override;  // 00

		// members
		DirectX::XMCOLOR  albedo;                  // 30
		float             meanFreePath;            // 34 - how far light can travel freely in meters [1, infinite]
		float             anisotropy;              // 38
		DirectX::XMFLOAT3 emittance;               // 3C
		float             edgeFalloffStart;        // 48
		float             edgeFalloffEnd;          // 4C
		float             noiseContribution;       // 50
		float             noiseScale;              // 54
		float             noiseBias;               // 58
		DirectX::XMFLOAT3 noiseScrollingVelocity;  // 5C
		std::uint32_t     pad68;                   // 68
	};
	static_assert(sizeof(BGSFogVolumeForm) == 0x70);
}
