#pragma once

#include "RE/B/BSCoreTypes.h"
#include "RE/B/BSTEvent.h"

namespace RE
{
	struct TESObjectLoadedEvent
	{
		[[nodiscard]] static BSTEventSource<TESObjectLoadedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESObjectLoadedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESObjectLoadedEvent::GetEventSource };
			return func();
		}

		// members
		TESFormID     formID;  // 0
		bool          loaded;  // 4
		std::uint8_t  pad5;    // 5
		std::uint16_t pad6;    // 6
	};
	static_assert(sizeof(TESObjectLoadedEvent) == 0x8);
}
