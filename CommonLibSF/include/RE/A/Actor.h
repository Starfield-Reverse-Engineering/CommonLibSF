#pragma once

#include "RE/A/AIProcess.h"
#include "RE/A/ActorState.h"
#include "RE/A/ActorValueStorage.h"
#include "RE/I/IMovementStateStore.h"
#include "RE/I/IStoreAnimationActions.h"
#include "RE/M/MagicTarget.h"
#include "RE/P/PerkRankData.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	class AIProcess;
	class BGSPerk;
	class CombatController;
	class CombatGroup;
	class MovementMessageUpdateRequestImmediate;
	class TESFaction;
	class TESRace;

	struct ActorCPMEvent;
	struct ActorSprintEvent;
	struct bhkCharacterMoveFinishEvent;
	struct bhkCharacterStateChangeEvent;
	struct bhkNonSupportContactEvent;
	struct BSMovementDataChangedEvent;
	struct BSNavmeshChangeEvent;
	struct BSSubGraphActivationUpdate;

	namespace PerkValueEvents
	{
		struct PerkValueChangedEvent;
		struct PerkEntryUpdatedEvent;
	}

	enum class ACTOR_CRITICAL_STAGE
	{
		kNone = 0,
		kGooStart = 1,
		kGooEnd = 2,
		kDisintegrateStart = 3,
		kDisintegrateEnd = 4,
		kFreezeStart = 5,
		kFreezeEnd = 6,

		kTotal
	};

	struct Perks
	{
	public:
		// members
		BSTArray<PerkRankData>* perkRanks;  // 00
		BSTArray<void*>         unk10;      // 08
	};
	static_assert(sizeof(Perks) == 0x18);

	class Actor :
		public TESObjectREFR,                                           // 000
		public MagicTarget,                                             // 110
		public ActorState,                                              // 128
		public IMovementStateStore,                                     // 138
		public IStoreAnimationActions,                                  // 140
		public BSTEventSink<BSNavmeshChangeEvent>,                      // 148
		public BSTEventSink<BSMovementDataChangedEvent>,                // 150
		public BSTEventSink<BSSubGraphActivationUpdate>,                // 158
		public BSTEventSink<bhkCharacterMoveFinishEvent>,               // 160
		public BSTEventSink<bhkNonSupportContactEvent>,                 // 168
		public BSTEventSink<bhkCharacterStateChangeEvent>,              // 170
		public BSTEventSource<MovementMessageUpdateRequestImmediate>,   // 178
		public BSTEventSource<PerkValueEvents::PerkValueChangedEvent>,  // 1A0
		public BSTEventSource<PerkValueEvents::PerkEntryUpdatedEvent>,  // 1C8
		public BSTEventSource<ActorCPMEvent>,                           // 1F0
		public BSTEventSource<ActorSprintEvent>                         // 218
	{
	public:
		SF_RTTI_VTABLE(Actor);
		SF_FORMTYPE(ACHR);

		enum class BOOL_BITS
		{
			kNone = 0,
			kDelayUpdateScenegraph = 1 << 0,
			kProcessMe = 1 << 1,
			kMurderAlarm = 1 << 2,
			kHasSceneExtra = 1 << 3,
			kHeadingFixed = 1 << 4,
			kSpeakingDone = 1 << 5,
			kIgnoreChangeAnimationCall = 1 << 6,
			kSoundFileDone = 1 << 7,
			kVoiceFileDone = 1 << 8,
			kInTempChangeList = 1 << 9,
			kDoNotRunSayToCallback = 1 << 10,
			kDead = 1 << 11,
			kForceGreetingPlayer = 1 << 12,
			kForceUpdateQuestTarget = 1 << 13,
			kSearchingInCombat = 1 << 14,
			kAttackOnNextTheft = 1 << 15,
			kEvpBuffered = 1 << 16,
			kResetAI = 1 << 17,
			kInWater = 1 << 18,
			kSwimming = 1 << 19,
			kVoicePausedByScript = 1 << 20,
			kWasInFrustrum = 1 << 21,
			kShouldRotateToTrack = 1 << 22,
			kSetOnDeath = 1 << 23,
			kDoNotPadVoice = 1 << 24,
			kFootIKInRange = 1 << 25,
			kPlayerTeammate = 1 << 26,
			kGivePlayerXP = 1 << 27,
			kSoundCallbackSuccess = 1 << 28,
			kUseEmotion = 1 << 29,
			kGuard = 1 << 30,
			kParalyzed = 1 << 31
		};

		enum class BOOL_FLAGS
		{
			kNone = 0,
			kScenePackage = 1 << 0,
			kIsAMount = 1 << 1,
			kIsMountPointClear = 1 << 2,
			kIsGettingOnOffMount = 1 << 3,
			kInRandomScene = 1 << 4,
			kNoBleedoutRecovery = 1 << 5,
			kInBleedoutAnimation = 1 << 6,
			kCanDoFavor = 1 << 7,
			kShouldAnimGraphUpdate = 1 << 8,
			kCanSpeakToEssentialDown = 1 << 9,
			kBribedByPlayer = 1 << 10,
			kAngryWithPlayer = 1 << 11,
			kIsTresspassing = 1 << 12,
			kCanSpeak = 1 << 13,
			kIsInKillMove = 1 << 14,
			kAttackOnSight = 1 << 15,
			kIsCommandedActor = 1 << 16,
			kForceOneAnimGraphUpdate = 1 << 17,
			kEssential = 1 << 18,
			kProtected = 1 << 19,
			kAttackingDisabled = 1 << 20,
			kCastingDisabled = 1 << 21,
			kSceneHeadtrackRotation = 1 << 22,
			kForceIncMinBoneUpdate = 1 << 23,
			kCrimeSearch = 1 << 24,
			kMovingIntoLoadedArea = 1 << 25,
			kDoNotShowOnStealthMeter = 1 << 26,
			kMovementBlocked = 1 << 27,
			kAllowInstantFurniturePopInPlayerCell = 1 << 28,
			kForceAnimGraphUpdate = 1 << 29,
			kCheckAddEffectDualCast = 1 << 30,
			kUnderwater = 1 << 31,
		};

		enum class BOOL_FLAGS2
		{
			kNone = 0,
			kHasChargenSkeleton = 1 << 5,
		};

		~Actor() override;  // 00

		// add
		virtual void         PlayPickUpSound(TESBoundObject* a_boundObj, bool a_pickUp, bool a_use);                 // 130
		virtual void         Unk_131();                                                                              // 131
		virtual void         Unk_132();                                                                              // 132
		virtual void         Unk_133();                                                                              // 133
		virtual void         Unk_134();                                                                              // 134
		virtual void         Unk_135();                                                                              // 135
		virtual void         Unk_136();                                                                              // 136
		virtual void         Unk_137();                                                                              // 137
		virtual void         Unk_138();                                                                              // 138
		virtual void         Unk_139();                                                                              // 139
		virtual void         Unk_13A();                                                                              // 13A
		virtual void         Unk_13B();                                                                              // 13B
		virtual void         Unk_13C();                                                                              // 13C
		virtual void         Unk_13D();                                                                              // 13D
		virtual void         Unk_13E();                                                                              // 13E
		virtual void         Update(float a_delta);                                                                  // 13F
		virtual void         Unk_140();                                                                              // 140
		virtual void         Unk_141();                                                                              // 141
		virtual void         Unk_142();                                                                              // 142
		virtual void         Unk_143();                                                                              // 143
		virtual void         Unk_144();                                                                              // 144
		virtual void         Unk_145();                                                                              // 145
		virtual void         Unk_146();                                                                              // 146
		virtual void         Unk_147();                                                                              // 147
		virtual void         Unk_148();                                                                              // 148
		virtual void         GoToPrison(TESFaction* a_faction, bool a_removeInventory, bool a_realJail);             // 149
		virtual void         ServePrisonTime();                                                                      // 14A
		virtual void         PayFine(TESFaction* a_faction, bool a_goToJail, bool a_removeStolenItems);              // 14B
		virtual void         Unk_14C();                                                                              // 14C
		virtual void         Unk_14D();                                                                              // 14D
		virtual void         Unk_14E();                                                                              // 14E
		virtual void         Unk_14F();                                                                              // 14F
		virtual void         Unk_150();                                                                              // 150
		virtual void         Unk_151();                                                                              // 151
		virtual void         Unk_152();                                                                              // 152
		virtual void         Unk_153();                                                                              // 153
		virtual void         Unk_154();                                                                              // 154
		virtual void         Unk_155();                                                                              // 155
		virtual void         Unk_156();                                                                              // 156
		virtual void         Unk_157();                                                                              // 157
		virtual void         Unk_158();                                                                              // 158
		virtual void         Unk_159();                                                                              // 159
		virtual void         Unk_15A();                                                                              // 15A
		virtual void         PickUpObject(TESObjectREFR* a_objREFR, std::int32_t a_count, bool a_playPickUpSounds);  // 15B
		virtual void         Unk_15C();                                                                              // 15C
		virtual void         Unk_15D();                                                                              // 15D
		virtual void         Unk_15E();                                                                              // 15E
		virtual void         Unk_15F();                                                                              // 15F
		virtual CombatGroup* GetCombatGroup();                                                                       // 160
		virtual void         SetCombatGroup(CombatGroup* a_group);                                                   // 161
		virtual bool         CheckValidTarget(TESObjectREFR& a_ref) const;                                           // 162
		virtual void         Unk_163();                                                                              // 163
		virtual void         Unk_164();                                                                              // 164
		virtual void         Unk_165();                                                                              // 165
		virtual void         Unk_166();                                                                              // 166
		virtual void         Unk_167();                                                                              // 167
		virtual void         Unk_168();                                                                              // 168
		virtual void         Unk_169();                                                                              // 169
		virtual void         Unk_16A();                                                                              // 16A
		virtual void         Unk_16B();                                                                              // 16B
		virtual bool         IsInCombat() const;                                                                     // 16C
		virtual void         Unk_16D();                                                                              // 16D
		virtual void         StopCombat();                                                                           // 16E
		virtual void         Unk_16F();                                                                              // 16F
		virtual void         SetLifeState(std::uint32_t a_state);                                                    // 170
		virtual void         Unk_171();                                                                              // 171
		virtual void         Unk_172();                                                                              // 172
		virtual void         Unk_173();                                                                              // 173
		virtual void         Unk_174();                                                                              // 174
		virtual bool         IsInFaction(TESFaction* a_faction);                                                     // 175
		virtual void         Unk_176();                                                                              // 176
		virtual void         Unk_177();                                                                              // 177
		virtual void         Unk_178();                                                                              // 178
		virtual void         Unk_179();                                                                              // 179
		virtual void         Unk_17A();                                                                              // 17A
		virtual void         Unk_17B();                                                                              // 17B
		virtual void         Unk_17C();                                                                              // 17C
		virtual void         Unk_17D();                                                                              // 17D
		virtual void         Unk_17E();                                                                              // 17E
		virtual void         Unk_17F();                                                                              // 17F
		virtual void         Unk_180();                                                                              // 180
		virtual void         Unk_181();                                                                              // 181
		virtual void         Unk_182();                                                                              // 182
		virtual void         Unk_183();                                                                              // 183
		virtual void         Unk_184();                                                                              // 184
		virtual void         Unk_185();                                                                              // 185
		virtual void         Unk_186();                                                                              // 186
		virtual void         Unk_187();                                                                              // 187
		virtual void         Unk_188();                                                                              // 188
		virtual void         Unk_189();                                                                              // 189
		virtual void         Unk_18A();                                                                              // 18A
		virtual void         Unk_18B();                                                                              // 18B
		virtual void         Unk_18C();                                                                              // 18C
		virtual void         Unk_18D();                                                                              // 18D
		virtual void         Unk_18E();                                                                              // 18E
		virtual void         Unk_18F();                                                                              // 18F
		virtual void         Unk_190();                                                                              // 190
		virtual void         Unk_191();                                                                              // 191
		virtual void         Unk_192();                                                                              // 192
		virtual void         Unk_193();                                                                              // 193
		virtual void         Unk_194();                                                                              // 194
		virtual void         Unk_195();                                                                              // 195
		virtual void         Unk_196();                                                                              // 196
		virtual void         Unk_197();                                                                              // 197
		virtual void         Unk_198();                                                                              // 198
		virtual void         Unk_199();                                                                              // 199
		virtual void         Unk_19A();                                                                              // 19A
		virtual void         Unk_19B();                                                                              // 19B
		virtual void         Unk_19C();                                                                              // 19C
		virtual void         Unk_19D();                                                                              // 19D
		virtual void         Unk_19E();                                                                              // 19E
		virtual void         Unk_19F();                                                                              // 19F
		virtual void         Unk_1A0();                                                                              // 1A0
		virtual void         Unk_1A1();                                                                              // 1A1

		[[nodiscard]] bool IsHostileToActor(Actor* a_actor);

		// members
		stl::enumeration<BOOL_BITS, std::uint32_t>           boolBits;                 // 240
		std::uint32_t                                        unk244;                   // 244
		std::uint64_t                                        unk248;                   // 248
		std::uint64_t                                        unk250;                   // 250
		std::uint64_t                                        unk258;                   // 258
		AIProcess*                                           currentProcess;           // 260
		std::uint64_t                                        unk268;                   // 268
		std::uint64_t                                        unk270;                   // 270
		std::uint64_t                                        unk278;                   // 278
		std::uint64_t                                        unk280;                   // 280
		CombatController*                                    combatController;         // 288
		std::uint64_t                                        unk290;                   // 290
		ActorValueStorage                                    avStorage;                // 298
		std::uint64_t                                        unk2C0;                   // 2C0
		stl::enumeration<ACTOR_CRITICAL_STAGE, std::int32_t> criticalStage;            // 2C8
		std::uint32_t                                        dialogueItemTarget;       // 2CC - TESPointerHandle
		std::uint32_t                                        currentCombatTarget;      // 2D0 - TESPointerHandle
		std::uint32_t                                        myKiller;                 // 2D4 - TESPointerHandle
		std::uint64_t                                        unk2D8;                   // 2D8
		std::uint64_t                                        unk2E0;                   // 2E0
		std::uint32_t                                        actionValue;              // 2E8
		float                                                timerOnAction;            // 2EC
		std::uint64_t                                        unk2F0;                   // 2F0
		std::uint32_t                                        intimidateBribeDayStamp;  // 2F8
		std::uint32_t                                        unk2FC;                   // 2FC
		std::uint64_t                                        unk300;                   // 300
		std::uint64_t                                        unk308;                   // 308
		std::uint64_t                                        unk310;                   // 310
		std::uint64_t                                        unk318;                   // 318
		std::uint64_t                                        unk320;                   // 320
		std::uint64_t                                        unk328;                   // 328
		std::uint64_t                                        unk330;                   // 330
		std::uint64_t                                        unk338;                   // 338
		std::uint64_t                                        unk340;                   // 340
		std::uint64_t                                        unk348;                   // 348
		std::uint64_t                                        unk350;                   // 350
		std::uint64_t                                        unk358;                   // 358
		std::uint64_t                                        unk360;                   // 360
		std::uint64_t                                        unk368;                   // 368
		std::uint64_t                                        unk370;                   // 370
		std::uint64_t                                        unk378;                   // 378
		std::uint64_t                                        unk380;                   // 380
		TESRace*                                             race;                     // 388
		Perks*                                               perks;                    // 390
		std::uint32_t                                        unk398;                   // 398
		mutable BSReadWriteLock                              perkArrayLock;            // 39C
		std::uint32_t                                        unk3A4;                   // 394
		stl::enumeration<BOOL_FLAGS, std::uint32_t>          boolFlags;                // 3A8
		stl::enumeration<BOOL_FLAGS2, std::uint32_t>         boolFlags2;               // 3AC
		std::uint64_t                                        unk3B0;                   // 3B0
		std::uint64_t                                        unk3B8;                   // 3B8
		std::uint64_t                                        unk3C0;                   // 3C0
		std::uint64_t                                        unk3C8;                   // 3C8
		std::uint64_t                                        unk3D0;                   // 3D0
		std::uint64_t                                        unk3D8;                   // 3D8
		std::uint64_t                                        unk3E0;                   // 3E0
		std::uint64_t                                        unk3E8;                   // 3E8
		std::uint64_t                                        unk3F0;                   // 3F0
		std::uint64_t                                        unk3F8;                   // 3F8
		std::uint64_t                                        unk400;                   // 400
		std::uint64_t                                        unk408;                   // 408
		std::uint64_t                                        unk410;                   // 410
		std::uint64_t                                        unk418;                   // 418
		std::uint64_t                                        unk420;                   // 420
		std::uint64_t                                        unk428;                   // 428
		std::uint64_t                                        unk430;                   // 430
		std::uint64_t                                        unk438;                   // 438
		std::uint64_t                                        unk440;                   // 440
		std::uint64_t                                        unk448;                   // 448
		std::uint64_t                                        unk450;                   // 450
		std::uint64_t                                        unk458;                   // 458
		std::uint64_t                                        unk460;                   // 460
		std::uint64_t                                        unk468;                   // 468
		std::uint64_t                                        unk470;                   // 470
		std::uint64_t                                        unk478;                   // 478
		std::uint64_t                                        unk480;                   // 480
		std::uint64_t                                        unk488;                   // 488
		std::uint64_t                                        unk490;                   // 490
		std::uint64_t                                        unk498;                   // 498
		std::uint64_t                                        unk4A0;                   // 4A0
		std::uint64_t                                        unk4A8;                   // 4A8
		std::uint64_t                                        unk4B0;                   // 4B0
		std::uint64_t                                        unk4B8;                   // 4B8
		std::uint64_t                                        unk4C0;                   // 4C0
		std::uint64_t                                        unk4C8;                   // 4C8
		std::uint64_t                                        unk4D0;                   // 4D0
		std::uint64_t                                        unk4D8;                   // 4D8
		std::uint64_t                                        unk4E0;                   // 4E0
		std::uint64_t                                        unk4E8;                   // 4E8
		std::uint64_t                                        unk4F0;                   // 4F0
		std::uint64_t                                        unk4F8;                   // 4F8
		std::uint64_t                                        unk500;                   // 500
		std::uint64_t                                        unk508;                   // 508
		std::uint64_t                                        unk510;                   // 510
		std::uint64_t                                        unk518;                   // 518
		std::uint64_t                                        unk520;                   // 520
		std::uint64_t                                        unk528;                   // 528
		std::uint64_t                                        unk530;                   // 530
		std::uint64_t                                        unk538;                   // 538
		std::uint64_t                                        unk540;                   // 540
		std::uint64_t                                        unk548;                   // 548
	};
	static_assert(sizeof(Actor) == 0x550);
}
