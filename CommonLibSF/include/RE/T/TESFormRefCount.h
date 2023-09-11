#pragma once

namespace RE
{
	struct TESFormRefCount
	{
	public:
		TES_RTTI(TESFormRefCount);

		// members
		volatile mutable std::uint64_t refCount;  // 0x0
	};
}

