#pragma once

namespace RE::BSScript
{
	class IVirtualMachine;
	class StackFrame;

	class ISavePatcherInterface
	{
	public:
		SF_RTTI_VTABLE(BSScript__ISavePatcherInterface);

		virtual ~ISavePatcherInterface() = default;  // 00

		// add
		virtual void PatchStackFrame(StackFrame&, IVirtualMachine&) = 0;  // 01
	};
	static_assert(sizeof(ISavePatcherInterface) == 0x8);
}
