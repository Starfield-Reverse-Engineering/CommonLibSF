
#pragma once

namespace RE
{
	class BSTimer
	{
	public:
		// members
		std::uint64_t unk00;                          // 00
		std::int64_t  highPrecisionInitTime;          // 08
		float         clamp;                          // 10
		float         clampRemainder;                 // 14
		float         delta;                          // 18
		float         realTimeDelta;                  // 1C
		std::uint64_t diffLastUpdate;                 // 20
		std::uint64_t lastTime;                       // 28
		std::uint64_t lastUpdate;                     // 30
		std::uint64_t firstTime;                      // 38
		std::uint64_t disabledLastTime;               // 40
		std::uint64_t disabledFirstTime;              // 48
		std::uint32_t disableCounter;                 // 50
		float         cumulutiveDelta;                // 54
		bool          useGlobalTimeMultiplierTarget;  // 58
		std::uint8_t  unk59;                          // 59
		std::uint8_t  unk5A;                          // 5A
	};
	static_assert(sizeof(BSTimer) == 0x60);
}
