#pragma once

#include "RE/A/ActorValues.h"
#include "RE/A/ActorValueInfo.h"

namespace RE
{
	class ActorValueOwner
	{
	public:
		TES_RTTI_VTABLE(ActorValueOwner);

		// add
		virtual float GetActorValue(const ActorValueInfo& a_info);
		virtual float GetPermanentActorValue(const ActorValueInfo& a_info);
		virtual float GetBaseActorValue(const ActorValueInfo& a_info);
		virtual void  SetBaseActorValue(const ActorValueInfo& a_info, float a_value);
		virtual void  ModBaseActorValue(const ActorValueInfo& a_info, float a_delta);
		virtual void  ModActorValue(ACTOR_VALUE_MODIFIER a_modifier, const ActorValueInfo& a_info);
		virtual float GetModifier(ACTOR_VALUE_MODIFIER a_modifier, const ActorValueInfo& a_info);
		virtual void  RestorActorValue(const ActorValueInfo& a_info, float a_amount);
		virtual void  SetActorValue(const ActorValueInfo& a_info, float afValue);
	};
	static_assert(sizeof(ActorValueOwner) == 0x8);
}

