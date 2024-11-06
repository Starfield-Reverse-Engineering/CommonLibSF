#include "RE/N/NiPoint.h"

namespace RE
{
	const NiPoint2 NiPoint2::ZERO = { 0.0F, 0.0F };

	NiPoint2::NiPoint2(float a_x, float a_y) noexcept :
		x(a_x), y(a_y)
	{}

	float& NiPoint2::operator[](std::size_t a_pos) noexcept
	{
		assert(a_pos < 2);
		return std::addressof(x)[a_pos];
	}

	const float& NiPoint2::operator[](std::size_t a_pos) const noexcept
	{
		assert(a_pos < 2);
		return std::addressof(x)[a_pos];
	}

	bool NiPoint2::operator==(const NiPoint2& a_rhs) const noexcept
	{
		return (x == a_rhs.x) && (y == a_rhs.y);
	}

	bool NiPoint2::operator!=(const NiPoint2& a_rhs) const noexcept
	{
		return !operator==(a_rhs);
	}

	bool NiPoint2::operator<(const NiPoint2& a_rhs) const noexcept
	{
		return std::tie(x, y) < std::tie(a_rhs.x, a_rhs.y);
	}

	bool NiPoint2::operator>(const NiPoint2& a_rhs) const noexcept
	{
		return std::tie(x, y) > std::tie(a_rhs.x, a_rhs.y);
	}

	NiPoint2 NiPoint2::operator+(const NiPoint2& a_rhs) const noexcept
	{
		return NiPoint2(x + a_rhs.x, y + a_rhs.y);
	}

	NiPoint2 NiPoint2::operator-(const NiPoint2& a_rhs) const noexcept
	{
		return NiPoint2(x - a_rhs.x, y - a_rhs.y);
	}

	NiPoint2 NiPoint2::operator*(const NiPoint2& a_rhs) const noexcept
	{
		return NiPoint2(x * a_rhs.x, y * a_rhs.y);
	}

	NiPoint2 NiPoint2::operator/(const NiPoint2& a_rhs) const noexcept
	{
		return NiPoint2(x / a_rhs.x, y / a_rhs.y);
	}

	NiPoint2 NiPoint2::operator*(float a_scalar) const noexcept
	{
		return NiPoint2(x * a_scalar, y * a_scalar);
	}

	NiPoint2 NiPoint2::operator/(float a_scalar) const noexcept
	{
		return NiPoint2(x / a_scalar, y / a_scalar);
	}

	NiPoint2 NiPoint2::operator-() const noexcept
	{
		return NiPoint2(-x, -y);
	}

	NiPoint2& NiPoint2::operator+=(const NiPoint2& a_rhs) noexcept
	{
		x += a_rhs.x;
		y += a_rhs.y;
		return *this;
	}

	NiPoint2& NiPoint2::operator-=(const NiPoint2& a_rhs) noexcept
	{
		x -= a_rhs.x;
		y -= a_rhs.y;
		return *this;
	}

	NiPoint2& NiPoint2::operator*=(const NiPoint2& a_rhs) noexcept
	{
		x *= a_rhs.x;
		y *= a_rhs.y;
		return *this;
	}

	NiPoint2& NiPoint2::operator/=(const NiPoint2& a_rhs) noexcept
	{
		x /= a_rhs.x;
		y /= a_rhs.y;
		return *this;
	}

	NiPoint2& NiPoint2::operator+=(float a_scalar) noexcept
	{
		x += a_scalar;
		y += a_scalar;
		return *this;
	}

	NiPoint2& NiPoint2::operator-=(float a_scalar) noexcept
	{
		x -= a_scalar;
		y -= a_scalar;
		return *this;
	}

	NiPoint2& NiPoint2::operator*=(float a_scalar) noexcept
	{
		x *= a_scalar;
		y *= a_scalar;
		return *this;
	}

	NiPoint2& NiPoint2::operator/=(float a_scalar) noexcept
	{
		x /= a_scalar;
		y /= a_scalar;
		return *this;
	}
}

namespace RE
{
	const NiPoint3  NiPoint3::ZERO = { 0.0F, 0.0F, 0.0F };
	const NiPoint3A NiPoint3A::ZERO = { 0.0F, 0.0F, 0.0F };

	NiPoint3::NiPoint3(const NiPoint2& a_point) noexcept :
		x(a_point.x), y(a_point.y)
	{}

	NiPoint3::NiPoint3(float a_x, float a_y, float a_z) noexcept :
		x(a_x), y(a_y), z(a_z)
	{}

	float& NiPoint3::operator[](std::size_t a_pos) noexcept
	{
		assert(a_pos < 3);
		return std::addressof(x)[a_pos];
	}

	const float& NiPoint3::operator[](std::size_t a_pos) const noexcept
	{
		assert(a_pos < 3);
		return std::addressof(x)[a_pos];
	}

	bool NiPoint3::operator==(const NiPoint3& a_rhs) const noexcept
	{
		return (x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z);
	}

	bool NiPoint3::operator!=(const NiPoint3& a_rhs) const noexcept
	{
		return !operator==(a_rhs);
	}

	bool NiPoint3::operator<(const NiPoint3& a_rhs) const noexcept
	{
		return std::tie(x, y, z) < std::tie(a_rhs.x, a_rhs.y, a_rhs.z);
	}

	bool NiPoint3::operator>(const NiPoint3& a_rhs) const noexcept
	{
		return std::tie(x, y, z) > std::tie(a_rhs.x, a_rhs.y, a_rhs.z);
	}

	NiPoint3 NiPoint3::operator+(const NiPoint3& a_rhs) const noexcept
	{
		return NiPoint3(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
	}

	NiPoint3 NiPoint3::operator-(const NiPoint3& a_rhs) const noexcept
	{
		return NiPoint3(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
	}

	NiPoint3 NiPoint3::operator*(const NiPoint3& a_rhs) const noexcept
	{
		return NiPoint3(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z);
	}

	NiPoint3 NiPoint3::operator/(const NiPoint3& a_rhs) const noexcept
	{
		return NiPoint3(x / a_rhs.x, y / a_rhs.y, z / a_rhs.z);
	}

	NiPoint3 NiPoint3::operator*(float a_scalar) const noexcept
	{
		return NiPoint3(x * a_scalar, y * a_scalar, z * a_scalar);
	}

	NiPoint3 NiPoint3::operator/(float a_scalar) const noexcept
	{
		return NiPoint3(x / a_scalar, y / a_scalar, z / a_scalar);
	}

	NiPoint3 NiPoint3::operator-() const noexcept
	{
		return NiPoint3(-x, -y, -z);
	}

	NiPoint3& NiPoint3::operator+=(const NiPoint3& a_rhs) noexcept
	{
		x += a_rhs.x;
		y += a_rhs.y;
		z += a_rhs.z;
		return *this;
	}

	NiPoint3& NiPoint3::operator-=(const NiPoint3& a_rhs) noexcept
	{
		x -= a_rhs.x;
		y -= a_rhs.y;
		z -= a_rhs.z;
		return *this;
	}

	NiPoint3& NiPoint3::operator*=(const NiPoint3& a_rhs) noexcept
	{
		x *= a_rhs.x;
		y *= a_rhs.y;
		z *= a_rhs.z;
		return *this;
	}

	NiPoint3& NiPoint3::operator/=(const NiPoint3& a_rhs) noexcept
	{
		x /= a_rhs.x;
		y /= a_rhs.y;
		z /= a_rhs.z;
		return *this;
	}

	NiPoint3& NiPoint3::operator+=(float a_scalar) noexcept
	{
		x += a_scalar;
		y += a_scalar;
		z += a_scalar;
		return *this;
	}

	NiPoint3& NiPoint3::operator-=(float a_scalar) noexcept
	{
		x -= a_scalar;
		y -= a_scalar;
		z -= a_scalar;
		return *this;
	}

	NiPoint3& NiPoint3::operator*=(float a_scalar) noexcept
	{
		x *= a_scalar;
		y *= a_scalar;
		z *= a_scalar;
		return *this;
	}

	NiPoint3& NiPoint3::operator/=(float a_scalar) noexcept
	{
		x /= a_scalar;
		y /= a_scalar;
		z /= a_scalar;
		return *this;
	}

	NiPoint3 NiPoint3::Cross(const NiPoint3& a_point) const noexcept
	{
		return NiPoint3(
			y * a_point.z - z * a_point.y,
			z * a_point.x - x * a_point.z,
			x * a_point.y - y * a_point.x);
	}

	float NiPoint3::Dot(const NiPoint3& a_point) const noexcept
	{
		return x * a_point.x + y * a_point.y + z * a_point.z;
	}

	float NiPoint3::GetDistance(const NiPoint3& a_point) const noexcept
	{
		return std::sqrtf(GetSquaredDistance(a_point));
	}

	float NiPoint3::GetSquaredDistance(const NiPoint3& a_point) const noexcept
	{
		const float dx = a_point.x - x;
		const float dy = a_point.y - y;
		const float dz = a_point.z - z;
		return dx * dx + dy * dy + dz * dz;
	}

	float NiPoint3::Length() const noexcept
	{
		return std::sqrtf(x * x + y * y + z * z);
	}

	float NiPoint3::SqrLength() const noexcept
	{
		return x * x + y * y + z * z;
	}

	NiPoint3 NiPoint3::UnitCross(const NiPoint3& a_point) const noexcept
	{
		auto cross = Cross(a_point);
		cross.Unitize();
		return cross;
	}

	float NiPoint3::Unitize() noexcept
	{
		auto length = Length();
		if (length == 1.f) {
			return length;
		} else if (length > FLT_EPSILON) {
			operator/=(length);
		} else {
			x = 0.0;
			y = 0.0;
			z = 0.0;
			length = 0.0;
		}
		return length;
	}
}

namespace RE
{
	const NiPoint4 NiPoint4::ZERO = { 0.0F, 0.0F, 0.0F, 0.0F };
	const NiPoint4 NiPoint4::IDENTITY0 = { 1.0F, 0.0F, 0.0F, 0.0F };
	const NiPoint4 NiPoint4::IDENTITY1 = { 0.0F, 1.0F, 0.0F, 0.0F };
	const NiPoint4 NiPoint4::IDENTITY2 = { 0.0F, 0.0F, 1.0F, 0.0F };
	const NiPoint4 NiPoint4::IDENTITY3 = { 0.0F, 0.0F, 0.0F, 1.0F };

	NiPoint4::NiPoint4(const NiPoint2& a_point) noexcept :
		x(a_point.x), y(a_point.y)
	{}

	NiPoint4::NiPoint4(const NiPoint3& a_point) noexcept :
		x(a_point.x), y(a_point.y), z(a_point.z)
	{}

	NiPoint4::NiPoint4(float a_x, float a_y, float a_z, float a_w) noexcept :
		x(a_x), y(a_y), z(a_z), w(a_w)
	{}

	float& NiPoint4::operator[](std::size_t a_pos) noexcept
	{
		assert(a_pos < 4);
		return std::addressof(x)[a_pos];
	}

	const float& NiPoint4::operator[](std::size_t a_pos) const noexcept
	{
		assert(a_pos < 4);
		return std::addressof(x)[a_pos];
	}

	bool NiPoint4::operator==(const NiPoint4& a_rhs) const noexcept
	{
		return (x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z) && (w == a_rhs.w);
	}

	bool NiPoint4::operator!=(const NiPoint4& a_rhs) const noexcept
	{
		return !operator==(a_rhs);
	}

	bool NiPoint4::operator<(const NiPoint4& a_rhs) const noexcept
	{
		return std::tie(x, y, z, w) < std::tie(a_rhs.x, a_rhs.y, a_rhs.z, a_rhs.w);
	}

	bool NiPoint4::operator>(const NiPoint4& a_rhs) const noexcept
	{
		return std::tie(x, y, z, w) > std::tie(a_rhs.x, a_rhs.y, a_rhs.z, a_rhs.w);
	}

	NiPoint4 NiPoint4::operator+(const NiPoint4& a_rhs) const noexcept
	{
		return NiPoint4(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z, w + a_rhs.w);
	}

	NiPoint4 NiPoint4::operator-(const NiPoint4& a_rhs) const noexcept
	{
		return NiPoint4(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z, w - a_rhs.w);
	}

	NiPoint4 NiPoint4::operator*(const NiPoint4& a_rhs) const noexcept
	{
		return NiPoint4(x * a_rhs.x, y * a_rhs.y, z * a_rhs.z, w * a_rhs.w);
	}

	NiPoint4 NiPoint4::operator/(const NiPoint4& a_rhs) const noexcept
	{
		return NiPoint4(x / a_rhs.x, y / a_rhs.y, z / a_rhs.z, w / a_rhs.w);
	}

	NiPoint4 NiPoint4::operator*(float a_scalar) const noexcept
	{
		return NiPoint4(x * a_scalar, y * a_scalar, z * a_scalar, w * a_scalar);
	}

	NiPoint4 NiPoint4::operator/(float a_scalar) const noexcept
	{
		return operator*(1.0F / a_scalar);
	}

	NiPoint4 NiPoint4::operator-() const noexcept
	{
		return NiPoint4(-x, -y, -z, -w);
	}

	NiPoint4& NiPoint4::operator+=(const NiPoint4& a_rhs) noexcept
	{
		x += a_rhs.x;
		y += a_rhs.y;
		z += a_rhs.z;
		w += a_rhs.w;
		return *this;
	}

	NiPoint4& NiPoint4::operator-=(const NiPoint4& a_rhs) noexcept
	{
		x -= a_rhs.x;
		y -= a_rhs.y;
		z -= a_rhs.z;
		w -= a_rhs.w;
		return *this;
	}

	NiPoint4& NiPoint4::operator*=(const NiPoint4& a_rhs) noexcept
	{
		x *= a_rhs.x;
		y *= a_rhs.y;
		z *= a_rhs.z;
		w *= a_rhs.w;
		return *this;
	}

	NiPoint4& NiPoint4::operator/=(const NiPoint4& a_rhs) noexcept
	{
		x /= a_rhs.x;
		y /= a_rhs.y;
		z /= a_rhs.z;
		w /= a_rhs.w;
		return *this;
	}

	NiPoint4& NiPoint4::operator+=(float a_scalar) noexcept
	{
		x += a_scalar;
		y += a_scalar;
		z += a_scalar;
		w += a_scalar;
		return *this;
	}

	NiPoint4& NiPoint4::operator-=(float a_scalar) noexcept
	{
		x -= a_scalar;
		y -= a_scalar;
		z -= a_scalar;
		w -= a_scalar;
		return *this;
	}

	NiPoint4& NiPoint4::operator*=(float a_scalar) noexcept
	{
		x *= a_scalar;
		y *= a_scalar;
		z *= a_scalar;
		w *= a_scalar;
		return *this;
	}

	NiPoint4& NiPoint4::operator/=(float a_scalar) noexcept
	{
		x /= a_scalar;
		y /= a_scalar;
		z /= a_scalar;
		w /= a_scalar;
		return *this;
	}
}
