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

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESFullName_Component"; }
		void                 InitializeDataComponent() override;     // 02

		// add
		virtual std::uint32_t             GetFullNameLength() const;     // 0B
		virtual const char*               GetFullName() const;           // 0C
		virtual const BGSLocalizedString& GetFullNameLocalized() const;  // OD

		// members
		BGSLocalizedString fullName;  // 08 - FULL
	};
	static_assert(sizeof(TESFullName) == 0x10);
}
