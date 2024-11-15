#pragma once

#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSBlockBashData.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEditorID.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSInstanceNamingRulesForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class TESObjectWEAPInstanceData;

	class WeaponAmmoData
	{
	public:
		char         pad_0000[24];   // 0x0000
		RE::TESAmmo* ammo;           // 0x0020
		char         pad_0028[8];    // 0x0028
		uint32_t     ammoCapacity;   // 0x0030
		char         pad_0034[336];  // 0x0034
	};  // Size: 0x0184

	static_assert(offsetof(WeaponAmmoData, ammo) == 0x18);

	class WeaponDamageData
	{
	public:
		char                                                                                                pad_0000[16];          // 0x0000 // a pointer?
		float                                                                                               attackDamage;          // 0x0010
		float                                                                                               rangeMin;              // 0x0014
		float                                                                                               rangeMax;              // 0x0018
		float                                                                                               Unk1;                  // 0x001C
		float                                                                                               Unk2;                  // 0x0020
		float                                                                                               Unk3;                  // 0x0024
		float                                                                                               Unk4;                  // 0x0028
		float                                                                                               Unk5;                  // 0x002C
		float                                                                                               Unk6;                  // 0x0030
		float                                                                                               outOfRangeDamageMult;  // 0x0034
		float                                                                                               critDamageMult;        // 0x0038
		float                                                                                               N000001A5;             // 0x003C
		RE::SpellItem*                                                                                      critEffect;            // 0x0040
		float                                                                                               N00000175;             // 0x0048
		float                                                                                               critChanceIncMult;     // 0x004C
		RE::BSTArray<RE::BSTTuple3<RE::TESForm*, RE::BGSCurveForm*, RE::BGSTypedFormValuePair::SharedVal>>* damageTypes;           // 0x0050
	};  // Size: 0x0140

	static_assert(offsetof(WeaponDamageData, critChanceIncMult) == 0x4C);
	static_assert(offsetof(WeaponDamageData, damageTypes) == 0x50);

	class WeaponFiringData
	{
	public:
		void* unk;
		void* instanceData;
		void* FiringType;
		char  pad_0000[0x4];              // 0x18
		float burstDelaySeconds;          // 1C
		float attackSeconds;              // 0x0020
		float fireSeconds;                // 0x0024
		float attackDelaySec;             // 0x0028
		float boltChargeSec;              // 0x002C
		float pad30;                      // 0x0030
		float shotsPerSecond;             // 34 FIX
		bool  overrideRateOfFire;         // 38
		float unknown;                    // 3C
		float triggerThresholdPrimary;    // 40
		float unk44;                      // 44
		float triggerThresholdSecondary;  // 48 FIX
		bool  DualTriggerSet;             // 50
	};

	// static_assert(offsetof(WeaponFiringData, shotsPerSecond) == 0x34);
	static_assert(offsetof(WeaponFiringData, pad30) == 0x30);
	static_assert(offsetof(WeaponFiringData, triggerThresholdPrimary) == 0x40);
	static_assert(offsetof(WeaponFiringData, triggerThresholdSecondary) == 0x48);
	static_assert(offsetof(WeaponFiringData, burstDelaySeconds) == 0x1C);
	static_assert(offsetof(WeaponFiringData, overrideRateOfFire) == 0x38);
	static_assert(offsetof(WeaponFiringData, boltChargeSec) == 0x2C);
	static_assert(offsetof(WeaponFiringData, attackDelaySec) == 0x28);
	static_assert(offsetof(WeaponFiringData, unknown) == 0x3C);

	class WeaponDataFlags
	{
	public:
		TESObjectWEAPInstanceData* pad1;  // 0x0000
		TESObjectWEAPInstanceData* pad2;
		uint8_t                    NonPlayable;
		uint8_t                    PlayerOnly;
		uint8_t                    flag3;
		uint8_t                    flag4;
		uint8_t                    CantDrop;
		uint8_t                    MinorCrime;
		uint8_t                    NonHostile;
		uint8_t                    flag8;
		uint8_t                    flag9;
		uint8_t                    flag10;
		uint8_t                    flag11;
		uint8_t                    flag12;
	};

	class WeaponDataGeneral
	{
	public:
		char         pad_0000[16];      // 0x0000
		void*        equipSlot;         // 0x0010
		char         pad_0018[24];      // 0x0018
		void*        barrelData;        // 0x0030
		uint32_t     Type;              // 0x0038
		float        baseWeight;        // 0x003C
		std::int32_t baseValue;         // 0x0040
		float        baseSpeed;         // 0x0044
		float        attackOxygenCost;  // 0x0048
		char         pad_004C[1];       // 0x004C
	};  // Size: 0x004D

	class WeapDataMelee
	{
	public:
		char    pad_0000[16];   // 0x0000
		float   N000001E6;      // 0x0010
		float   bashDamage;     // 0x0014
		float   reach;          // 0x0018
		uint8_t Stagger;        // 0x001C
		char    pad_001D[291];  // 0x001D
	};  // Size: 0x0140

	class WeaponDataPower
	{
	public:
		char pad_0000[64];  // 0x0000
	};  // Size: 0x0040

	class WeapDataReload
	{
	public:
		char  pad_0000[8];  // 0x0000
		void* N000001F9;    // 0x0008
		float Unknown;      // 0x0010
		float Reloadspeed;  // 0x0014
		bool  Charging;     // 0x0018
		bool  Single;       // 0x0019
	};  // Size: 0x001A

	class WeapDataTurret
	{
	public:
		char pad_0000[1088];  // 0x0000
	};  // Size: 0x0440

	class WeapDataVariableRange
	{
	public:
		char pad_0000[64];  // 0x0000
	};  // Size: 0x0040

	class WeapDataVisuals
	{
	public:
		char pad_0000[64];  // 0x0000
	};  // Size: 0x0040

	class WeapDataShipWeapon
	{
	public:
		char  pad_0000[32];  // 0x0000
		float Unknown;       // 0x0020
		char  pad_0024[4];   // 0x0024
		float Unknown1;      // 0x0028
		float Unknown2;      // 0x002C
		float Unknown3;      // 0x0030
		char  pad_0034[12];  // 0x0034
	};  // Size: 0x0040

	class WeaponDataAudio
	{
	public:
		char pad_0000[64];  // 0x0000
	};  // Size: 0x0040

	class WeaponDataCharge
	{
	public:
		char pad_0000[64];  // 0x0000
	};  // Size: 0x0040

	class WeaponDataAim
	{
	public:
		void* pad0;
		void* pa8;
		float sightedTransitionSeconds;  // 10
		// float pad;
		void*         aimDownSightTemplate;  // 18
		void*         pad;                   // 20 AimDownSightData
		void*         aimModel;              // 28
		void*         pad30;                 // 30 AimModelData
		std::uint64_t pad38;                 // 38
		std::uint64_t pad40;                 // 40
		std::uint64_t pad48;                 // 48
		std::uint64_t pad50;                 // 50
		std::uint8_t  accuracyBonus;         // 58 Confirm later
	};

	static_assert(offsetof(WeaponDataAim, sightedTransitionSeconds) == 0x10);
	static_assert(offsetof(WeaponDataAim, aimDownSightTemplate) == 0x18);
	static_assert(offsetof(WeaponDataAim, aimModel) == 0x28);
	static_assert(offsetof(WeaponDataAim, accuracyBonus) == 0x58);

	class TESObjectWEAPInstanceData
	{
	public:
		char                   pad_0000[24];           // 0x0000
		WeaponDataAim*         WeaponDataAim;          // 0x0018
		WeaponAmmoData*        WeaponAmmoData;         // 0x0020
		WeaponDataAudio*       WeaponDataAudio;        // 0x0028
		WeaponDataCharge*      WeaponDataCharge;       // 0x0030
		WeaponDamageData*      WeaponDamage;           // 0x0038
		WeaponFiringData*      WeaponFiringData;       // 0x0040
		WeaponDataFlags*       WeaponFlags;            // 0x0048
		WeaponDataGeneral*     WeapDataGeneral;        // 0x0050
		WeapDataMelee*         WeapDataMelee;          // 0x0058
		WeaponDataPower*       WeapDataPower;          // 0x0060
		WeapDataReload*        WeapDataReload;         // 0x0068
		WeapDataTurret*        WeapDataTurret;         // 0x0070
		WeapDataVariableRange* WeapDataVariableRange;  // 0x0078
		WeapDataVisuals*       WeapDataVisuals;        // 0x0080
		WeapDataShipWeapon*    WeapDataShipWeapon;     // 0x0088
	};

	static_assert(offsetof(TESObjectWEAPInstanceData, WeaponAmmoData) == 0x20);
	static_assert(offsetof(TESObjectWEAPInstanceData, WeaponDamage) == 0x38);

	namespace BGSMod::Attachment
	{
		class Mod;
	}

	class TESObjectWEAP :
		public TESBoundObject,             // 000
		public TESFullName,                // 0E0
		public BGSModelMaterialSwap,       // 0F0
		public TESEnchantableForm,         // 118
		public BGSDestructibleObjectForm,  // 130
		public BGSEquipType,               // 140
		public BGSPreloadable,             // 150
		public BGSPickupPutdownSounds,     // 158
		public BGSBlockBashData,           // 1C0
		public BGSKeywordForm,             // 1D8
		public TESDescription,             // 208
		public BGSInstanceNamingRulesForm  // 220
	{
	public:
		SF_RTTI_VTABLE(TESObjectWEAP);
		SF_FORMTYPE(WEAP);

		~TESObjectWEAP() override;  // 00

		// members
		BGSEditorID                                formEditorID;       // 230
		BSTSmartPointer<TESObjectWEAPInstanceData> weaponData;         // 240
		BGSAttachParentArray                       attachParents;      // 248
		BGSMod::Attachment::Mod*                   embeddedWeaponMod;  // 268
		std::uint8_t                               unk270;             // 270
	};
	static_assert(sizeof(TESObjectWEAP) == 0x280);
}
