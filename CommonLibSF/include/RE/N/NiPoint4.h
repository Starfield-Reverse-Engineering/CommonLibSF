#pragma once

namespace RE
{
	class NiPoint4
	{
	public:
		struct NiPoint4Struct
		{
		public:
			// members
			float x;  // 00
			float y;  // 04
			float z;  // 08
			float w;  // 0C
		};
		static_assert(sizeof(NiPoint4Struct) == 0x10);

		// members
		union
		{
			NiPoint4Struct v;
			float          pt[4]{ 0.0F };
		};  // 00

		float& operator[](size_t i) {
			assert(i < 4);
			return pt[i];
		}

		const float& operator[](size_t i) const
		{
			assert(i < 4);
			return pt[i];
		}
	};
	static_assert(sizeof(NiPoint4) == 0x10);
}
