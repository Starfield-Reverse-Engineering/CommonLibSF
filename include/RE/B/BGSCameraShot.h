#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESImageSpaceModifiableForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class BGSCameraShot :
		public TESForm,                     // 00
		public TESModel,                    // 30
		public BGSKeywordForm,              // 50
		public TESImageSpaceModifiableForm  // 80
	{
	public:
		SF_RTTI_VTABLE(BGSCameraShot);
		SF_FORMTYPE(CAMS);

		enum class CAM_ACTION
		{
			kShoot = 0,
			kFly = 1,
			kHit = 2,
			kZoom = 3
		};

		enum class CAM_OBJECT
		{
			kAttacker = 0,
			kProjectile = 1,
			kTarget = 2,
			kLeadActor = 3
		};

		struct CAMERA_SHOT_DATA  // DATA
		{
		public:
			enum class Flag
			{
				kNone = 0,
				kPositionFollowsLocation = 1 << 0,
				kRotationFollowsTarget = 1 << 1,
				kDontFollowBone = 1 << 2,
				kFirstPersonCamera = 1 << 3,
				kNoTracer = 1 << 4,
				kStartAtTimeZero = 1 << 5,
				kDontResetLocationSpring = 1 << 6,
				kDontResetTargetSpring = 1 << 7
			};

			// members
			stl::enumeration<CAM_ACTION, std::int32_t> cameraAction;                // 00
			stl::enumeration<CAM_OBJECT, std::int32_t> location;                    // 04
			stl::enumeration<CAM_OBJECT, std::int32_t> target;                      // 08
			std::uint32_t                              flags;                       // 0C
			float                                      playerTimeMult;              // 10
			float                                      targetTimeMult;              // 14
			float                                      globalTimeMult;              // 18
			float                                      maxTime;                     // 1C
			float                                      minTime;                     // 20
			float                                      targetPercentBetweenActors;  // 24
			float                                      nearTargetDistance;          // 28
			float                                      locationSpring;              // 2C
			float                                      targetSpring;                // 30
			float                                      rotationOffsetX;             // 34
			float                                      rotationOffsetY;             // 38
			float                                      rotationOffsetZ;             // 3C
		};
		static_assert(sizeof(CAMERA_SHOT_DATA) == 0x40);

		~BGSCameraShot() override;  // 00

		// members
		CAMERA_SHOT_DATA data;        // 90
		TESCondition     conditions;  // D0
		BSFixedString    animPath;    // E0
	};
	static_assert(sizeof(BGSCameraShot) == 0xE8);
}
