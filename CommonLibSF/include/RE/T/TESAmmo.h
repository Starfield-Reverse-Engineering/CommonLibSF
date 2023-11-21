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
		BGSProjectile*                       projectile;  // 00
		std::uint32_t                        health;      // 08
		float                                damage;      // 0C
		stl::enumeration<Flag, std::uint8_t> flags;       // 10
	};
	static_assert(sizeof(AMMO_DATA) == 0x18);

	class TESAmmo :
		public TESBoundObject,             // 000
		public TESFullName,                // 118
		public BGSModelMaterialSwap,       // 128
		public TESValueForm,               // 150
		public BGSDestructibleObjectForm,  // 160
		public BGSPickupPutdownSounds,     // 170
		public TESDescription,             // 1D8
		public BGSKeywordForm,             // 1F0
		public TESWeightForm               // 220
	{
	public:
		SF_RTTI_VTABLE(TESAmmo);
		SF_FORMTYPE(AMMO);

		~TESAmmo() override;  // 00

		// members
		AMMO_DATA          data;         // 230
		BGSLocalizedString shortDesc;    // 248
		TESModel           shellCasing;  // 250
	};
	static_assert(sizeof(TESAmmo) == 0x270);
}
