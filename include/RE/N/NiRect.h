#pragma once

namespace RE
{
	template <class T>
	class NiRect
	{
	public:
		T left;    // 00
		T right;   // ??
		T top;     // ??
		T bottom;  // ??
	};

	static_assert(sizeof(NiRect<float>) == 0x10);
	static_assert(sizeof(NiRect<std::int32_t>) == 0x10);
	static_assert(sizeof(NiRect<std::uint32_t>) == 0x10);
}
