#pragma once

#include "RE/N/NiPoint3.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSLocation;
	class TESWorldSpace :
		public TESForm,     // 00
		public TESFullName  // 20
	{
	public:
		SF_FORMTYPE(WRLD);

		[[nodiscard]] BGSLocation* GetLocationFromCoordinates(NiPoint3A& a_coordinates);

		//
	};
}
