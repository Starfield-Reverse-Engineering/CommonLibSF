#pragma once

namespace RE
{
	struct BSIntrusiveRefCounted
	{
	public:
		SF_RTTI(BSIntrusiveRefCounted);

		volatile mutable std::uint32_t refCount{ 0 };  // 00
		std::uint32_t                  unk04;          // 04
	};
	static_assert(sizeof(BSIntrusiveRefCounted) == 0x08);
}
