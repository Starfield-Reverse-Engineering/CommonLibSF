#pragma once

#include "RE/B/BSFixedString.h"

namespace RE::BSScript
{
	class __declspec(novtable) IVMRemoteDebuggerInterface
	{
	public:
		SF_RTTI_VTABLE(BSScript__IVMRemoteDebuggerInterface);

		~IVMRemoteDebuggerInterface() = delete;

		virtual bool IsCompletelyFrozen() = 0;  // 00 -- just calls IsCompletelyFrozen on the VM
		virtual void Unk01() = 0;  // 01
		virtual void Unk02() = 0;  // 02
	};
	static_assert(sizeof(IVMRemoteDebuggerInterface) == 0x8);
}
