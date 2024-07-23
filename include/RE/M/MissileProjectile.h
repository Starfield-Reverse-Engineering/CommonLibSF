#pragma once

#include "RE/P/Projectile.h"

namespace RE
{
	class MissileProjectile : public Projectile
	{
	public:
		SF_RTTI_VTABLE(MissileProjectile);
		SF_FORMTYPE(PMIS);

		~MissileProjectile() override;  // 00

		// add
		virtual bool ShouldReorient() const;  // 15D

		// members
		NiMatrix3                                    unk260;                 // 260
		NiPoint3                                     unk290;                 // 290
		std::uint32_t                                unk29C;                 // 29C
		NiPointer<bhkNPCollisionObject>              modelCollision;         // 2A0
		stl::enumeration<ImpactResult, std::int32_t> impactResult;           // 2A8
		bool                                         waitingToInitialize3D;  // 2AC
		bool                                         unk2AD;                 // 2AD
		bool                                         unk2AE;                 // 2AE
		void*                                        unk2AF;
		void*                                        unk2B7;
	};
	static_assert(sizeof(MissileProjectile) == 0x2A0);
}
