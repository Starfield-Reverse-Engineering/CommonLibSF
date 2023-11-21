#pragma once

#include "RE/P/Projectile.h"

namespace RE
{
	class MissileProjectile : public Projectile
	{
	public:
		SF_RTTI_VTABLE(MissileProjectile);
		SF_FORMTYPE(PMIS);

		~MissileProjectile() override;  // 00                                                                                                                                            // C0

		// add
		virtual bool ShouldReorient() const;  // 15D

		// members
		NiMatrix3                                    unk280;                 // 280
		NiPoint3                                     unk2B0;                 // 2B0
		std::uint32_t                                unk2BC;                 // 2BC
		NiPointer<bhkNPCollisionObject>              modelCollision;         // 2C0
		stl::enumeration<ImpactResult, std::int32_t> impactResult;           // 2C8
		bool                                         waitingToInitialize3D;  // 2CC
		bool                                         unk2CD;                 // 2CD
		bool                                         unk2CE;                 // 2CE
	};
	static_assert(sizeof(MissileProjectile) == 0x2D0);
}
