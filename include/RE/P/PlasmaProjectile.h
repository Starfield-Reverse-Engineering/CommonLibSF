#pragma once

#include "RE/C/ConeProjectile.h"

namespace RE
{
	class PlasmaProjectile : public ConeProjectile
	{
	public:
		SF_RTTI_VTABLE(PlasmaProjectile);
		SF_FORMTYPE(PPLA);

		~PlasmaProjectile() override;  // 00
	};
	static_assert(sizeof(PlasmaProjectile) == 0x290);
}
