#pragma once

#include "RE/B/BGSReflectedForm.h"

namespace RE
{
	class BGSCurveForm;

	namespace BSForces
	{
		enum class TYPE
		{
			kDirectional,
			kPoint
		};

		enum class CHANNEL
		{
			kGravity,
			kWind
		};
	}

	class BGSForceData : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSForceData);
		SF_FORMTYPE(FORC);

		~BGSForceData() override;  // 00

		// members
		stl::enumeration<BSForces::TYPE, std::uint32_t>    forceType;                     // 30
		stl::enumeration<BSForces::CHANNEL, std::uint32_t> forceChannel;                  // 34
		float                                              horizontalAngle;               // 38
		float                                              verticalAngle;                 // 3C
		float                                              speed;                         // 40
		float                                              strength;                      // 44
		DirectX::XMFLOAT3                                  vector;                        // 48
		BGSCurveForm*                                      falloffCurve;                  // 58
		float                                              turbulenceSpeedAmplitude;      // 60
		float                                              turbulenceSpeedFrequency;      // 64
		float                                              turbulenceDirectionAmplitude;  // 68
		float                                              turbulenceDirectionFrequency;  // 6C
	};
	static_assert(sizeof(BGSForceData) == 0x70);
}
