#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class ActorValueInfo;

	enum class ACTOR_VALUE_MODIFIER
	{
		kPermanent = 0,
		kTemporary = 1,
		kDamage = 2,

		kTotal = 3
	};

	class ActorValue :
		public BSTSingletonImplicit<ActorValue>  // 000
	{
	public:
		enum class Type : std::uint32_t
		{
			kDerivedAttribute,
			kAttribute,
			kSkill,
			kAIAttribute,
			kResistance,
			kCondition,
			kCharge,
			kIntValue,
			kVariable,
			kResource
		};

		[[nodiscard]] static ActorValue* GetSingleton()
		{
			using func_t = decltype(&ActorValue::GetSingleton);
			static REL::Relocation<func_t> func{ ID::ActorValue::GetSingleton };
			return func();
		}

		// members
		ActorValueInfo*           absorbChance;                                // 000
		ActorValueInfo*           oxygen;                                      // 008
		ActorValueInfo*           aggression;                                  // 010
		ActorValueInfo*           agility;                                     // 018
		ActorValueInfo*           aimStability;                                // 020
		ActorValueInfo*           alchemy;                                     // 028
		ActorValueInfo*           animationMult;                               // 030
		ActorValueInfo*           armorPerks;                                  // 038
		ActorValueInfo*           assistance;                                  // 040
		ActorValueInfo*           attackDamageMult;                            // 048
		ActorValueInfo*           blindness;                                   // 050
		ActorValueInfo*           block;                                       // 058
		ActorValueInfo*           bloodyMess;                                  // 060
		ActorValueInfo*           bowSpeedBonus;                               // 068
		ActorValueInfo*           bowStaggerBonus;                             // 070
		ActorValueInfo*           brainCondition;                              // 078
		ActorValueInfo*           carryWeight;                                 // 080
		ActorValueInfo*           charisma;                                    // 088
		ActorValueInfo*           combatHealthRegenMult;                       // 090
		ActorValueInfo*           confidence;                                  // 098
		ActorValueInfo*           criticalHitChance;                           // 0A0
		ActorValueInfo*           criticalHitIncMult;                          // 0A8
		ActorValueInfo*           criticalHitDamageMult;                       // 0B0
		ActorValueInfo*           damageResist;                                // 0B8
		ActorValueInfo*           deafness;                                    // 0C0
		ActorValueInfo*           electromagneticDamageResist;                 // 0C8
		ActorValueInfo*           electromagneticHealth;                       // 0D0
		ActorValueInfo*           electromagneticToDamageConversionRate;       // 0D8
		ActorValueInfo*           electromagneticRecoverRateMult;              // 0E0
		ActorValueInfo*           enchanting;                                  // 0E8
		ActorValueInfo*           endurance;                                   // 0F0
		ActorValueInfo*           enduranceCondition;                          // 0F8
		ActorValueInfo*           experience;                                  // 100
		ActorValueInfo*           health;                                      // 108
		ActorValueInfo*           healRateMult;                                // 110
		ActorValueInfo*           idleChatterTimeMin;                          // 118
		ActorValueInfo*           idleChatterTimeMax;                          // 120
		ActorValueInfo*           ignoreCrippledLimbs;                         // 128
		ActorValueInfo*           intelligence;                                // 130
		ActorValueInfo*           invisibility;                                // 138
		ActorValueInfo*           invulnerable;                                // 140
		ActorValueInfo*           karma;                                       // 148
		ActorValueInfo*           leftAttackCondition;                         // 150
		ActorValueInfo*           leftItemCharge;                              // 158
		ActorValueInfo*           leftMobilityCondition;                       // 160
		ActorValueInfo*           leftWeaponSpeedMult;                         // 168
		ActorValueInfo*           lockpicking;                                 // 170
		ActorValueInfo*           luck;                                        // 178
		ActorValueInfo*           mass;                                        // 180
		ActorValueInfo*           meleeDamage;                                 // 188
		ActorValueInfo*           morality;                                    // 190
		ActorValueInfo*           movementNoiseMult;                           // 198
		ActorValueInfo*           nightEye;                                    // 1A0
		ActorValueInfo*           perception;                                  // 1A8
		ActorValueInfo*           perceptionCondition;                         // 1B0
		ActorValueInfo*           unk1B8;                                      // 1B8 - null
		ActorValueInfo*           poisonResist;                                // 1C0
		ActorValueInfo*           powerArmorBattery;                           // 1C8
		ActorValueInfo*           powerArmorHeadCondition;                     // 1D0
		ActorValueInfo*           powerArmorTorsoCondition;                    // 1D8
		ActorValueInfo*           powerArmorLeftArmCondition;                  // 1E0
		ActorValueInfo*           powerArmorRightArmCondition;                 // 1E8
		ActorValueInfo*           powerArmorLeftLegCondition;                  // 1F0
		ActorValueInfo*           powerArmorRightLegCondition;                 // 1F8
		ActorValueInfo*           envDamageHealthMax;                          // 200
		ActorValueInfo*           envDamage;                                   // 208
		ActorValueInfo*           carbonDioxideOxygenMax;                      // 210
		ActorValueInfo*           carbonDioxide;                               // 218
		ActorValueInfo*           reflectDamage;                               // 220
		ActorValueInfo*           conditionRate;                               // 228
		ActorValueInfo*           rightAttackCondition;                        // 230
		ActorValueInfo*           rightItemCharge;                             // 238
		ActorValueInfo*           rightMobilityCondition;                      // 240
		ActorValueInfo*           rotationSpeedCondition;                      // 248
		ActorValueInfo*           shieldDamageResist;                          // 250
		ActorValueInfo*           shieldPerks;                                 // 258
		ActorValueInfo*           sneak;                                       // 260
		ActorValueInfo*           unk268;                                      // 268 - null
		ActorValueInfo*           speedMult;                                   // 270
		ActorValueInfo*           unusedStamina;                               // 278
		ActorValueInfo*           strength;                                    // 280
		ActorValueInfo*           suspicious;                                  // 288
		ActorValueInfo*           telekinesis;                                 // 290
		ActorValueInfo*           unarmedDamage;                               // 298
		ActorValueInfo*           vansPerk;                                    // 2A0
		ActorValueInfo*           wardPower;                                   // 2A8
		ActorValueInfo*           waitingForPlayer;                            // 2B0
		ActorValueInfo*           waterBreathing;                              // 2B8
		ActorValueInfo*           waterWalking;                                // 2C0
		ActorValueInfo*           weaponSpeedMult;                             // 2C8
		ActorValueInfo*           weapReloadSpeedMult;                         // 2D0
		ActorValueInfo*           healRate;                                    // 2D8
		ActorValueInfo*           oxygenRate;                                  // 2E0
		ActorValueInfo*           electromagneticRecoverRate;                  // 2E8
		ActorValueInfo*           oxygenRateMult;                              // 2F0
		ActorValueInfo*           envDamageRate;                               // 2F8
		ActorValueInfo*           envDamageRateMult;                           // 300
		ActorValueInfo*           carbonDioxideRate;                           // 308
		ActorValueInfo*           carbonDioxideRateMult;                       // 310
		ActorValueInfo*           conditionRateMult;                           // 318
		ActorValueInfo*           fireResist;                                  // 320
		ActorValueInfo*           electricResist;                              // 328
		ActorValueInfo*           frostResist;                                 // 330
		ActorValueInfo*           magicResist;                                 // 338
		ActorValueInfo*           radResistIngestion;                          // 340
		ActorValueInfo*           radResistExposure;                           // 348
		ActorValueInfo*           energy;                                      // 350
		ActorValueInfo*           energyResist;                                // 358
		ActorValueInfo*           paralysis;                                   // 360
		ActorValueInfo*           attackConditionAlt1;                         // 368
		ActorValueInfo*           attackConditionAlt2;                         // 370
		ActorValueInfo*           attackConditionAlt3;                         // 378
		ActorValueInfo*           powerGenerated;                              // 380
		ActorValueInfo*           powerRadiation;                              // 388
		ActorValueInfo*           powerRequired;                               // 390
		ActorValueInfo*           food;                                        // 398
		ActorValueInfo*           water;                                       // 3A0
		ActorValueInfo*           safety;                                      // 3A8
		ActorValueInfo*           bed;                                         // 3B0
		ActorValueInfo*           happiness;                                   // 3B8
		ActorValueInfo*           fallSpeedMult;                               // 3C0
		ActorValueInfo*           workshopItemOverlap;                         // 3C8
		ActorValueInfo*           workshopProduceUntilNextCycle;               // 3D0
		ActorValueInfo*           workshopItemClampDirection;                  // 3D8
		ActorValueInfo*           workshopItemZOffset;                         // 3E0
		ActorValueInfo*           workshopLevel;                               // 3E8
		ActorValueInfo*           workshopLevelHealthPercent;                  // 3F0
		ActorValueInfo*           workshopLevelObject;                         // 3F8
		ActorValueInfo*           workshopPlayerOwned;                         // 400
		ActorValueInfo*           workshopActorWounded;                        // 408
		ActorValueInfo*           workshopStackableItem;                       // 410
		ActorValueInfo*           workshopState;                               // 418
		ActorValueInfo*           workshopStateTransition;                     // 420
		ActorValueInfo*           workshopStateTimeout;                        // 428
		ActorValueInfo*           workshopSnapPointRadius;                     // 430
		ActorValueInfo*           workshopAnythingIsGround;                    // 438
		ActorValueInfo*           workshopMaxTriangles;                        // 440
		ActorValueInfo*           workshopMaxDraws;                            // 448
		ActorValueInfo*           workshopCurrentBudget;                       // 450
		ActorValueInfo*           workshopCurrentTriangles;                    // 458
		ActorValueInfo*           workshopCurrentDraws;                        // 460
		ActorValueInfo*           workshopIgnoreSimpleIntersections;           // 468
		ActorValueInfo*           workshopAllowUnsupportedStacking;            // 470
		ActorValueInfo*           workshopSnapTransmitsPower;                  // 478
		ActorValueInfo*           workshopPowerConnection;                     // 480
		ActorValueInfo*           workshopPowerConnectionAndReceiver;          // 488
		ActorValueInfo*           ignorePlayerWhileFrenzied;                   // 490
		ActorValueInfo*           produceUses;                                 // 498
		ActorValueInfo*           starPower;                                   // 4A0
		ActorValueInfo*           starPowerRecoverRate;                        // 4A8
		ActorValueInfo*           starPowerRateMult;                           // 4B0
		ActorValueInfo*           rangedDamage;                                // 4B8
		ActorValueInfo*           dockingPermission;                           // 4C0
		ActorValueInfo*           organicResourceType;                         // 4C8
		ActorValueInfo*           envDamageSoak;                               // 4D0
		ActorValueInfo*           envCapacity;                                 // 4D8
		ActorValueInfo*           shipSystemWeaponGroup1Health;                // 4E0
		ActorValueInfo*           shipSystemWeaponGroup2Health;                // 4E8
		ActorValueInfo*           shipSystemWeaponGroup3Health;                // 4F0
		ActorValueInfo*           spaceshipWeaponGroup1EMHealth;               // 4F8
		ActorValueInfo*           spaceshipWeaponGroup2EMHealth;               // 500
		ActorValueInfo*           spaceshipWeaponGroup3EMHealth;               // 508
		ActorValueInfo*           spaceshipWeaponGroup1DamageChance;           // 510
		ActorValueInfo*           spaceshipWeaponGroup2DamageChance;           // 518
		ActorValueInfo*           spaceshipWeaponGroup3DamageChance;           // 520
		ActorValueInfo*           legendaryRank;                               // 528
		ActorValueInfo*           weatherTransitionPercent;                    // 530
		ActorValueInfo*           securityMenuRingHighlightingEnabled;         // 538
		ActorValueInfo*           securityMenuDisableUnusedKeysOptionEnabled;  // 540
		ActorValueInfo*           securityMenuAutoattemptPointsMultiplier;     // 548
		ActorValueInfo*           securityMenuMaxAutoattemptPoints;            // 550
		ActorValueInfo*           galaxyBodyScanAbility;                       // 558
		ActorValueInfo*           distantContainerAbility;                     // 560
		ActorValueInfo*           spaceshipCustomized;                         // 568
		ActorValueInfo*           spaceshipPainted;                            // 570
		BSTArray<ActorValueInfo*> hardcodedActorValues;                        // 578
		BSTArray<ActorValueInfo*> conditionActorValues;                        // 588
		std::uint32_t             avTypeCounts[10];                            // 598
	};
	static_assert(sizeof(ActorValue) == 0x5C0);
}
