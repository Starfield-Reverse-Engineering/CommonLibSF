#pragma once

namespace RE
{
	class Actor;
	class BGSKeyword;
}

namespace RE::ActorUtils
{
	inline bool ChangeAnimArchetype(Actor* a_actor, BGSKeyword* a_keyword)
	{
		using func_t = decltype(&ActorUtils::ChangeAnimArchetype);
		static REL::Relocation<func_t> func{ ID::ActorUtils::ChangeAnimArchetype };
		return func(a_actor, a_keyword);
	}
}
