#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class BGSImpactDataSet;

	class BGSFootstep : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSFootstep);
		SF_FORMTYPE(FSTP);

		~BGSFootstep() override;  // 00

		// members
		BSFixedString     tag;        // 30 - ANAM
		BGSImpactDataSet* impactSet;  // 38 - DATA
	};
	static_assert(sizeof(BGSFootstep) == 0x40);
}
