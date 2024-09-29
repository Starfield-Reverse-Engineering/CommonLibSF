#pragma once

#include "RE/B/BSCoreTypes.h"
#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESObjectCELL;

	struct TESFormIDRemapEvent
	{
		[[nodiscard]] static BSTEventSource<TESFormIDRemapEvent>* GetEventSource()
		{
			using func_t = decltype(&TESFormIDRemapEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(107167) };
			return func();
		}

		// members
		TESFormID oldId;
		TESFormID newId;
	};
	static_assert(sizeof(TESFormIDRemapEvent) == 0x8);
}
