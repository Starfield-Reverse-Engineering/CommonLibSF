#pragma once

namespace RE
{
	class NiFrustum
	{
	public:
		float left{ 0.0f };  // 00
		float right;         // 04
		float top{ 0.0f };   // 08
		float bottom;        // 0C
		float near{ 0.0f };  // 10
		float far;           // 14
		bool  ortho;         // 18
	};
	static_assert(sizeof(NiFrustum) == 0x1C);
}
