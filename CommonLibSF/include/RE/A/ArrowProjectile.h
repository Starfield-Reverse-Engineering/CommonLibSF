#pragma once

#include "RE/M/MissileProjectile.h"

namespace RE
{
	class AlchemyItem;

	class ArrowProjectile : public MissileProjectile
	{
	public:
		SF_RTTI_VTABLE(ArrowProjectile);
		SF_FORMTYPE(PARW);

		~ArrowProjectile() override;  // 00

		// members
		AlchemyItem* poison;  // 2B0
	};
	static_assert(sizeof(ArrowProjectile) == 0x2C0);
}
