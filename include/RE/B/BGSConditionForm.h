#pragma once

#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class TESQuest;
	class TESPackage;

	class BGSConditionForm : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSConditionForm);
		SF_FORMTYPE(CNDF);

		~BGSConditionForm() override;  // 00

		// members
		TESCondition  conditions;  // 30
		TESQuest*     quest;       // 40
		TESPackage*   package;     // 48
		std::uint32_t unk50;       // 50
		std::uint8_t  unk54;       // 54
	};
	static_assert(sizeof(BGSConditionForm) == 0x60);
}
