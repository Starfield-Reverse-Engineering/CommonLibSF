#pragma once

namespace RE
{
	class NiQuaternion
	{
	public:
		float w{ 1.0f };
		float x{ 0.0f };
		float y{ 0.0f };
		float z{ 0.0f };

		NiQuaternion() {}

		NiQuaternion(float w, float x, float y, float z) :
			w(w), x(x), y(y), z(z) {}

		NiQuaternion(const NiMatrix3& mat)
		{
			FromMatrix(mat);
		}

		static NiQuaternion Slerp(const NiQuaternion& prev, NiQuaternion next, float t)
		{
			NiQuaternion result;
			float        dot = prev.Dot(next);
			if (dot < 0.0f) {
				next = -next;
				dot = -dot;
			}

			const float epsilon = 1e-6f;
			if (1.0f - dot > epsilon) {
				float theta = std::acosf(dot);
				float sinTheta = std::sinf(theta);
				float weight1 = std::sinf((1.0f - t) * theta) / sinTheta;
				float weight2 = std::sinf(t * theta) / sinTheta;

				result = (prev * weight1) + (next * weight2);
			} else {
				float tInverse = 1.0f - t;
				result.w = tInverse * prev.w + t * next.w;
				result.x = tInverse * prev.x + t * next.x;
				result.y = tInverse * prev.y + t * next.y;
				result.z = tInverse * prev.z + t * next.z;
			}

			return result;
		}

		static NiQuaternion EulerZXY(const NiPoint3& euler)
		{
			NiQuaternion result;
			result.FromEulerAnglesZXY(euler);
			return result;
		}

		static NiQuaternion AngleAxis(float angle, const NiPoint3& axis)
		{
			NiQuaternion result;
			result.FromAngleAxis(angle, axis);
			return result;
		}

		NiPoint3 ToEulerAnglesZXY() const
		{
			NiPoint3 euler;
			euler.x = std::atan2(2.0f * (w * x + y * z), 1.0f - 2.0f * (x * x + y * y));
			euler.y = std::asin(2.0f * (w * y - z * x));
			euler.z = std::atan2(2.0f * (w * z + x * y), 1.0f - 2.0f * (y * y + z * z));

			return euler;
		}

		void FromEulerAnglesZXY(const NiPoint3& euler)
		{
			float cy = std::cos(euler.z * 0.5f);
			float sy = std::sin(euler.z * 0.5f);
			float cp = std::cos(euler.y * 0.5f);
			float sp = std::sin(euler.y * 0.5f);
			float cr = std::cos(euler.x * 0.5f);
			float sr = std::sin(euler.x * 0.5f);

			w = cr * cp * cy + sr * sp * sy;
			x = sr * cp * cy - cr * sp * sy;
			y = cr * sp * cy + sr * cp * sy;
			z = cr * cp * sy - sr * sp * cy;
		}

		void FromAngleAxis(float angle, const NiPoint3& axis)
		{
			float halfAngle = angle / 2.0f;
			w = std::cos(halfAngle);
			x = std::sin(halfAngle) * axis.x;
			y = std::sin(halfAngle) * axis.y;
			z = std::sin(halfAngle) * axis.z;
		}

		void ToMatrix(NiMatrix3& a_mat) const
		{
			float wx, wy, wz, xx, yy, yz, xy, xz, zz, x2, y2, z2;
			x2 = x + x;
			y2 = y + y;
			z2 = z + z;
			xx = x * x2;
			xy = x * y2;
			xz = x * z2;
			yy = y * y2;
			yz = y * z2;
			zz = z * z2;
			wx = w * x2;
			wy = w * y2;
			wz = w * z2;

			a_mat[0][0] = 1.0f - (zz + yy);
			a_mat[0][1] = xy + wz;
			a_mat[0][2] = xz - wy;
			a_mat[0][3] = 0.0f;

			a_mat[1][0] = xy - wz;
			a_mat[1][1] = 1.0f - (zz + xx);
			a_mat[1][2] = yz + wx;
			a_mat[1][3] = 0.0f;

			a_mat[2][0] = xz + wy;
			a_mat[2][1] = yz - wx;
			a_mat[2][2] = 1.0f - (yy + xx);
			a_mat[2][3] = 0.0f;
		}

		void FromMatrix(const NiMatrix3& a_mat)
		{
			auto& q = *this;
			float trace = a_mat[0][0] + a_mat[1][1] + a_mat[2][2];

			if (trace <= 0.0f) {
				int i = (a_mat[1][1] > a_mat[0][0]) ? 1 : 0;

				if (a_mat[2][2] > a_mat[i][i]) {
					i = 2;
				}

				const int next[4] = {
					1, 2, 0, 0
				};

				int j = next[i];
				int k = next[j];

				float root = std::sqrtf(((a_mat[i][i] - a_mat[j][j]) - a_mat[k][k]) + 1.0f);
				q[i + 1] = root * 0.5f;
				root = 0.5f / root;
				q[0] = (a_mat[j][k] - a_mat[k][j]) * root;
				q[j + 1] = (a_mat[j][i] + a_mat[i][j]) * root;
				q[k + 1] = (a_mat[i][k] + a_mat[k][i]) * root;
			} else {
				float root = std::sqrtf(trace + 1.0f);
				q[0] = root * 0.5f;
				root = 0.5f / root;
				q[1] = (a_mat[1][2] - a_mat[2][1]) * root;
				q[2] = (a_mat[2][0] - a_mat[0][2]) * root;
				q[3] = (a_mat[0][1] - a_mat[1][0]) * root;
			}
		}

		float Dot() const
		{
			return w * w + x * x + y * y + z * z;
		}

		float Dot(const NiQuaternion& q) const
		{
			return w * q.w + x * q.x + y * q.y + z * q.z;
		}

		float Magnitude() const
		{
			return std::sqrt(Dot());
		}

		//Faster than Normalize(), but with less precision.
		NiQuaternion FastNormalize() const
		{
			__m128 temp = _mm_set_ss(Dot());
			temp = _mm_rsqrt_ss(temp);
			float rsqrt = _mm_cvtss_f32(temp);
			return { w * rsqrt, x * rsqrt, y * rsqrt, z * rsqrt };
		}

		NiQuaternion Normalize() const
		{
			float rsqrt = 1.0f / Magnitude();
			return { w * rsqrt, x * rsqrt, y * rsqrt, z * rsqrt };
		}

		NiQuaternion InvertVector() const
		{
			return { w, -x, -y, -z };
		}

		NiQuaternion InvertScalar() const
		{
			return { -w, x, y, z };
		}

		float& operator[](size_t i)
		{
			assert(i < 4);
			return (&w)[i];
		}

		const float& operator[](size_t i) const
		{
			assert(i < 4);
			return (&w)[i];
		}

		NiQuaternion operator*(const NiQuaternion& a_rhs) const
		{
			return {
				a_rhs.w * w - a_rhs.x * x - a_rhs.y * y - a_rhs.z * z,
				a_rhs.w * x + a_rhs.x * w - a_rhs.y * z + a_rhs.z * y,
				a_rhs.w * y + a_rhs.x * z + a_rhs.y * w - a_rhs.z * x,
				a_rhs.w * z - a_rhs.x * y + a_rhs.y * x + a_rhs.z * w
			};
		}

		NiPoint3 operator*(const NiPoint3& a_rhs) const
		{
			NiQuaternion res = (*this) * NiQuaternion{ 0.0f, a_rhs.x, a_rhs.y, a_rhs.z } * InvertVector();
			return { res.x, res.y, res.z };
		}

		void operator*=(const NiQuaternion& a_rhs)
		{
			(*this) = operator*(a_rhs);
		}

		NiQuaternion operator*(float s) const
		{
			return { w * s, x * s, y * s, z * s };
		}

		NiQuaternion operator+(const NiQuaternion& a_rhs) const
		{
			return { w + a_rhs.w, x + a_rhs.x, y + a_rhs.y, z + a_rhs.z };
		}

		NiQuaternion operator-(const NiQuaternion& a_rhs) const
		{
			return { w - a_rhs.w, x - a_rhs.x, y - a_rhs.y, z - a_rhs.z };
		}

		NiQuaternion operator/(float s) const
		{
			return { w / s, x / s, y / s, z / s };
		}

		NiQuaternion operator-() const
		{
			return { -w, -x, -y, -z };
		}
	};
	static_assert(sizeof(NiQuaternion) == 0x10);
}
