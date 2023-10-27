#pragma once

namespace RE
{
	namespace BSScript
	{
		class IVirtualMachine;
		class StackFrame;

		class ISavePatcherInterface
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__ISavePatcherInterface };
			static constexpr auto VTABLE{ VTABLE::BSScript__ISavePatcherInterface };

			virtual ~ISavePatcherInterface() = default;  // 00

			// add
			virtual void PatchStackFrame(StackFrame&, IVirtualMachine&) = 0;  // 01
		};
		static_assert(sizeof(ISavePatcherInterface) == 0x8);
	}
}
