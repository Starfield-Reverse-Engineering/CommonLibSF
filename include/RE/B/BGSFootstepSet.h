#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSFootstep;

	struct ACTOR_MOVEMENT_TYPES
	{
		enum ACTOR_MOVEMENT_TYPE : std::uint32_t
		{
			kWalk = 0,
			kRun = 1,
			kSneak = 2,
			kBleedout = 3,
			kSwim = 4,

			kTotal = 5
		};
	};
	using ACTOR_MOVEMENT_TYPE = ACTOR_MOVEMENT_TYPES::ACTOR_MOVEMENT_TYPE;

	class BGSFootstepSet : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSFootstepSet);
		SF_FORMTYPE(FSTS);

		~BGSFootstepSet() override;  // 00

		// members
		BSTArray<BGSFootstep*> entries[ACTOR_MOVEMENT_TYPES::kTotal];  // 30
	};
	static_assert(sizeof(BGSFootstepSet) == 0x88);
}
