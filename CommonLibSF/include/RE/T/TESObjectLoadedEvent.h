#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	struct TESObjectLoadedEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESObjectLoadedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESObjectLoadedEvent::GetEventSource);
			REL::Relocation<func_t> func{ REL::ID(107177) };
			return func();
		}

		// members
		std::uint32_t formID;  // 0
		bool          loaded;  // 4
		std::uint8_t  pad5;    // 5
		std::uint16_t pad6;    // 6
	};
	static_assert(sizeof(TESObjectLoadedEvent) == 0x8);
}
