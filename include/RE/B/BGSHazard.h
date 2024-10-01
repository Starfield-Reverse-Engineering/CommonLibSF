#pragma once

#include "RE/B/BGSPreloadable.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESImageSpaceModifiableForm.h"
#include "RE/T/TESModel.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class BGSImpactDataSet;
	class MagicItem;
	class TESObjectLIGH;

	struct BGSHazardData  // DATA
	{
	public:
		enum class BGSHazardFlags
		{
			kNone = 0,
			kPCOnly = 1 << 0,
			kInheritDuration = 1 << 1,
			kAlignToNormal = 1 << 2,
			kInheritRadius = 1 << 3,
			kDropToGround = 1 << 4,
			kTaperEffectivenessbyProximity = 1 << 5,
			kIncreasedGravity = 1 << 6,
			kReversedGravity = 1 << 7
		};

		BGSAudio::WwiseSoundHook sound;             // 00
		MagicItem*               spell;             // 30
		TESObjectLIGH*           light;             // 38
		BGSImpactDataSet*        impactDataSet;     // 40
		std::uint32_t            radius;            // 48
		std::uint32_t            lifetime;          // 4C
		std::uint32_t            imageSpaceRadius;  // 50
		float                    targetInterval;    // 54
		std::uint32_t            unk58;             // 58
		std::uint32_t            unk5C;             // 5C
		std::uint32_t            unk60;             // 60
		float                    unk64;             // 64
		float                    unk68;             // 68
		std::uint32_t            unk6C;             // 6C
	};
	static_assert(sizeof(BGSHazardData) == 0x70);

	class BGSHazard :
		public TESBoundObject,              // 000
		public TESFullName,                 // 0E0
		public TESModel,                    // 0F0
		public BGSPreloadable,              // 110
		public TESImageSpaceModifiableForm  // 118
	{
	public:
		SF_RTTI_VTABLE(BGSHazard);
		SF_FORMTYPE(HAZD);

		~BGSHazard() override;  // 00

		// members
		BGSHazardData data;        // 128
		TESCondition  conditions;  // 198
	};
	static_assert(sizeof(BGSHazard) == 0x1B0);
}
