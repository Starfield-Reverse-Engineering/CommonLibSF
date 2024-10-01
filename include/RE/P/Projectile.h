#pragma once

#include "RE/B/BGSBodyPartDefs.h"
#include "RE/B/BGSEquipIndex.h"
#include "RE/B/BGSObjectInstance.h"
#include "RE/B/BSTArray.h"
#include "RE/L/Location.h"
#include "RE/M/MagicSystem.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTransform.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	enum class COL_LAYER;
	enum class ImpactResult;

	class bhkNPCollisionObject;
	class ActorCause;
	class AlchemyItem;
	class BGSExplosion;
	class BGSMaterialType;
	class BGSProjectile;
	class CombatController;
	class EffectSetting;
	class MagicItem;
	class TESAmmo;
	class TESObjectWEAP;

	struct ImpactCreation;

	class ProjectileLaunchData
	{
	public:
		// members
		Location                                            origin;                   // 00
		NiPoint3                                            contactNormal;            // 18
		NiPoint3                                            destination;              // 24
		BGSProjectile*                                      projectileBase;           // 30
		TESObjectREFR*                                      shooter;                  // 38
		CombatController*                                   shooterCombatController;  // 40
		TESAmmo*                                            fromAmmo;                 // 48
		TESObjectREFR*                                      homingTarget;             // 50
		TESObjectCELL*                                      parentCell;               // 58
		MagicItem*                                          spell;                    // 60
		AlchemyItem*                                        poison;                   // 68
		BGSObjectInstanceT<TESObjectWEAP>                   fromWeapon;               // 70
		REX::Enum<MagicSystem::CastingSource, std::uint8_t> castingSource;            // 80
		REX::Enum<BGSBodyPartDefs::LIMB_ENUM, std::int32_t> targetLimbEnum;           // 84
		void*                                               unk88;                    // 88 - smart ptr
		BGSEquipIndex                                       equipIndex;               // 90
		std::uint32_t                                       unk94;                    // 94
		Location                                            unk98;                    // 98
		float                                               unkB0;                    // B0
		std::uint32_t                                       unkB4;                    // B4
		std::uint32_t                                       unkB8;                    // B8
		std::uint32_t                                       unkBC;                    // BC
		std::uint32_t                                       unkC0;                    // C0
		float                                               power;                    // C4
		float                                               unkC8;                    // C8
		float                                               unkCC;                    // CC
		std::uint32_t                                       unkD0;                    // D0
		float                                               unkD4;                    // D4
		float                                               range;                    // D8
		float                                               unkDC;                    // DC
		std::uint8_t                                        unkE0;                    // E0
		std::uint8_t                                        unkE1;                    // E1
		std::uint8_t                                        unkE2;                    // E2
		std::uint8_t                                        unkE3;                    // E3
		bool                                                useOrigin;                // E4
		std::uint8_t                                        unkE5;                    // E5
		std::uint8_t                                        unkE6;                    // E6
		std::uint8_t                                        unkE7;                    // E7
		std::uint8_t                                        unkE8;                    // E8
		std::uint8_t                                        unkE9;                    // E9
		bool                                                penetrates;               // EA
		std::uint8_t                                        unkEB;                    // EB
		std::uint8_t                                        unkEC;                    // EC
		std::uint8_t                                        unkED;                    // ED
		std::uint8_t                                        unkEE;                    // EE
		std::uint8_t                                        unkEF;                    // EF
		std::uint8_t                                        unkF0;                    // F0
		std::uint8_t                                        unkF1;                    // F1
		bool                                                continuousUpdate;         // F2
	};
	static_assert(sizeof(ProjectileLaunchData) == 0xF8);

	class Projectile : public TESObjectREFR
	{
	public:
		SF_RTTI_VTABLE(Projectile);

		struct ImpactData
		{
		public:
			// members
			Location                                            location;                // 00
			NiPoint3                                            normal;                  // 18
			std::uint64_t                                       unk28;                   // 28
			std::uint32_t                                       collidee;                // 30 - TESPointerHandle
			std::uint32_t                                       unk34;                   // 34
			NiPointer<bhkNPCollisionObject>                     colObj;                  // 38
			BGSMaterialType*                                    materialType;            // 40
			REX::Enum<BGSBodyPartDefs::LIMB_ENUM, std::int32_t> damageLimb;              // 48
			REX::Enum<COL_LAYER, std::int32_t>                  collisionLayer;          // 4C
			std::uint64_t                                       unk50;                   // 50
			REX::Enum<ImpactResult, std::int32_t>               resultOverride;          // 58
			std::uint32_t                                       unk5C;                   // 5C
			float                                               decalSize;               // 60
			std::uint32_t                                       collisionShapeKey;       // 64
			std::int16_t                                        targetWorldObjectCount;  // 68
			std::int16_t                                        targetWorldObjectIndex;  // 6A
			bool                                                processed;               // 6C
			bool                                                spellCast;               // 6D
			bool                                                effectSpawned;           // 6E
			bool                                                backFace;                // 6F
			std::uint8_t                                        unk70;                   // 70
			std::uint64_t                                       unk78;                   // 78
		};
		static_assert(sizeof(ImpactData) == 0x80);

		~Projectile() override;  // 00

		// add
		virtual bool          IsMissileProjectile() const;                   // 130
		virtual bool          IsGrenadeProjectile() const;                   // 131
		virtual bool          IsFlameProjectile() const;                     // 132
		virtual bool          IsBeamProjectile() const;                      // 133
		virtual bool          IsFogProjectile() const;                       // 134
		virtual bool          IsBarrierProjectile() const;                   // 135
		virtual void          Unk_136();                                     // 136
		virtual void          Unk_137();                                     // 137
		virtual void          Unk_138();                                     // 138
		virtual void          UpdateImpl(float a_delta);                     // 139
		virtual bool          ProcessImpacts();                              // 13A
		virtual void          Unk_13B();                                     // 13B
		virtual void          Unk_13C();                                     // 13C
		virtual float         GetPowerSpeedMult() const;                     // 13D
		virtual float         GetWeaponSpeedMult() const;                    // 13E
		virtual void          Unk_13F();                                     // 13F
		virtual void          Unk_140();                                     // 140
		virtual void          Unk_141();                                     // 141
		virtual void          Unk_142();                                     // 142
		virtual void          Unk_143();                                     // 143
		virtual void          Unk_144();                                     // 144
		virtual bool          TurnOff(Actor* a_actionActor, bool a_silent);  // 145
		virtual bool          IsPermanent();                                 // 146
		virtual float         GetGravity() const;                            // 147
		virtual void          CleanUpPointersOnDisable();                    // 148
		virtual void          Unk_149();                                     // 149
		virtual void          Unk_14A();                                     // 14A
		virtual void          Unk_14B();                                     // 14B
		virtual void          Unk_14C();                                     // 14C
		virtual void          Unk_14D();                                     // 14D
		virtual bool          GetAllowMovement() const;                      // 14E
		virtual void          Unk_14F();                                     // 14F
		virtual void          Unk_150();                                     // 150
		virtual void          Unk_151();                                     // 151
		virtual void          Unk_152();                                     // 152
		virtual void          Unk_153();                                     // 153
		virtual void          InitializeImpl();                              // 154
		virtual void          Relaunch(ProjectileLaunchData& a_data);        // 155
		virtual std::uint32_t AddImpact(const ImpactCreation& a_data);       // 156
		virtual void          Unk_157();                                     // 157
		virtual void          Unk_158();                                     // 158
		virtual void          Unk_159();                                     // 159
		virtual void          Unk_15A();                                     // 15A
		virtual void          Unk_15B();                                     // 15B
		virtual bool          ShouldUseDesiredTarget();                      // 15C

		// members
		BSTArray<ImpactData>                                impacts;              // 0F0
		NiPointer<bhkNPCollisionObject>                     collisionObject;      // 100
		NiPointer<TESObjectREFR>                            droppedRefr;          // 108
		NiTransform                                         followOffset;         // 110
		BSSpinLock                                          lock;                 // 150
		NiPoint3                                            movementDirection;    // 158
		NiPoint3                                            velocity;             // 164
		void*                                               unk170;               // 170 - smart ptr
		NiPointer<ActorCause>                               actorCause;           // 178
		std::uint32_t                                       shooterHandle;        // 180 - TESPointerHandle
		std::uint32_t                                       desiredTargetHandle;  // 184 - TESPointerHandle
		std::uint32_t                                       unk188;               // 188
		std::uint32_t                                       unk18C;               // 18C
		std::uint32_t                                       unk190;               // 190
		std::uint32_t                                       unk194;               // 194
		BGSExplosion*                                       explosion;            // 198
		MagicItem*                                          spell;                // 1A0
		EffectSetting*                                      avEffect;             // 1A8
		void*                                               unk1B0;               // 1B0 - smart ptr
		void*                                               unk1B8;               // 1B8 - smart ptr
		void*                                               unk1C0;               // 1C0 - smart ptr
		void*                                               unk1C8;               // 1C8 - smart ptr
		std::uint64_t                                       unk1D0;               // 1D0
		BGSEquipIndex                                       equipIndex;           // 1D8
		REX::Enum<BGSBodyPartDefs::LIMB_ENUM, std::int32_t> targetLimbEnum;       // 1DC
		NiPointer<NiAVObject>                               targetLimbObj;        // 1E0
		std::uint64_t                                       unk1E8;               // 1E8
		BGSObjectInstanceT<TESObjectWEAP>                   weaponSource;         // 1F0
		TESAmmo*                                            ammoSource;           // 200
		std::uint64_t                                       flags;                // 208
		std::uint32_t                                       unk210;               // 210
		float                                               power;                // 214
		float                                               speedMult;            // 218
		float                                               range;                // 21C
		float                                               age;                  // 220
		float                                               damage;               // 224
		float                                               alpha;                // 228
		float                                               explosionTimer;       // 22C
		float                                               blinkTimer;           // 230
		float                                               distanceMoved;        // 234
		std::uint32_t                                       unk238;               // 238
		float                                               scale;                // 23C
		float                                               unk240;               // 240
		float                                               unk244;               // 244
		std::uint32_t                                       unk248;               // 248
		std::uint32_t                                       unk24C;               // 24C
		std::uint32_t                                       unk250;               // 250
		std::uint32_t                                       unk254;               // 254
		REX::Enum<MagicSystem::CastingSource, std::uint8_t> castingSource;        // 258
		std::uint8_t                                        unk259;               // 259
		bool                                                artRequested;         // 25A
		bool                                                animationsLoaded;     // 25B
		std::uint8_t                                        unk25C;               // 25C
	};
	static_assert(sizeof(Projectile) == 0x250);
}
