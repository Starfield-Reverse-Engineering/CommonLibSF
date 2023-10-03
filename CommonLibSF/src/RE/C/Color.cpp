#include "RE/C/Color.h"

namespace RE
{
	std::uint32_t Color::ToInt() const
	{
		return ((red & 0xFF) << 24) + ((green & 0xFF) << 16) + ((blue & 0xFF) << 8) + (alpha & 0xFF);
	}

	std::string Color::ToHex() const
	{
		return std::format("{:X}{:X}{:X}{:X}", red, green, blue, alpha);
	}
}
