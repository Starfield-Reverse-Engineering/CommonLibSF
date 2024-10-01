#pragma once

#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSTerminalMenu :
		public TESForm,     // 00
		public TESFullName  // 30
	{
	public:
		SF_RTTI_VTABLE(BGSTerminalMenu);
		SF_FORMTYPE(TMLM);

		~BGSTerminalMenu() override;  // 00

		// members
		BSTArray<void*>    unk48;  // 40
		BSTArray<void*>    unk58;  // 50
		BGSLocalizedString unk60;  // 60
		std::uint64_t      unk68;  // 68
		std::uint64_t      unk70;  // 70
		std::uint32_t      unk78;  // 78
	};
	static_assert(sizeof(BGSTerminalMenu) == 0x88);
}
