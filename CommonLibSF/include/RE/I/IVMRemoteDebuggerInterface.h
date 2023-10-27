#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	namespace BSScript
	{
		class __declspec(novtable) IVMRemoteDebuggerInterface
		{
		public:
			SF_RTTI_VTABLE(BSScript__IVMRemoteDebuggerInterface);

			~IVMRemoteDebuggerInterface() = delete;

			virtual void Unk00();  // 00 -- calls Unk05 in IVirtualMachine
			virtual void Unk01();  // 01
			virtual void Unk02();  // 02
		};
		static_assert(sizeof(IVMRemoteDebuggerInterface) == 0x8);
	}
}
