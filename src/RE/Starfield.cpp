#include "RE/Starfield.h"

namespace RE
{
	namespace detail
	{
		template class BSFixedString<char, false>;
		static_assert(sizeof(BSFixedString<char, false>) == 0x8);

		template class BSFixedString<char, true>;
		static_assert(sizeof(BSFixedString<char, true>) == 0x8);

		template class BSFixedString<wchar_t, false>;
		static_assert(sizeof(BSFixedString<wchar_t, false>) == 0x8);

		template class BSFixedString<wchar_t, true>;
		static_assert(sizeof(BSFixedString<wchar_t, true>) == 0x8);
	}
}
