#pragma once

namespace RE
{
	class InputEvent;

	class BSInputEventReceiver
	{
	public:
		SF_RTTI_VTABLE(BSInputEventReceiver);

		virtual ~BSInputEventReceiver() = default;  // 00

		// add
		virtual void PerformInputProcessing(const InputEvent* a_queueHead) = 0;  // 01

		// members
		std::int32_t currInputTimeCount;  // 08
	};
	static_assert(sizeof(BSInputEventReceiver) == 0x10);
}
