#pragma once

#include "RE/B/BSContainer.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTObjectArena.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSTTuple.h"
#include "RE/I/IMemoryPagePolicy.h"

namespace RE::BSScript
{
	class MemoryPage;  // stub

	class SimpleAllocMemoryPagePolicy :
		public IMemoryPagePolicy
	{
	public:
		SF_RTTI_VTABLE(BSScript__SimpleAllocMemoryPagePolicy);

		// override (IMemoryPagePolicy)
		std::uint32_t    MaximumPageSize() const override { return maxPageSize; }                                                                // 01
		std::uint32_t    MaximumStackDepth() const override { return maxStackDepth; }                                                            // 02
		AllocationStatus AllocatePage(std::uint32_t a_sizeInBytes, NewPageStrategy a_strategy, BSTAutoPointer<MemoryPage>& a_newPage) override;  // 03
		AllocationStatus GetLargestAvailablePage(BSTAutoPointer<MemoryPage>& a_newPage) override;                                                // 04
		void             DisposePage(BSTAutoPointer<MemoryPage>& a_oldPage) override;                                                            // 05

		// members
		const std::uint32_t minPageSize{ 0x40 };             // 08
		const std::uint32_t maxPageSize{ 0x2000 };           // 0C
		const std::uint32_t maxAllocatedMemory{ 0x100000 };  // 10
		const std::uint32_t maxStackDepth{ 500 };            // 14
		bool                ignoreMemoryLimit{ false };      // 18
		bool                outOfMemory{ false };            // 19
		BSSpinLock          dataLock;                        // 1C
		std::uint32_t       currentMemorySize{ 0 };          // 24
		std::uint32_t       maxAdditionalAllocations{ 0 };   // 28
	};
	static_assert(sizeof(SimpleAllocMemoryPagePolicy) == 0x30);
}
