#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class alignas(0x10) NiMatrix3
	{
	public:
		static const NiMatrix3 ZERO;
		static const NiMatrix3 IDENTITY;

		NiMatrix3() noexcept = default;
		NiMatrix3(const NiPoint4& a_point0, const NiPoint4& a_point1, const NiPoint4& a_point2) noexcept;
		NiMatrix3(
			float a_x0, float a_y0, float a_z0, float a_w0,
			float a_x1, float a_y1, float a_z1, float a_w1,
			float a_x2, float a_y2, float a_z2, float a_w2) noexcept;

		NiPoint4&       operator[](std::size_t a_pos) noexcept;
		const NiPoint4& operator[](std::size_t a_pos) const noexcept;
		bool            operator==(const NiMatrix3& a_rhs) const noexcept;
		bool            operator!=(const NiMatrix3& a_rhs) const noexcept;

		NiMatrix3 operator*(const NiMatrix3& a_rhs) const noexcept;
		NiMatrix3 operator*(float a_scalar) const noexcept;
		NiPoint3  operator*(const NiPoint3& a_rhs) const noexcept;

		void      MakeIdentity() noexcept;
		NiMatrix3 Transpose() const noexcept;

		bool ToEulerAnglesXYZ(NiPoint3& a_point) const;
		bool ToEulerAnglesXYZ(float& a_x, float& a_y, float& a_z) const;

		// members
		NiPoint4 entry[3];  // 00
	};
	static_assert(sizeof(NiMatrix3) == 0x30);
}

template <>
struct std::formatter<RE::NiMatrix3>
{
	template <class ParseContext>
	constexpr auto parse(ParseContext& a_ctx)
	{
		return a_ctx.begin();
	}

	template <class FormatContext>
	constexpr auto format(const RE::NiMatrix3& a_matrix, FormatContext& a_ctx) const
	{
		return format_to(a_ctx.out(), "[{}, {}, {}]", a_matrix[0], a_matrix[1], a_matrix[2]);
	}
};
