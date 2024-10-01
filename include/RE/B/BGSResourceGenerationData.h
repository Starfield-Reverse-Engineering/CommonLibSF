#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSResourceGenerationData : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSResourceGenerationData);
		SF_FORMTYPE(RSGD);

		~BGSResourceGenerationData() override;  // 00

		// members
		BSTArray<void*> unk30;  // 30
	};
	static_assert(sizeof(BGSResourceGenerationData) == 0x48);
}
