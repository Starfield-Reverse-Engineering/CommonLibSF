#pragma once

#include "RE/B/BSCoreTypes.h"
#include "RE/B/BSTEvent.h"

namespace RE
{
	struct TESContainerChangedEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESContainerChangedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESContainerChangedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESContainerChangedEvent::GetEventSource };
			return func();
		}

		// members
		TESFormID     oldContainerFormID;  // 00
		TESFormID     newContainerFormID;  // 04
		TESFormID     baseObjectFormID;    // 08
		std::int32_t  itemCount;           // 0C
		TESFormID     referenceFormID;     // 10
		std::uint16_t uniqueID;            // 14
		std::uint64_t unk18;               // 18
		std::uint32_t unk20;               // 20
	};
	static_assert(sizeof(TESContainerChangedEvent) == 0x28);
}
