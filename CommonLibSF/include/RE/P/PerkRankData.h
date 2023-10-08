#pragma once

namespace RE
{
	class BGSPerk;

	struct PerkRankData
	{
		// members
		BGSPerk*    perk;         // 00
		std::int8_t currentRank;  // 08
	};
	static_assert(sizeof(PerkRankData) == 0x10);
}
