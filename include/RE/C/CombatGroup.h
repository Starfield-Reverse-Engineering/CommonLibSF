#pragma once

namespace RE
{
	class CombatGroup
	{
	public:
		/*
		// members
		std::uint32_t                  groupID;                      // 000
		std::uint32_t                  groupIndex;                   // 004
		BSTArray<CombatTarget>         targets;                      // 008
		BSTArray<CombatMember>         members;                      // 020
		CombatGroupDetectionListener*  detectionListener;            // 038
		AITimer                        allyKilledTimer;              // 040
		AITimer                        avoidThreathTimer;            // 048
		AITimer                        unk50;                        // 050
		AITimer                        detectionDialogueTimers[11];  // 058
		AITimer                        updateTimer;                  // 0B0
		AITimer                        musicThreatRatioTimer;        // 0B8
		AITimer                        unkC0;                        // 0C0
		float                          unkC8;                        // 0C8
		float                          unkCC;                        // 0CC
		float                          unkD0;                        // 0D0
		float                          unkD4;                        // 0D4
		std::uint32_t                  searchState;                  // 0D8
		std::uint32_t                  padDC;                        // 0DC
		BSPathingLOSGridMap*           gridMap;                      // 0E0
		AITimer                        searchUpdateTimer;            // 0E8
		AITimer                        searchAreaUpdateTimer;        // 0F0
		AITimeStamp                    unkF8;                        // 0F8
		BSPointerHandle<Actor>         targetToSearchFor;            // 0FC
		BGSWorldLocation               searchTargetLoc;              // 100
		float                          searchRadius;                 // 118
		std::uint32_t                  unk11C;                       // 11C
		BSTArray<CombatSearchLocation> searchLocations;              // 120
		BSTArray<CombatSearchDoor>     searchDoors;                  // 138
		std::uint32_t                  unk150;                       // 150 - count
		std::uint32_t                  fleeCount;                    // 154
		std::uint32_t                  fightCount;                   // 158
		std::uint8_t                   musicState;                   // 15C
		std::uint8_t                   unk15D;                       // 15D
		std::uint8_t                   unk15E;                       // 15E
		std::uint8_t                   unk15F;                       // 15F
		mutable BSReadWriteLock        lock;                         // 160
		*/
	};
	//static_assert(sizeof(CombatGroup) == 0x168);
}
