#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"

namespace RE
{
	class BGSInventoryItem;

	namespace BGSInventoryListEvent
	{
		struct Event;
	}

	class BGSInventoryList :
		public BSTEventSource<BGSInventoryListEvent::Event>  // 00
	{
	public:
		SF_RTTI_VTABLE(BGSInventoryList);

		~BGSInventoryList() override;  // 00

		// members
		BSTArray<BGSInventoryItem> data;          // 28
		std::uint32_t              ownerHandle;   // 38
		float                      cachedWeight;  // 3C
	};
	static_assert(sizeof(BGSInventoryList) == 0x40);
}
