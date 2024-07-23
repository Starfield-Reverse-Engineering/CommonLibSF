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

		~EmitterProjectile() override;  // 00

		// members
		std::int32_t                              unk260;  // 260
		BSTSmartPointer<Particles::SystemBinding> unk268;  // 268
		BSTSmartPointer<Particles::SystemBinding> unk270;  // 270
		BSTSmartPointer<Particles::SystemBinding> unk278;  // 278
		bool                                      unk280;  // 280
		bool                                      unk281;  // 281
		std::uint64_t                             unk288;  // 288
		std::uint64_t                             unk290;  // 290
		std::uint64_t                             unk298;  // 298
		std::uint64_t                             unk2A0;  // 2A0
		std::uint64_t                             unk2A8;  // 2A8
	};
	static_assert(sizeof(EmitterProjectile) == 0x290);
}
