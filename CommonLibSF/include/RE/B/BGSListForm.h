#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSListForm :
		public TESForm  // 00
	{
	public:
		SF_RTTI_VTABLE(BGSListForm);
		SF_FORMTYPE(FLST);

		~BGSListForm() override;  // 00

		// members
		BSTArray<TESForm*>       arrayOfForms;          // 38
		std::uint64_t            unk48;                 // 48
		std::uint64_t            unk50;                 // 50
		std::uint64_t            unk58;                 // 58
		std::uint64_t            unk60;                 // 60
		std::uint64_t            unk68;                 // 68
		std::uint64_t            unk70;                 // 70
		std::uint64_t            unk78;                 // 78
		BSTArray<std::uint32_t>* scriptAddedTempForms;  // 80
		std::uint32_t            scriptAddedFormCount;  // 88
	};
	static_assert(sizeof(BGSListForm) == 0x90);
}
