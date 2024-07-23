#pragma once

#include "RE/B/BSFixedString.h"

namespace RE::BGSBodyPartDefs
{
	struct LIMB_CATEGORIES
	{
		enum LIMB_CATEGORY
		{
			kNone = static_cast<std::underlying_type_t<LIMB_CATEGORY>>(-1),
			kTorso = 0,
			kBegin,
			kHead,
			kArm,
			kLeg,

			kTotal
		};
	};
	using LIMB_CATEGORY = LIMB_CATEGORIES::LIMB_CATEGORY;

	struct LIMB_ENUMS
	{
		enum LIMB_ENUM
		{
			kNone = static_cast<std::underlying_type_t<LIMB_ENUM>>(-1),
			kTorso = 0,
			kHead1,
			kEye1,
			kLookAt1,
			kFlyGrab,
			kHead2,
			kLeftArm1,
			kLeftArm2,
			kRightArm1,
			kRightArm2,
			kLeftLeg1,
			kLeftLeg2,
			kLeftLeg3,
			kRightLeg1,
			kRightLeg2,
			kRightLeg3,
			kBrain,
			kWeapon,
			kRoot,
			kCom,
			kPelvis,
			kCamera,
			kOffsetRoot,
			kLeftFoot,
			kRightFoot,
			kFaceTargetSource,

			kTotal
		};
	};
	using LIMB_ENUM = LIMB_ENUMS::LIMB_ENUM;

	struct HitReactionData
	{
	public:
		// members
		BSFixedString chainStart;  // 00
		BSFixedString chainEnd;    // 08
		BSFixedString variableX;   // 10
		BSFixedString variableY;   // 18
		BSFixedString variableZ;   // 20
	};
	static_assert(sizeof(HitReactionData) == 0x28);
}
