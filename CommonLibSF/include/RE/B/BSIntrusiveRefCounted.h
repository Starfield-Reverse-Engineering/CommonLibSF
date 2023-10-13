#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	struct BSIntrusiveRefCounted
	{
	public:
		SF_RTTI(BSIntrusiveRefCounted);

		template <class>
		friend struct BSTSmartPointerIntrusiveRefCount;

		constexpr BSIntrusiveRefCounted() noexcept {}

		std::uint32_t IncRef() const
		{
			stl::atomic_ref myRefCount{ _refCount };
			return ++myRefCount;
		}

		std::uint32_t DecRef() const
		{
			stl::atomic_ref myRefCount{ _refCount };
			return --myRefCount;
		}

		[[nodiscard]] constexpr std::uint32_t QRefCount() const noexcept { return _refCount; }

		SF_HEAP_REDEFINE_NEW();

	protected:
		// members
		mutable volatile std::uint32_t _refCount{};  // 0
	};
	static_assert(sizeof(BSIntrusiveRefCounted) == 0x04);
}
