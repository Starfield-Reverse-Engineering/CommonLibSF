#pragma once

namespace RE
{
	class EffectSetting;
	class TESGlobal;

	struct EffectItemData
	{
	public:
		// members
		float        magnitude;  // 0
		float        area;       // 4
		std::int32_t duration;   // 8
	};
	static_assert(sizeof(EffectItemData) == 0xC);

	class EffectItem
	{
	public:
		// members
		EffectItemData data;            // 00
		EffectSetting* effectSetting;   // 10
		TESGlobal*     magGlobal;       // 18
		TESGlobal*     areaGlobal;      // 20
		TESGlobal*     durationGlobal;  // 28
		std::uint32_t  unk30;           // 30
		std::uint32_t  unk34;           // 34
		float          rawCost;         // 38
		std::uint64_t  conditions[2];   // 40 - TESCondition
	};
	static_assert(sizeof(EffectItem) == 0x50);
}
