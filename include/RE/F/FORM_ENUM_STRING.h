#pragma once

namespace RE
{
	enum class FormType;

	struct FORM_ENUM_STRING
	{
	public:
		[[nodiscard]] static std::span<FORM_ENUM_STRING, 215> GetFormEnumString()
		{
			static REL::Relocation<FORM_ENUM_STRING(*)[215]> formEnumString{ ID::FORM_ENUM_STRING::FormEnumString };
			return { *formEnumString };
		}

		// members
		const char* formString;  // 00
		FormType    formType;    // 08
	};
	static_assert(sizeof(FORM_ENUM_STRING) == 0x10);
}
