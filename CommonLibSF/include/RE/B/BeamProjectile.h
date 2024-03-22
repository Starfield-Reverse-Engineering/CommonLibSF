#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/F/FormTypes.h"
#include "RE/P/Projectile.h"

namespace RE
{
	class BSProceduralGeomEvent;
	struct BeamProjectileImpactEvent;

	class BeamProjectile :
		public Projectile,                                 // 000
		public BSTEventSource<BeamProjectileImpactEvent>,  // 280
		public BSTEventSink<BSProceduralGeomEvent>         // 2A8
	{
	public:
		SF_RTTI_VTABLE(BeamProjectile);
		SF_FORMTYPE(PBEA);

		~BeamProjectile() override;  // 00

		// members
		void*                unk290;      // 290 - smart ptr
		std::uint64_t        unk298;      // 298
		ProjectileLaunchData launchData;  // 2A0
		std::uint64_t        unk390;      // 390
		std::uint64_t        unk3A0;      // 3A0
		void*                unk3A8;      // 3A8 - smart ptr
		std::uint32_t        unk3B0;      // 3B0
		std::uint8_t         unk3B4;      // 3B4
		std::uint8_t         unk3B5;      // 3B5
		std::uint8_t         unk3B6;      // 3B6
	};
	static_assert(sizeof(BeamProjectile) == 0x3A0);
}
