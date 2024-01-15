#pragma once

namespace RE
{
	class BSFloatCurve
	{
	public:
		enum class CurveType
		{
			kLinear = 0,
			kQuadraticBezier,
			kCubicBezier,
			kQuadraticSpline,
			kCubicSpline
		};

		enum class Edge
		{
			kClamp = 0,
			kMirror,
			kRepeat
		};

		struct alignas(4) Control
		{
		public:
			// members
			float input;  // 00
			float value;  // 04
		};
		static_assert(sizeof(Control) == 0x8);

		// members
		std::uint64_t                             unk00;                  // 00
		std::vector<Control>                      controls;               // 08 - std::vector<BSFloatCurve::Control, BSTHeapAllocator<BSFloatCurve::Control, 2>>
		float                                     maxInput;               // 20
		float                                     minInput;               // 24
		float                                     inputDistance;          // 28
		float                                     maxValue;               // 2C
		float                                     minValue;               // 30
		float                                     defaultValue;           // 34
		stl::enumeration<CurveType, std::uint8_t> type;                   // 38
		stl::enumeration<Edge, std::uint8_t>      edge;                   // 39
		bool                                      isSampleInterpolating;  // 3A
	};
	static_assert(sizeof(BSFloatCurve) == 0x40);
}
