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
		void*                unk2B0;      // 2B0 - smart ptr
		std::uint64_t        unk2B8;      // 2B8
		ProjectileLaunchData launchData;  // 2C0
		std::uint64_t        unk3B0;      // 3B0
		std::uint64_t        unk3C0;      // 3C0
		void*                unk3C8;      // 3C8 - smart ptr
		std::uint32_t        unk3D0;      // 3D0
		std::uint8_t         unk3D4;      // 3D4
		std::uint8_t         unk3D5;      // 3D5
		std::uint8_t         unk3D6;      // 3D6
	};
	static_assert(sizeof(BeamProjectile) == 0x3E0);
}
