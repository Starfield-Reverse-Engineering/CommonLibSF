#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESObjectCELL;

	struct TESFormIDRemapEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESFormIDRemapEvent>* GetEventSource()
		{
			using func_t = decltype(&TESFormIDRemapEvent::GetEventSource);
			REL::Relocation<func_t> func{ REL::ID(107167) };
			return func();
		}

		// members
		uint32_t oldId;
		uint32_t newId;
	};
	static_assert(sizeof(TESFormIDRemapEvent) == 0x8);
}
