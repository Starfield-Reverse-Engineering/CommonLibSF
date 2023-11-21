#pragma once

#include "RE/P/Projectile.h"

namespace RE
{
	class ConeProjectile : public Projectile
	{
	public:
		SF_RTTI_VTABLE(ConeProjectile);
		SF_FORMTYPE(PCON);

		~ConeProjectile() override;  // 00                                                                                                                                     // C0

		// members
		stl::enumeration<ImpactResult, std::int32_t> impactResult;                  // 280
		float                                        environmentTimer;              // 284
		float                                        coneSpreadTangent;             // 288
		float                                        initialCollisionSphereRadius;  // 28C
		Location                                     origin;                        // 290
		void*                                        collisionShape;                // 2A8
		BSTArray<std::int32_t>                       collisions;                    // 2B0
	};
	static_assert(sizeof(ConeProjectile) == 0x2C0);
}
