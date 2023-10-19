#include "RE/A/Actor.h"
#include "RE/Offsets.h"

namespace RE
{
	bool Actor::IsHostileToActor(Actor* a_actor)
	{
		using func_t = decltype(&Actor::IsHostileToActor);
		REL::Relocation<func_t> func{ Offset::Actor::IsHostileToActor };
		return func(this, a_actor);
	}
}
