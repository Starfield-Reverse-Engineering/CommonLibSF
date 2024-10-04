#pragma once

namespace RE
{
	struct Color
	{
	public:
		enum : std::size_t
		{
			kRed,
			kGreen,
			kBlue,
			kAlpha,

			kTotal
		};

		constexpr Color() noexcept = default;

		constexpr Color(const Color& a_rhs) noexcept :
			red(a_rhs.red),
			green(a_rhs.green),
			blue(a_rhs.blue),
			alpha(a_rhs.alpha)
		{}

		constexpr Color(Color&& a_rhs) noexcept :
			red(std::move(a_rhs.red)),
			green(std::move(a_rhs.green)),
			blue(std::move(a_rhs.blue)),
			alpha(std::move(a_rhs.alpha))
		{}

		constexpr Color(std::uint8_t a_red, std::uint8_t a_green, std::uint8_t a_blue, std::uint8_t a_alpha) noexcept :
			red(a_red),
			green(a_green),
			blue(a_blue),
			alpha(a_alpha)
		{}

		constexpr Color(std::uint32_t a_hexValue) noexcept :
			red((a_hexValue >> 16) & 0xFF),
			green((a_hexValue >> 8) & 0xFF),
			blue((a_hexValue) & 0xFF),
			alpha(0)
		{}

		~Color() noexcept = default;

		constexpr Color& operator=(const Color& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				red = a_rhs.red;
				green = a_rhs.green;
				blue = a_rhs.blue;
				alpha = a_rhs.alpha;
			}
			return *this;
		}

		constexpr Color& operator=(Color&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				red = std::move(a_rhs.red);
				green = std::move(a_rhs.green);
				blue = std::move(a_rhs.blue);
				alpha = std::move(a_rhs.alpha);
			}
			return *this;
		}

		[[nodiscard]] friend constexpr bool operator==(const Color& a_lhs, const Color& a_rhs) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				if (a_lhs[i] != a_rhs[i]) {
					return false;
				}
			}
			return true;
		}

		[[nodiscard]] friend constexpr bool operator!=(const Color& a_lhs, const Color& a_rhs) noexcept
		{
			return !(a_lhs == a_rhs);
		}

		[[nodiscard]] constexpr std::uint8_t& operator[](std::size_t a_idx) noexcept
		{
			assert(a_idx < kTotal);
			return std::addressof(red)[a_idx];
		}

		[[nodiscard]] constexpr const std::uint8_t& operator[](std::size_t a_idx) const noexcept
		{
			assert(a_idx < kTotal);
			return std::addressof(red)[a_idx];
		}

		[[nodiscard]] Color operator+(const Color& a_rhs) const noexcept
		{
			Color tmp = *this;
			for (std::size_t i = 0; i < kTotal; ++i) {
				tmp[i] += a_rhs[i];
			}
			return tmp;
		}

		Color& operator+=(const Color& a_rhs) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				operator[](i) += a_rhs[i];
			}
			return *this;
		}

		[[nodiscard]] Color operator-(const Color& a_rhs) const noexcept
		{
			Color tmp = *this;
			for (std::size_t i = 0; i < kTotal; ++i) {
				tmp[i] -= a_rhs[i];
			}
			return tmp;
		}

		Color& operator-=(const Color& a_rhs) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				operator[](i) -= a_rhs[i];
			}
			return *this;
		}

		friend Color operator-(std::uint8_t a_lhs, const Color& a_rhs)
		{
			return Color(
				a_lhs - a_rhs.red,
				a_lhs - a_rhs.green,
				a_lhs - a_rhs.blue,
				a_lhs - a_rhs.alpha);
		}

		[[nodiscard]] Color operator*(const Color& a_rhs) const noexcept
		{
			Color tmp = *this;
			for (std::size_t i = 0; i < kTotal; ++i) {
				tmp[i] *= a_rhs[i];
			}
			return tmp;
		}

		Color& operator*=(const Color& a_rhs) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				operator[](i) *= a_rhs[i];
			}
			return *this;
		}

		friend Color operator*(std::uint8_t a_lhs, const Color& a_rhs)
		{
			return Color(
				a_lhs * a_rhs.red,
				a_lhs * a_rhs.green,
				a_lhs * a_rhs.blue,
				a_lhs * a_rhs.alpha);
		}

		[[nodiscard]] Color operator/(const Color& a_rhs) const noexcept
		{
			Color tmp = *this;
			for (std::size_t i = 0; i < kTotal; ++i) {
				tmp[i] /= a_rhs[i];
			}
			return tmp;
		}

		Color& operator/=(const Color& a_rhs) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				operator[](i) /= a_rhs[i];
			}
			return *this;
		}

		friend Color operator/(std::uint8_t a_lhs, const Color& a_rhs)
		{
			return Color(
				a_lhs / a_rhs.red,
				a_lhs / a_rhs.green,
				a_lhs / a_rhs.blue,
				a_lhs / a_rhs.alpha);
		}

		[[nodiscard]] Color operator+(std::uint8_t a_value) const noexcept
		{
			Color tmp = *this;
			for (std::size_t i = 0; i < kTotal; ++i) {
				tmp[i] += a_value;
			}
			return tmp;
		}

		Color& operator+=(std::uint8_t a_value) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				operator[](i) += a_value;
			}
			return *this;
		}

		[[nodiscard]] Color operator-(std::uint8_t a_value) const noexcept
		{
			Color tmp = *this;
			for (std::size_t i = 0; i < kTotal; ++i) {
				tmp[i] -= a_value;
			}
			return tmp;
		}

		Color& operator-=(std::uint8_t a_value) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				operator[](i) -= a_value;
			}
			return *this;
		}

		[[nodiscard]] Color operator*(std::uint8_t a_value) const noexcept
		{
			Color tmp = *this;
			for (std::size_t i = 0; i < kTotal; ++i) {
				tmp[i] *= a_value;
			}
			return tmp;
		}

		Color& operator*=(std::uint8_t a_value) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				operator[](i) *= a_value;
			}
			return *this;
		}

		[[nodiscard]] Color operator/(std::uint8_t a_value) const noexcept
		{
			Color tmp = *this;
			for (std::size_t i = 0; i < kTotal; ++i) {
				tmp[i] /= a_value;
			}
			return tmp;
		}

		Color& operator/=(std::uint8_t a_value) noexcept
		{
			for (std::size_t i = 0; i < kTotal; ++i) {
				operator[](i) /= a_value;
			}
			return *this;
		}

		std::uint32_t ToInt() const
		{
			return ((red & 0xFF) << 24) + ((green & 0xFF) << 16) + ((blue & 0xFF) << 8) + (alpha & 0xFF);
		}

		std::string ToHex() const
		{
			return std::format("{:X}{:X}{:X}{:X}", red, green, blue, alpha);
		}

		// members
		std::uint8_t red{ 0 };    // 0
		std::uint8_t green{ 0 };  // 1
		std::uint8_t blue{ 0 };   // 2
		std::uint8_t alpha{ 0 };  // 3
	};
	static_assert(sizeof(Color) == 0x4);
}
