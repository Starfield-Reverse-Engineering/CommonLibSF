#pragma once

namespace RE
{
	class InputEvent;

	class BSInputEventReceiver
	{
	public:
		virtual ~BSInputEventReceiver() = default;  // 00

		// add
		virtual void PerformInputProcessing(const InputEvent* a_queueHead) = 0;  // 01

		// members
		std::uint32_t currInputTimeCount;  // 08
	};
	static_assert(sizeof(BSInputEventReceiver) == 0x10);
}
