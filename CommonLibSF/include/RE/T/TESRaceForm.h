#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/T/TESRace.h"

namespace RE
{
	class TESRaceForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESRaceForm);

		// members
		TESRace* formRace;  // 08
	};
	static_assert(sizeof(TESRaceForm) == 0x10);
}
