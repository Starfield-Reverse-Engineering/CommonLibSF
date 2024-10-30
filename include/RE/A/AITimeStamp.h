#pragma once

namespace RE
{
	class AITimeStamp
	{
	public:
		// members
		float timeStamp{ -3.4028235e38f };  // 00
	};
	static_assert(sizeof(AITimeStamp) == 0x4);
}
