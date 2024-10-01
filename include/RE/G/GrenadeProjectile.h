#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/P/Projectile.h"

namespace RE
{
	struct BGSDecalGroup;

	class GrenadeProjectile : public Projectile
	{
	public:
		SF_RTTI_VTABLE(GrenadeProjectile);
		SF_FORMTYPE(PGRE);

		~GrenadeProjectile() override;  // 00

		// members
		BSTSmartPointer<BGSDecalGroup> decalGroup;           // 260 - NiPointer?
		bool                           collisionGroupReset;  // 268
	};
	static_assert(sizeof(GrenadeProjectile) == 0x260);
}
