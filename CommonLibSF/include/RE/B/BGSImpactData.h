#pragma once

#include "RE/B/BSTArray.h"
#include "RE/D/DecalData.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	enum class ImpactResult;

	class BGSExplosion;
	class BGSHazard;
	class BGSProjectedDecal;

	class BGSImpactData :
		public TESForm,  // 00
		public TESModel  // 30
	{
	public:
		SF_RTTI_VTABLE(BGSImpactData);
		SF_FORMTYPE(IPCT);

		enum class ORIENTATION
		{
			kSurfaceNormal = 0,
			kProjVector = 1,
			kProjReflect = 2
		};

		struct IMPACT_DATA_DATA  // DATA
		{
			enum class Flag
			{
				kNone = 0,
				kNoDecalData = 1 << 0
			};

			float                                        effectDuration;   // 00
			stl::enumeration<ORIENTATION, std::uint32_t> orient;           // 04
			float                                        angleThreshold;   // 08
			float                                        placementRadius;  // 0C
			std::uint32_t                                soundLevel;       // 10
			stl::enumeration<Flag, std::uint8_t>         flags;            // 14
			stl::enumeration<ImpactResult, std::uint8_t> resultOverride;   // 15
		};
		static_assert(sizeof(IMPACT_DATA_DATA) == 0x18);

		~BGSImpactData() override;  // 00

		// members
		IMPACT_DATA_DATA             data;                     // 050
		DecalData                    decalData;                // 068
		BSTArray<BGSProjectedDecal*> projectedDecals1;         // 080
		BSTArray<BGSProjectedDecal*> projectedDecals2;         // 090
		BGSAudio::WwiseSoundHook     sound1;                   // 0A0
		BGSAudio::WwiseSoundHook     sound2;                   // 0D0
		BGSAudio::WwiseSoundHook     sound3;                   // 100
		BGSExplosion*                explosion;                // 130
		BGSHazard*                   hazard;                   // 138
		float                        maxFootstepParticleDist;  // 140
		std::uint32_t                unk144;                   // 144
	};
	static_assert(sizeof(BGSImpactData) == 0x148);
}
