#pragma once

#include "RE/N/NiPoint4.h"

namespace RE
{
	class alignas(0x10) NiMatrix3
	{
	public:
		void MakeIdentity() noexcept
		{
			entry[0].v = { 1.0F, 0.0F, 0.0F, 0.0F };
			entry[1].v = { 0.0F, 1.0F, 0.0F, 0.0F };
			entry[2].v = { 0.0F, 0.0F, 1.0F, 0.0F };
		}

		NiMatrix3 operator*(const NiMatrix3& rhs) const
		{
			NiMatrix3 tmp;
			tmp.entry[0].pt[0] =
				entry[0].pt[0] * rhs.entry[0].pt[0] +
				entry[0].pt[1] * rhs.entry[1].pt[0] +
				entry[0].pt[2] * rhs.entry[2].pt[0];
			tmp.entry[1].pt[0] =
				entry[1].pt[0] * rhs.entry[0].pt[0] +
				entry[1].pt[1] * rhs.entry[1].pt[0] +
				entry[1].pt[2] * rhs.entry[2].pt[0];
			tmp.entry[2].pt[0] =
				entry[2].pt[0] * rhs.entry[0].pt[0] +
				entry[2].pt[1] * rhs.entry[1].pt[0] +
				entry[2].pt[2] * rhs.entry[2].pt[0];
			tmp.entry[0].pt[1] =
				entry[0].pt[0] * rhs.entry[0].pt[1] +
				entry[0].pt[1] * rhs.entry[1].pt[1] +
				entry[0].pt[2] * rhs.entry[2].pt[1];
			tmp.entry[1].pt[1] =
				entry[1].pt[0] * rhs.entry[0].pt[1] +
				entry[1].pt[1] * rhs.entry[1].pt[1] +
				entry[1].pt[2] * rhs.entry[2].pt[1];
			tmp.entry[2].pt[1] =
				entry[2].pt[0] * rhs.entry[0].pt[1] +
				entry[2].pt[1] * rhs.entry[1].pt[1] +
				entry[2].pt[2] * rhs.entry[2].pt[1];
			tmp.entry[0].pt[2] =
				entry[0].pt[0] * rhs.entry[0].pt[2] +
				entry[0].pt[1] * rhs.entry[1].pt[2] +
				entry[0].pt[2] * rhs.entry[2].pt[2];
			tmp.entry[1].pt[2] =
				entry[1].pt[0] * rhs.entry[0].pt[2] +
				entry[1].pt[1] * rhs.entry[1].pt[2] +
				entry[1].pt[2] * rhs.entry[2].pt[2];
			tmp.entry[2].pt[2] =
				entry[2].pt[0] * rhs.entry[0].pt[2] +
				entry[2].pt[1] * rhs.entry[1].pt[2] +
				entry[2].pt[2] * rhs.entry[2].pt[2];
			return tmp;
		}

		NiMatrix3 operator*(float scalar) const
		{
			NiMatrix3 result;
			result.entry[0].pt[0] = entry[0].pt[0] * scalar;
			result.entry[0].pt[1] = entry[0].pt[1] * scalar;
			result.entry[0].pt[2] = entry[0].pt[2] * scalar;
			result.entry[1].pt[0] = entry[1].pt[0] * scalar;
			result.entry[1].pt[1] = entry[1].pt[1] * scalar;
			result.entry[1].pt[2] = entry[1].pt[2] * scalar;
			result.entry[2].pt[0] = entry[2].pt[0] * scalar;
			result.entry[2].pt[1] = entry[2].pt[1] * scalar;
			result.entry[2].pt[2] = entry[2].pt[2] * scalar;
			return result;
		}

		NiPoint3 operator*(const NiPoint3& p) const
		{
			return NiPoint3(
				entry[0].pt[0] * p.x + entry[0].pt[1] * p.y + entry[0].pt[2] * p.z,
				entry[1].pt[0] * p.x + entry[1].pt[1] * p.y + entry[1].pt[2] * p.z,
				entry[2].pt[0] * p.x + entry[2].pt[1] * p.y + entry[2].pt[2] * p.z);
		}

		RE::NiPoint4& operator[](size_t i)
		{
			assert(i < 3);
			return entry[i];
		}

		const RE::NiPoint4& operator[](size_t i) const
		{
			assert(i < 3);
			return entry[i];
		}

		bool ToEulerAnglesXYZ(float& a_x, float& a_y, float& a_z)
		{
			using func_t = decltype(&NiMatrix3::ToEulerAnglesXYZ);
			REL::Relocation<func_t> func{ ID::NiMatrix3::ToEulerAnglesXYZ };
			return func(this, a_x, a_y, a_z);
		}

		NiMatrix3 Transpose() const
		{
			NiMatrix3 result;
			result.entry[0].pt[0] = entry[0].pt[0];
			result.entry[0].pt[1] = entry[1].pt[0];
			result.entry[0].pt[2] = entry[2].pt[0];
			result.entry[1].pt[0] = entry[0].pt[1];
			result.entry[1].pt[1] = entry[1].pt[1];
			result.entry[1].pt[2] = entry[2].pt[1];
			result.entry[2].pt[0] = entry[0].pt[2];
			result.entry[2].pt[1] = entry[1].pt[2];
			result.entry[2].pt[2] = entry[2].pt[2];
			return result;
		}

		// members
		NiPoint4 entry[3];  // 00
	};
	static_assert(sizeof(NiMatrix3) == 0x30);
}
