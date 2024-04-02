#pragma once

#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple3.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/F/FormTypes.h"
#include "RE/T/TESCondition.h"

namespace RE
{
	class BGSCurveForm;
	class BGSBiome;
	class TESForm;
	class TESGlobal;

	struct ContainerItemExtra;

	struct LEVELED_OBJECT
	{
	public:
		SF_HEAP_REDEFINE_NEW(LEVELED_OBJECT);

		// members
		TESForm*            form;        // 00
		ContainerItemExtra* itemExtra;   // 08
		TESCondition*       conditions;  // 10
		std::uint16_t       count;       // 18
		std::uint16_t       level;       // 1A
		std::uint8_t        chanceNone;  // 1C
		std::uint8_t        unk1D;       // 1D
	};
	static_assert(sizeof(LEVELED_OBJECT) == 0x20);

	class TESLeveledList : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESLeveledList);

		enum Flag : std::uint8_t  // LVLF
		{
			kCalculateFromAllLevelsLTOrEqPCLevel = 1 << 0,
			kCalculateForEachItemInCount = 1 << 1,
			kUseAll = 1 << 2,
			kSpecialLoot = 1 << 3
		};

		~TESLeveledList() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESLeveledList_Component"; }
		void                 InitializeDataComponent() override;     // 02

		// add
		virtual std::int32_t GetMaxLevelDifference();                              // 0B
		virtual bool         GetCanHoldForm(TESForm* a_form);                      // 0C
		virtual void         Unk_0D();                                             // 0D
		virtual void         Unk_0E();                                             // 0E
		virtual void         Unk_0F();                                             // 0F
		virtual bool         GetCanContainFormsOfType(FormType a_type) const = 0;  // 10

		// members
		TESCondition                                                                   conditions;        // 08
		TESGlobal*                                                                     chanceGlobal;      // 10
		BGSBiome*                                                                      biome;             // 20 ??
		TESForm*                                                                       unk28;             // 28
		BSTArray<BSTTuple3<TESForm*, BGSCurveForm, BGSTypedFormValuePair::SharedVal>>* keywordChances;    // 30
		LEVELED_OBJECT*                                                                leveledLists;      // 38
		LEVELED_OBJECT**                                                               scriptAddedLists;  // 40
		std::int8_t                                                                    scriptListCount;   // 48
		std::uint32_t                                                                  unk4C;             // 4C
		stl::enumeration<Flag, std::uint8_t>                                           flags;             // 50
		std::uint8_t                                                                   unk51;             // 51
		std::uint8_t                                                                   baseListCount;     // 52
		std::uint8_t                                                                   unk53;             // 53
		std::uint8_t                                                                   unk54;             // 54
		BSFixedString                                                                  overrideName;      // 58
	};
	static_assert(sizeof(TESLeveledList) == 0x60);
}
