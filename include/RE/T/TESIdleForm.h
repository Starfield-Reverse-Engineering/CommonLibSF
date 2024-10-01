#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class TESIdleForm : public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESIdleForm);
		SF_FORMTYPE(IDLE);

		~TESIdleForm() override;  // 00

		// members
		BGSEditorID   formEditorID;       // 30
		TESCondition  conditions;         // 40
		TESForm*      parentIdle;         // 50
		TESIdleForm*  prevIdle;           // 58
		BSFixedString behaviorGraphName;  // 60
		BSFixedString animEventName;      // 68
		BSFixedString animFileName;       // 70
		std::uint64_t unk78;              // 78
		std::uint8_t  unk80;              // 80
	};
	static_assert(sizeof(TESIdleForm) == 0x90);
}
