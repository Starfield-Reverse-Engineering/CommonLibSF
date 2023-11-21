#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESModel.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class BGSCollisionLayer;
	class BGSCurveForm;
	class BGSExplosion;
	class BGSProjectile;
	class BGSTextureSet;
	class TESObjectLIGH;
	class TESObjectWEAP;

	struct BGSProjectileData  // DATA
	{
	public:
		enum class BGSProjectileFlags
		{
			kNone = 0,
			kHitScan = 1 << 0,
			kExplosion = 1 << 1,
			kExplosionAltTrigger = 1 << 2,
			kMuzzleFlash = 1 << 3,
			kCanTurnOff = 1 << 5,
			kCanPickUp = 1 << 6,
			kSupersonic = 1 << 7,
			kPinsLimbs = 1 << 8,
			kPassSMTransparent = 1 << 9,
			kDisableCombatAimCorrection = 1 << 10,
			kPenetratesGeometry = 1 << 11,
			kContinuousUpdate = 1 << 12,
			kSeeksTarget = 1 << 13
		};

		enum class Type
		{
			kMissile = 1 << 0,
			kGrenade = 1 << 1,
			kBeam = 1 << 2,
			kFlamethrower = 1 << 3,
			kCone = 1 << 4,
			kBarrier = 1 << 5,
			kArrow = 1 << 6
		};

		// members
		BSFixedString                                       unk00;                // 00
		BSFixedString                                       unk08;                // 08
		TESObjectLIGH*                                      light;                // 10
		TESObjectLIGH*                                      muzzleFlashLight;     // 18
		BGSExplosion*                                       explosionType;        // 20
		TESObjectWEAP*                                      defaultWeaponSource;  // 28
		BGSTextureSet*                                      decalData;            // 30
		BGSCollisionLayer*                                  collisionLayer;       // 38
		BGSProjectile*                                      vatsProjectile;       // 40
		stl::enumeration<BGSProjectileFlags, std::uint32_t> flags;                // 48
		float                                               gravity;              // 4C
		float                                               speed;                // 50
		float                                               range;                // 54
		float                                               explosionProximity;   // 58
		float                                               explosionTimer;       // 5C
		float                                               muzzleFlashDuration;  // 60
		float                                               fadeOutTime;          // 64
		float                                               force;                // 68
		float                                               coneSpread;           // 6C
		float                                               collisionRadius;      // 70
		float                                               lifetime;             // 74
		float                                               relaunchInterval;     // 78
		float                                               unk7C;                // 7C
		std::uint32_t                                       unk80;                // 80
		stl::enumeration<Type, std::uint8_t>                type;                 // 84
		std::uint8_t                                        unk85;                // 85
		float                                               unk88;                // 88
		float                                               unk8C;                // 8C
		float                                               unk90;                // 90
		float                                               unk94;                // 94
	};
	static_assert(sizeof(BGSProjectileData) == 0x98);

	class BGSProjectile :
		public TESBoundObject,            // 000
		public TESFullName,               // 118
		public TESModel,                  // 128
		public BGSPreloadable,            // 148
		public BGSDestructibleObjectForm  // 150
	{
	public:
		SF_RTTI_VTABLE(BGSProjectile);
		SF_FORMTYPE(PROJ);

		~BGSProjectile() override;  // 00

		// members
		BGSProjectileData        data;              // 160
		TESModel                 muzzleFlashModel;  // 1F8
		BGSCurveForm*            curveTable;        // 218
		BGSAudio::WwiseSoundHook activeSoundLoop;   // 220
		BGSAudio::WwiseSoundHook countdownSound;    // 250
		BGSAudio::WwiseSoundHook deactivateSound;   // 280
		std::uint32_t            unk2B0;            // 2B0
	};
	static_assert(sizeof(BGSProjectile) == 0x2B8);
}
