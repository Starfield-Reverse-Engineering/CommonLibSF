#include "RE/T/TESWorldSpace.h"

namespace RE
{
	BGSLocation* TESWorldSpace::GetLocationFromCoordinates(const NiPoint3A& a_coordinates)
	{
		using func_t = decltype(&TESWorldSpace::GetLocationFromCoordinates);
		REL::Relocation<func_t> func{ REL::ID(107914) };
		return func(this, a_coordinates);
	}
}
