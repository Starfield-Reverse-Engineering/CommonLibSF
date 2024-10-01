#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class BGSProjectile;

	struct AMMO_DATA
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kIgnoresNormalWeaponResistance = 1 << 0,
			kNonPlayable = 1 << 1,
			kHasCountBased3D = 1 << 2
		};

		// members
		BGSProjectile*                   projectile;  // 00
		std::uint32_t                    health;      // 08
		float                            damage;      // 0C
		REX::EnumSet<Flag, std::uint8_t> flags;       // 10
	};
	static_assert(sizeof(AMMO_DATA) == 0x18);

	class TESAmmo :
		public TESBoundObject,             // 000
		public TESFullName,                // 0E0
		public BGSModelMaterialSwap,       // 0F0
		public TESValueForm,               // 118
		public BGSDestructibleObjectForm,  // 128
		public BGSPickupPutdownSounds,     // 138
		public TESDescription,             // 1A0
		public BGSKeywordForm,             // 1B8
		public TESWeightForm               // 1E8
	{
	public:
		SF_RTTI_VTABLE(TESAmmo);
		SF_FORMTYPE(AMMO);

		~TESAmmo() override;  // 00

		// members
		AMMO_DATA          data;         // 1F8
		BGSLocalizedString shortDesc;    // 210
		TESModel           shellCasing;  // 218
	};
	static_assert(sizeof(TESAmmo) == 0x240);
}
