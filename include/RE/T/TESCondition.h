#pragma once

namespace RE
{
	class TESConditionItem;

	class TESCondition
	{
	public:
		// members
		std::uint8_t      unk0;  // 0
		TESConditionItem* head;  // 8
	};
	static_assert(sizeof(TESCondition) == 0x10);
}
