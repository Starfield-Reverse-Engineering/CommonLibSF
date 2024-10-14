#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class TESForm;

	class BGSEditorID
	{
	public:
		using size_type = typename BSFixedString::size_type;
		using value_type = typename BSFixedString::value_type;
		using pointer = typename BSFixedString::pointer;
		using const_pointer = typename BSFixedString::const_pointer;
		using reference = typename BSFixedString::reference;
		using const_reference = typename BSFixedString::const_reference;

		[[nodiscard]] const_pointer data() const noexcept { return _data.data(); }
		[[nodiscard]] const_pointer c_str() const noexcept { return _data.c_str(); }

		[[nodiscard]] operator std::basic_string_view<value_type>() const { return { c_str(), length() }; }

		[[nodiscard]] bool empty() const noexcept { return _data.empty(); }

		[[nodiscard]] size_type size() const noexcept { return _data.size(); }
		[[nodiscard]] size_type length() const noexcept { return _data.length(); }

		[[nodiscard]] bool operator==(const BSFixedString& a_rhs) const noexcept { return _data == a_rhs; }
		[[nodiscard]] bool operator==(std::basic_string_view<value_type> a_rhs) const { return _data == a_rhs; }

		[[nodiscard]] bool contains(std::basic_string_view<value_type> a_rhs) const { return _data.contains(a_rhs); }

		[[nodiscard]] TESForm* owner() const { return _owner; }

		void Register(const char* a_editorID, const RE::TESForm* a_form)
		{
			using func_t = decltype(&BGSEditorID::Register);
			static REL::Relocation<func_t> func{ ID::BGSEditorID::Register };
			return func(this, a_editorID, a_form);
		}

	private:
		// members
		BSFixedString _data;     // 00
		TESForm*      _owner{};  // 08
	};
	static_assert(sizeof(BGSEditorID) == 0x10);
}
