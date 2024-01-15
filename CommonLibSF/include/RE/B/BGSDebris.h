#pragma once

#include "RE/B/BGSPreloadable.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTList.h"
#include "RE/T/TESForm.h"

namespace RE
{
	struct BGSDebrisData
	{
	public:
		// members
		BSTArray<void*>         unk00;  // 00
		BSTArray<std::uint32_t> unk10;  // 10
		std::uint64_t           unk20;  // 20
		BSFixedString           unk28;  // 28
	};
	static_assert(sizeof(BGSDebrisData) == 0x30);

	class BGSDebris :
		public TESForm,        // 00
		public BGSPreloadable  // 30
	{
	public:
		SF_RTTI_VTABLE(BGSDebris);
		SF_FORMTYPE(DEBR);

		~BGSDebris() override;  // 00

		// members
		BSSimpleList<BGSDebrisData*> data;  // 38
	};
	static_assert(sizeof(BGSDebris) == 0x48);
}
