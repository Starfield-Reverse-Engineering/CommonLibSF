#include "RE/T/TESWorldSpace.h"

namespace RE
{
	BGSLocation* TESWorldSpace::GetLocationFromCoordinates(const NiPoint3A& a_coordinates)
	{
		using func_t = decltype(&TESWorldSpace::GetLocationFromCoordinates);
		static REL::Relocation<func_t> func{ ID::TESWorldSpace::GetLocationFromCoordinates };
		return func(this, a_coordinates);
	}
}
