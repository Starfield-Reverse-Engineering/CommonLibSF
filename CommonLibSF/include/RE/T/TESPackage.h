#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class TESPackage : public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESPackage);
		SF_FORMTYPE(PACK);

		~TESPackage() override;  // 00
	};
	//static_assert(sizeof(TESPackage) == 0xE8);
}
