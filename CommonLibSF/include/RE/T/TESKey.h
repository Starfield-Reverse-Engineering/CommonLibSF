#pragma once

#include "RE/T/TESObjectMisc.h"

namespace RE
{
	class TESKey : public TESObjectMISC
	{
	public:
		SF_RTTI_VTABLE(TESKey);
		SF_FORMTYPE(KEYM);

		~TESKey() override;  // 00
	};
	static_assert(sizeof(TESKey) == 0x290);
}
