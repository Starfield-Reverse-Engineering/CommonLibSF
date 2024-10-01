#pragma once

#include "RE/B/BSTArray.h"
#include "RE/C/Color.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSCollisionLayer : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSCollisionLayer);
		SF_FORMTYPE(COLL);

		enum class Flag  // GNAM
		{
			kNone = 0,
			kTriggerVolume = 1 << 0,
			kSensor = 1 << 1,
			kNavmeshObstacle = 1 << 2
		};

		~BGSCollisionLayer() override;  // 00

		// members
		std::uint32_t                     collisionIdx;  // 30
		std::uint32_t                     debugColor;    // 34
		REX::EnumSet<Flag, std::uint32_t> flags;         // 38
		BSFixedString                     name;          // 40
		BSTArray<BGSCollisionLayer*>      collidesWith;  // 48
	};
	static_assert(sizeof(BGSCollisionLayer) == 0x60);
}
