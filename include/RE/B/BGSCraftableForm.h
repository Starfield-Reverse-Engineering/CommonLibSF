#pragma once

#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple3.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSCurveForm;
	class BGSKeyword;

	class BGSCraftableForm :
		public TESForm,         // 00
		public TESDescription,  // 30
		public TESFullName      // 48
	{
	public:
		SF_RTTI_VTABLE(BGSCraftableForm);

		~BGSCraftableForm() override;  // 00

		// add
		virtual void Unk_62();  // 62

		// members
		BGSKeyword*                                                                     benchKeyword;   // 58
		TESCondition                                                                    conditions;     // 60
		BSTArray<BSTTuple3<TESForm*, BGSCurveForm*, BGSTypedFormValuePair::SharedVal>>* components;     // 70
		BSTArray<BSTTuple3<TESForm*, BGSCurveForm*, BGSTypedFormValuePair::SharedVal>>* requiredPerks;  // 78
		TESForm*                                                                        createdObject;  // 80
		std::uint8_t                                                                    unk88;          // 88
		float                                                                           menuSortOrder;  // 8C
		std::uint8_t                                                                    unk90;          // 90
	};
	static_assert(sizeof(BGSCraftableForm) == 0xA0);
}
