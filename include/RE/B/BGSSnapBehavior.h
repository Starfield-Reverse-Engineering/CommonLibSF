#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSKeyword;
	class BGSSnapTemplateNode;

	struct SNAP_BEHAVIOR_DATA
	{
	public:
		// members
		TESCondition         conditions;        // 00
		TESForm*             baseObject;        // 10
		BGSSnapTemplateNode* snapTemplateNode;  // 18
		BGSKeyword*          keyword;           // 20
		BSFixedString        unk28;             // 28
		std::uint32_t        unk30;             // 30
	};
	static_assert(sizeof(SNAP_BEHAVIOR_DATA) == 0x38);

	class BGSSnapBehavior : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSSnapBehavior);
		SF_FORMTYPE(STBH);

		~BGSSnapBehavior() override;  // 00

		// members
		BSTArray<SNAP_BEHAVIOR_DATA*> snapBehaviors;  // 30
	};
	static_assert(sizeof(BGSSnapBehavior) == 0x48);
}
