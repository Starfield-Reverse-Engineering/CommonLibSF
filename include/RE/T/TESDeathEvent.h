#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;

	struct TESDeathEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESDeathEvent>* GetEventSource()
		{
			using func_t = decltype(&TESDeathEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESDeathEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> actorDying;   // 00
		NiPointer<TESObjectREFR> actorKiller;  // 08
		bool                     dead;         // 10
	};
	static_assert(sizeof(TESDeathEvent) == 0x18);
}
