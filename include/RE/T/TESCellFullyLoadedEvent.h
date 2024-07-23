#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESObjectCELL;

	struct TESCellFullyLoadedEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESCellFullyLoadedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESCellFullyLoadedEvent::GetEventSource);
			REL::Relocation<func_t> func{ ID::TESCellFullyLoadedEvent::GetEventSource };
			return func();
		}

		// members
		TESObjectCELL* cell;
	};
	static_assert(sizeof(TESCellFullyLoadedEvent) == 0x8);
}
