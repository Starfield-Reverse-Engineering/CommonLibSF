#pragma once

namespace RE
{
	struct INTERIOR_DATA
	{
	public:
		// members
		std::uint32_t ambient;                // 00
		std::uint32_t directional;            // 04
		std::uint32_t fogColorNear;           // 08
		float         fogNear;                // 0C
		float         fogFar;                 // 10
		std::uint32_t directionalXY;          // 14
		std::uint32_t directionalZ;           // 18
		float         directionalFade;        // 1C
		float         clipDist;               // 20
		std::uint32_t fogPower;               // 24
		std::uint32_t fogColorFar;            // 28
		float         fogClamp;               // 2C
		float         lightFadeStart;         // 30
		float         lightFadeEnd;           // 34
		std::uint32_t unk38;                  // 38
		float         fogHeightMid;           // 3C
		float         fogHeightRange;         // 40
		std::uint32_t fogColorHighNear;       // 44
		std::uint32_t fogColorHighFar;        // 48
		float         fogHighDensityScale;    // 4C
		float         fogNearColorScale;      // 50
		float         fogFarColorScale;       // 54
		float         fogHighNearColorScale;  // 58
		float         fogHighFarColorScale;   // 5C
		float         fogFarHeightMid;        // 60
		float         fogFarHeightRange;      // 64
		std::int8_t   flags;                  // 68
		std::uint32_t unk6C;                  // 6C
		std::uint64_t unk70;                  // 70
	};
	static_assert(sizeof(INTERIOR_DATA) == 0x78);
}
