#pragma once

#include "RE/B/BGSReflectedForm.h"

namespace RE
{
	class BGSChallengeForm : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSChallengeForm);
		SF_FORMTYPE(CHAL);

		~BGSChallengeForm() override;  // 00
	};
	static_assert(sizeof(BGSChallengeForm) == 0x30);
}
