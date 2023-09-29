#include "RE/T/TESFormRefCount.h"

namespace RE
{
	std::uint64_t TESFormRefCount::IncRefCount() const
	{
		stl::atomic_ref myRefCount{ refCount };
		return ++myRefCount;
	}

	std::uint64_t TESFormRefCount::QRefCount() const
	{
		return refCount & kRefCountMask;
	}
}
