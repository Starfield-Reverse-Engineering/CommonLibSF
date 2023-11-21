#pragma once

#include "RE/P/Projectile.h"

namespace RE
{
	namespace Particles
	{
		class SystemBinding;
	}

	class EmitterProjectile : public Projectile
	{
	public:
		SF_RTTI_VTABLE(EmitterProjectile);
		SF_FORMTYPE(PEMI);

		~EmitterProjectile() override;  // 00                                                                                                                                    // C1

		// members
		std::int32_t                              unk280;  // 280
		BSTSmartPointer<Particles::SystemBinding> unk288;  // 288
		BSTSmartPointer<Particles::SystemBinding> unk290;  // 290
		BSTSmartPointer<Particles::SystemBinding> unk298;  // 298
		bool                                      unk2A0;  // 2A0
		bool                                      unk2A1;  // 2A1
		std::uint64_t                             unk2A8;  // 2A8
		std::uint64_t                             unk2B0;  // 2B0
		std::uint64_t                             unk2B8;  // 2B8
		std::uint64_t                             unk2C0;  // 2C0
		std::uint64_t                             unk2C8;  // 2C8
	};
	static_assert(sizeof(EmitterProjectile) == 0x2D0);
}
