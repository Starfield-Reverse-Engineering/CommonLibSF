#pragma once

namespace RE
{
	struct TESFormRefCount
	{
	public:
		// members
		volatile mutable std::uint64_t refCount;  // 0x0
	};
}

