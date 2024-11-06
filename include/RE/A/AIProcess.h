#pragma once

#include "RE/A/ActorPackage.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTList.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class ActorKnowledge;
	class bhkCharacterController;
	class DialogueItem;
	class MagicItem;
	class ObjectsToAcquire;
	class TESBoundObject;
	class TESIdleForm;
	class TESObjectREFR;
	class TESObjectWEAP;

	enum class COMMAND_TYPE : std::int32_t
	{
		kNone = 0,
		kCall = 1,
		kFollow = 2,
		kMove = 3,
		kAttack = 4,
		kInspect = 5,
		kRetrieve = 6,
		kStay = 7,
		kRelease = 8,
		kHeal = 9,
		kAssign = 10,
		kRide = 11,
		kEnter = 12,
	};

	struct HighProcessData
	{
		enum class FADE_STATE : std::int32_t
		{
			kNormal = 0,
			kIn = 1,
			kOut = 2,
			kTeleportIn = 3,
			kTeleportOut = 4,
			kOutDisable = 5,
			kOutDelete = 6
		};

		// members
		std::byte                      pad000[0x13C];           // 000
		FADE_STATE                     fadeState;               // 13C
		std::byte                      pad140[0x1B8];           // 140
		BSFixedStringCS                strVoiceSubtitle;        // 2F8
		std::byte                      pad300[0x14];            // 300
		BSReadWriteLock                knowledgeLock;           // 314
		std::byte                      pad31C[0x2E];            // 31C
		NiPoint3                       deathForceDirection;     // 34C
		float                          deathForce;              // 358
		std::byte                      pad35C[0x28];            // 35C
		float                          packageEvalTimer;        // 384
		float                          useItemTimer;            // 388
		float                          procedureEvalTimer;      // 38C
		std::byte                      pad390[0x40];            // 390
		float                          greetingTimer;           // 3D0
		std::byte                      pad3D4[0x4];             // 3D4
		float                          idleTimer;               // 3D8
		std::byte                      pad3DC[0x2C];            // 3DC
		TESIdleForm*                   idleToPlay;              // 408
		std::byte                      pad410[0x8];             // 410
		TESPackage*                    commandPackage;          // 418
		std::byte                      pad420[0x18];            // 420
		BSPointerHandle<TESObjectREFR> idleTarget;              // 438
		std::byte                      pad43C[0x4];             // 43C
		DialogueItem*                  greetTopic;              // 440
		std::byte                      pad448[0x30];            // 448
		float                          lightLevel;              // 478
		std::byte                      pad47C[0x84];            // 47C
		float                          tryTalkIdleTimer;        // 500
		std::uint16_t                  tryTalk;                 // 504
		std::byte                      pad506[0xA];             // 506
		COMMAND_TYPE                   commandType;             // 510
		std::byte                      pad514[0x47];            // 514
		bool                           greetingFlag;            // 55B
		bool                           pickNewIdle;             // 55C
		bool                           skipVoiceEndIdleStop;    // 55D
		bool                           weaponAlertDrawn;        // 55E
		bool                           dialoguewithPlayer;      // 55F
		bool                           inCommandState;          // 560
		bool                           inWorkshopCommandState;  // 561
		bool                           continuingPackageForPC;  // 562
		bool                           activateAnim;            // 563
		bool                           stop;                    // 564
		std::byte                      pad562[0x18];            // 562
		bool                           playerActivated;         // 57D
		bool                           itemEquipQueued;         // 57E
		bool                           doingCommand;            // 57F
		bool                           capLineFired;            // 580
		std::byte                      pad581[0x2];             // 581
		bool                           processingForceEquip;    // 583
		bool                           capLinePlaying;          // 584
	};
	static_assert(offsetof(HighProcessData, fadeState) == 0x13C);
	static_assert(offsetof(HighProcessData, strVoiceSubtitle) == 0x2F8);
	static_assert(offsetof(HighProcessData, knowledgeLock) == 0x314);
	static_assert(offsetof(HighProcessData, deathForceDirection) == 0x34C);
	static_assert(offsetof(HighProcessData, packageEvalTimer) == 0x384);
	static_assert(offsetof(HighProcessData, idleTimer) == 0x3D8);
	static_assert(offsetof(HighProcessData, idleToPlay) == 0x408);
	static_assert(offsetof(HighProcessData, greetTopic) == 0x440);
	static_assert(offsetof(HighProcessData, lightLevel) == 0x478);
	static_assert(offsetof(HighProcessData, tryTalkIdleTimer) == 0x500);
	static_assert(offsetof(HighProcessData, commandType) == 0x510);
	static_assert(offsetof(HighProcessData, pickNewIdle) == 0x55C);
	static_assert(offsetof(HighProcessData, inCommandState) == 0x560);
	static_assert(offsetof(HighProcessData, stop) == 0x564);
	static_assert(offsetof(HighProcessData, playerActivated) == 0x57D);
	static_assert(offsetof(HighProcessData, capLineFired) == 0x580);
	static_assert(offsetof(HighProcessData, capLinePlaying) == 0x584);

	struct MiddleLowProcessData
	{
		// members
		std::int32_t hourPackageEvaluated;  // 00
	};

	struct MiddleHighProcessData
	{
		// members
		std::byte                         pad000[0x38];                       // 000
		ActorPackage                      runOncePackage;                     // 038
		std::byte                         pad068[0x200];                      // 068
		BSReadWriteLock                   equippedItemsLock;                  // 268
		std::byte                         pad270[0x1B4];                      // 270
		BSPointerHandle<TESObjectREFR>    currentFurniture;                   // 424
		BSPointerHandle<TESObjectREFR>    occupiedFurniture;                  // 428
		std::byte                         pad42C[0x1C];                       // 42C
		MagicItem*                        currentPackageSpell;                // 448
		TESObjectWEAP*                    lastBoundWeapon;                    // 450
		NiPointer<bhkCharacterController> charController;                     // 458
		std::byte                         pad460[0xA8];                       // 460
		std::uint32_t                     deferredKill;                       // 508
		std::byte                         pad50C[0x74];                       // 50C
		std::int16_t                      animActionSuccess;                  // 580
		std::byte                         pad582[0x7];                        // 582
		bool                              aimingTarget;                       // 589
		bool                              doneClothesChange;                  // 58A
		std::byte                         pad58B[0x6];                        // 58B
		bool                              playedBeginIdles;                   // 591
		std::byte                         pad592[0x7];                        // 592
		bool                              eating;                             // 599
		bool                              calcLight;                          // 59A
		std::byte                         pad59B[0x6];                        // 59B
		bool                              killQueued;                         // 5A1
		bool                              ragdollInstant;                     // 5A2
		bool                              scriptDeferredKill;                 // 5A3
		bool                              furnitureEntryLeftFootFirst;        // 5A4
		bool                              furnitureAnimationPlayed;           // 5A5
		bool                              queuedInstantInteractionAnimation;  // 5A6
		bool                              queuedModifyInitialAnimationPose;   // 5A7
		bool                              avoidPlayer;                        // 5A8
	};
	static_assert(offsetof(MiddleHighProcessData, runOncePackage) == 0x38);
	static_assert(offsetof(MiddleHighProcessData, equippedItemsLock) == 0x268);
	static_assert(offsetof(MiddleHighProcessData, currentFurniture) == 0x424);
	static_assert(offsetof(MiddleHighProcessData, occupiedFurniture) == 0x428);
	static_assert(offsetof(MiddleHighProcessData, currentPackageSpell) == 0x448);
	static_assert(offsetof(MiddleHighProcessData, charController) == 0x458);
	static_assert(offsetof(MiddleHighProcessData, deferredKill) == 0x508);
	static_assert(offsetof(MiddleHighProcessData, animActionSuccess) == 0x580);
	static_assert(offsetof(MiddleHighProcessData, doneClothesChange) == 0x58A);
	static_assert(offsetof(MiddleHighProcessData, playedBeginIdles) == 0x591);
	static_assert(offsetof(MiddleHighProcessData, calcLight) == 0x59A);
	static_assert(offsetof(MiddleHighProcessData, killQueued) == 0x5A1);
	static_assert(offsetof(MiddleHighProcessData, avoidPlayer) == 0x5A8);

	class AIProcess
	{
	public:
		float GetActorLightLevel() const
		{
			return high ? high->lightLevel : 0.0f;
		}

		ActorPackage* GetActorPackage()
		{
			return std::addressof(currentPackage);
		}

		ActorPackage* GetActorPackageRunning()
		{
			if (middleHigh && middleHigh->runOncePackage.package)
				return std::addressof(middleHigh->runOncePackage);

			return std::addressof(currentPackage);
		}

		bool GetCommandState() const
		{
			return high && high->inCommandState;
		}

		bool GetCommandWorkshopState() const
		{
			return high && high->inWorkshopCommandState;
		}

		COMMAND_TYPE GetCommandType() const
		{
			return high ? high->commandType : COMMAND_TYPE::kNone;
		}

		bool IsPlayingPCap() const
		{
			return high && high->capLinePlaying;
		}

		bool IsRunningRunOnce() const
		{
			return middleHigh && middleHigh->runOncePackage.package;
		}

		// members
		MiddleLowProcessData*           middleLow;             // 00
		MiddleHighProcessData*          middleHigh;            // 08
		HighProcessData*                high;                  // 10
		ActorPackage                    currentPackage;        // 18
		float                           hourLastProcessed;     // 48
		float                           timeAdjustmentsMade;   // 4C
		std::uint64_t                   unk50;                 // 50
		std::uint64_t                   unk58;                 // 58
		std::uint64_t                   unk60;                 // 60
		BSSimpleList<ObjectsToAcquire*> objectList;            // 68
		BSSimpleList<TESObjectREFR*>    genericLocationsList;  // 78
		ObjectsToAcquire*               acquireObject;         // 88
		ObjectsToAcquire*               savedAcquireObject;    // 90
		std::uint64_t                   unk98;                 // 98
		std::uint64_t                   unkA0;                 // A0
		std::uint64_t                   unkA8;                 // A8
		std::uint64_t                   unkB0;                 // B0
		TESBoundObject*                 itemBeingUsed;         // B8
		BSPointerHandle<TESObjectREFR>  followTarget;          // C0
		BSPointerHandle<TESObjectREFR>  target;                // C4
		std::uint64_t                   unkC8;                 // C8
		std::uint64_t                   unkD0;                 // D0
		std::uint64_t                   unkD8;                 // D8
		std::byte                       unkE0[0x6];            // E0
		std::uint8_t                    lowProcessFlags;       // E6
		std::uint8_t                    unkE7;                 // E7
		std::byte                       padE8[0x3];            // E8
		bool                            ignoringCombat;        // EB
		std::byte                       padEC[0x5];            // EC
		bool                            escortingPlayer;       // F1
		std::byte                       padF2[0x6];            // F2
	};
	static_assert(sizeof(AIProcess) == 0xF8);
	static_assert(offsetof(AIProcess, objectList) == 0x68);
	static_assert(offsetof(AIProcess, acquireObject) == 0x88);
	static_assert(offsetof(AIProcess, lowProcessFlags) == 0xE6);
	static_assert(offsetof(AIProcess, ignoringCombat) == 0xEB);
	static_assert(offsetof(AIProcess, escortingPlayer) == 0xF1);
}
