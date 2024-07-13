#pragma once

#include "RE/P/Projectile.h"

namespace RE
{
	class BarrierProjectile : public Projectile
	{
	public:
		SF_RTTI_VTABLE(BarrierProjectile);
		SF_FORMTYPE(PBAR);

		struct CollisionData
		{
			std::uint32_t ref;    // 0 - TESPointerHandle
			std::uint32_t count;  // 4
		};
		static_assert(sizeof(CollisionData) == 0x8);

		~BarrierProjectile() override;  // 00

		// add
		virtual void Unk_15D();  // 15D

		// members
		float                   width;          // 260
		BSTArray<CollisionData> collisionData;  // 268
	};
	static_assert(sizeof(BarrierProjectile) == 0x260);
}
