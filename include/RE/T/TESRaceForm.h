#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESRace;

	class TESRaceForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESRaceForm);

		~TESRaceForm() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESRace_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		TESRace* formRace;  // 08
	};
	static_assert(sizeof(TESRaceForm) == 0x10);
}
