#include "RE/A/Actor.h"

namespace RE
{
	bool Actor::IsHostileToActor(Actor* a_actor)
	{
		using func_t = decltype(&Actor::IsHostileToActor);
		REL::Relocation<func_t> func{ ID::Actor::IsHostileToActor };
		return func(this, a_actor);
	}
	void Actor::SetHelmetFlashlight(bool a_on)
	{
		using func_t = decltype(&Actor::SetHelmetFlashlight);
		REL::Relocation<func_t> func{ REL::ID(153762) };
		func(this, a_on);
	}
}
