#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/B/BGSLocation.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class TESWorldSpace :
		public TESForm,     // 00
		public TESFullName  // 20
	{
	public:
		SF_FORMTYPE(WRLD);

		[[nodiscard]] BGSLocation* GetLocationFromCoordinates(NiPoint3A a_coordinates);

		//
	};
}
