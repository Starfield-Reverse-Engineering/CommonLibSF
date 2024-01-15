#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class BGSSoundTagSet : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSSoundTagSet);
		SF_FORMTYPE(STAG);

		~BGSSoundTagSet() override;  // 00
	};
	//static_assert(sizeof(BGSSoundTagSet) == 0x88);
}
