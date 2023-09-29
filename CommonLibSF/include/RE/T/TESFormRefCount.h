#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	struct TESFormRefCount : public BaseFormComponent
	{
	public:
		SF_RTTI(TESFormRefCount);

		enum
		{
			kRefCountMask = 0x3FFFFF,
		};

		std::uint64_t               IncRefCount() const;
		[[nodiscard]] std::uint64_t QRefCount() const;

		// members
		volatile mutable std::uint64_t refCount;  // 08
	};
	static_assert(sizeof(TESFormRefCount) == 0x10);
}
