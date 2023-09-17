#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	struct TESFormRefCount : public BaseFormComponent
	{
	public:
		SF_RTTI(TESFormRefCount);

		// members
		volatile mutable std::uint64_t refCount;  // 08
	};
	static_assert(sizeof(TESFormRefCount) == 0x10);
}
