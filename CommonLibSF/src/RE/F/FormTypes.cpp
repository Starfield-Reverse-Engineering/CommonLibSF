#include "RE/F/FormTypes.h"

#include "RE/F/FORM_ENUM_STRING.h"

namespace RE
{
	const char* FormTypeToString(FormType a_formType)
	{
		return FORM_ENUM_STRING::GetFormEnumString()[stl::to_underlying(a_formType)].formString;
	}

	FormType StringToFormType(std::string_view a_formType)
	{
		for (auto& iter : FORM_ENUM_STRING::GetFormEnumString()) {
			if (_stricmp(iter.formString, a_formType.data()) == 0) {
				return iter.formType;
			}
		}

		return FormType::kNONE;
	}
}
