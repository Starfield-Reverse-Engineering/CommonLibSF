#pragma once

#include "RE/B/BGSCraftableForm.h"
#include "RE/B/BGSCraftingUseSound.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/B/BSTList.h"
#include "RE/T/TESValueForm.h"

namespace RE
{
	class TESBoundObject;
	class TESGlobal;

	class BGSConstructibleObject :
		public BGSCraftableForm,        // 000
		public BGSPickupPutdownSounds,  // 098
		public TESValueForm,            // 100
		public BGSCraftingUseSound      // 110
	{
	public:
		SF_RTTI_VTABLE(BGSConstructibleObject);
		SF_FORMTYPE(COBJ);

		enum class LEARN_METHOD
		{
			kPickupOrScript,
			kScrapping,
			kIngestion,
			kDefaultOrConditionsMet,
			kPlan
		};

		~BGSConstructibleObject() override;  // 00

		// members
		std::vector<BGSKeyword*>                                                        category;     // 148 - std::vector<BGSKeyword*, BSTHeapSTLAllocator<BGSKeyword, 2>
		TESBoundObject*                                                                 unk160;       // 160
		BGSCurveForm*                                                                   unk168;       // 168
		TESGlobal*                                                                      buildLimit;   // 170
		BSTArray<BSTTuple3<TESForm*, BGSCurveForm*, BGSTypedFormValuePair::SharedVal>>* unk178;       // 178
		REX::Enum<LEARN_METHOD, std::uint8_t>                                           learnMethod;  // 180
		TESGlobal*                                                                      unk188;       // 188
		BGSKeyword*                                                                     unk190;       // 190
		std::uint32_t                                                                   unk198;       // 198
	};
	static_assert(sizeof(BGSConstructibleObject) == 0x1A8);
}
