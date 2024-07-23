#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class BGSLocalizedString
	{
	public:
		using size_type = typename BSFixedStringCS::size_type;
		using value_type = typename BSFixedStringCS::value_type;
		using pointer = typename BSFixedStringCS::pointer;
		using const_pointer = typename BSFixedStringCS::const_pointer;
		using reference = typename BSFixedStringCS::reference;
		using const_reference = typename BSFixedStringCS::const_reference;

		BGSLocalizedString& operator=(std::basic_string_view<value_type> a_rhs)
		{
			const auto self = static_cast<std::basic_string_view<value_type>>(_data);
			if (self.starts_with("<ID=")) {
				assert(self.length() >= PREFIX_LENGTH);
				std::vector<char> buf(PREFIX_LENGTH + a_rhs.length() + 1, '\0');
				strncpy_s(buf.data(), buf.size(), self.data(), PREFIX_LENGTH);
				strcpy_s(buf.data() + PREFIX_LENGTH, buf.size() - PREFIX_LENGTH, (a_rhs.empty() ? "" : a_rhs.data()));
				_data = std::string_view{ buf.data(), buf.size() };
			} else {
				_data = a_rhs;
			}

			return *this;
		}

		[[nodiscard]] const_pointer data() const noexcept { return _data.data(); }
		[[nodiscard]] const_pointer c_str() const noexcept { return _data.c_str(); }

		[[nodiscard]] operator std::basic_string_view<value_type>() const { return { _data }; }

		[[nodiscard]] bool empty() const noexcept { return _data.empty(); }

		[[nodiscard]] size_type size() const noexcept { return _data.size(); }
		[[nodiscard]] size_type length() const noexcept { return _data.length(); }

	private:
		static constexpr std::size_t PREFIX_LENGTH = 13;

		// members
		BSFixedStringCS _data;  // 0
	};
	static_assert(sizeof(BGSLocalizedString) == 0x8);
}
