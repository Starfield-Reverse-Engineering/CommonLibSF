#pragma once

namespace RE
{
	struct IMovementInterface
	{
	public:
		virtual ~IMovementInterface();  // 00
	};
	static_assert(sizeof(IMovementInterface) == 0x8);
}
