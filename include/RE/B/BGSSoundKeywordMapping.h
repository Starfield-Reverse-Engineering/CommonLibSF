#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class BGSSoundKeywordMapping : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSSoundKeywordMapping);
		SF_FORMTYPE(KSSM);

		~BGSSoundKeywordMapping() override;  // 00
	};
	//static_assert(sizeof(BGSSoundKeywordMapping) == 0xE0);
}
