#pragma once

namespace RE
{
	struct ConditionCheckParams;

	enum class ENUM_COMPARISION_CONDITION : std::int32_t
	{
		kEqual = 0,                 // ==
		kNotEqual = 1,              // !=
		kGreaterThan = 2,           // >
		kGreaterThanOrEqualTo = 3,  // >=
		kLessThan = 4,              // <
		kLessThanOrEqualTo = 5,     // <=
	};

	class TESConditionItem
	{
	public:
		bool IsTrue(ConditionCheckParams& a_params) const
		{
			using func_t = decltype(&TESConditionItem::IsTrue);
			static REL::Relocation<func_t> func{ ID::TESConditionItem::IsTrue };
			return func(this, a_params);
		}

		bool operator()(ConditionCheckParams& a_params) const
		{
			return IsTrue(a_params);
		}

		// members
		TESConditionItem* next{ nullptr };
		//...
	};

	class TESCondition
	{
	public:
		static bool CheckValue(ENUM_COMPARISION_CONDITION a_comparison, float a_valueA, float a_valueB)
		{
			using func_t = decltype(&TESCondition::CheckValue);
			static REL::Relocation<func_t> func{ ID::TESCondition::CheckValue };
			return func(a_comparison, a_valueA, a_valueB);
		}

		// members
		std::uint8_t      unk0;  // 0
		TESConditionItem* head;  // 8
	};
	static_assert(sizeof(TESCondition) == 0x10);
}
