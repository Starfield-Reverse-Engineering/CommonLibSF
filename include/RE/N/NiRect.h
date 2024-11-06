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

template <class T>
struct std::formatter<RE::NiRect<T>>
{
	template <class ParseContext>
	constexpr auto parse(ParseContext& a_ctx)
	{
		return a_ctx.begin();
	}

	template <class FormatContext>
	constexpr auto format(const RE::NiRect<T>& a_rect, FormatContext& a_ctx) const
	{
		return format_to(a_ctx.out(), "({}, {}, {}, {})", a_rect.left, a_rect.right, a_rect.top, a_rect.bottom);
	}
};
