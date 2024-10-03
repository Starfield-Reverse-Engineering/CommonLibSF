#include "RE/A/Actor.h"

namespace RE
{
	void Actor::EvaluatePackage(bool a_immediate, bool a_resetAI)
	{
		using func_t = decltype(&Actor::EvaluatePackage);
		static REL::Relocation<func_t> func{ ID::Actor::EvaluatePackage };
		return func(this, a_immediate, a_resetAI);
	}

	bool Actor::IsHostileToActor(Actor* a_actor)
	{
		using func_t = decltype(&Actor::IsHostileToActor);
		static REL::Relocation<func_t> func{ ID::Actor::IsHostileToActor };
		return func(this, a_actor);
	}
}
