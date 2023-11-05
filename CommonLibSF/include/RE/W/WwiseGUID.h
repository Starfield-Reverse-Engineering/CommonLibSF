#pragma once

namespace RE::BGSAudio
{
	class WwiseGUID
	{
	public:
		// members
		std::uint64_t highGUID;  // 00
		std::uint64_t lowGUID;   // 08
	};
	static_assert(sizeof(WwiseGUID) == 0x10);
}
