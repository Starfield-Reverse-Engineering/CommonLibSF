#pragma once

#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESFullName : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESFullName);

		~TESFullName() override;

		// add
		virtual std::uint32_t             GetFullNameLength() const;     // 11
		virtual const char*               GetFullName() const;           // 12
		virtual const BGSLocalizedString& GetFullNameLocalized() const;  // 13

		// members
		BGSLocalizedString fullName;  // 08 - FULL
	};
	static_assert(sizeof(TESFullName) == 0x10);
}
