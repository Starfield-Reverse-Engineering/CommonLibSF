#pragma once

#include "RE/P/Projectile.h"

namespace RE
{
	class ConeProjectile : public Projectile
	{
	public:
		SF_RTTI_VTABLE(ConeProjectile);
		SF_FORMTYPE(PCON);

		~ConeProjectile() override;  // 00

		// members
		REX::Enum<ImpactResult, std::int32_t> impactResult;                  // 260
		float                                 environmentTimer;              // 264
		float                                 coneSpreadTangent;             // 268
		float                                 initialCollisionSphereRadius;  // 26C
		Location                              origin;                        // 270
		void*                                 collisionShape;                // 288
		BSTArray<std::int32_t>                collisions;                    // 290
	};
	static_assert(sizeof(ConeProjectile) == 0x290);
}
