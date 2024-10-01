#pragma once

#include "RE/P/Projectile.h"

namespace RE
{
	class FlameProjectile : public Projectile
	{
	public:
		SF_RTTI_VTABLE(FlameProjectile);
		SF_FORMTYPE(PFLA);

		~FlameProjectile() override;  // 00

		// members
		float expirationTimer;  // 260
		float coneAngle;        // 264
	};
	static_assert(sizeof(FlameProjectile) == 0x260);

}
