#pragma once

#include "RE/A/ActorValues.h"

namespace RE
{
	class TESObjectREFR;

	class ActorValueOwner
	{
	public:
		SF_RTTI(ActorValueOwner);

		virtual ~ActorValueOwner();  // 00

		// add
		virtual float              GetActorValue(const ActorValueInfo& a_info);                                                                        // 01
		virtual float              GetPermanentActorValue(const ActorValueInfo& a_info);                                                               // 02
		virtual float              GetBaseActorValue(const ActorValueInfo& a_info);                                                                    // 03
		virtual void               SetBaseActorValue(const ActorValueInfo& a_info, float a_value);                                                     // 04
		virtual void               ModBaseActorValue(const ActorValueInfo& a_info, float a_delta);                                                     // 05
		virtual void               ModActorValue(ACTOR_VALUE_MODIFIER a_modifier, const ActorValueInfo& a_info, float a_delta, TESObjectREFR* a_ref);  // 06 - new
		virtual void               ModActorValue(ACTOR_VALUE_MODIFIER a_modifier, const ActorValueInfo& a_info, float a_delta);                        // 07
		virtual float              GetModifier(ACTOR_VALUE_MODIFIER a_modifier, const ActorValueInfo& a_info);                                         // 08
		virtual void               RestoreActorValue(const ActorValueInfo& a_info, float a_amount);                                                    // 09
		virtual void               SetActorValue(const ActorValueInfo& a_info, float a_value);                                                         // 0A
		[[nodiscard]] virtual bool GetIsPlayerOwner() const;                                                                                           // 0B
	};
	static_assert(sizeof(ActorValueOwner) == 0x8);
}
