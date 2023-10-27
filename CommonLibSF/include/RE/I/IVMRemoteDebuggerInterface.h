#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	namespace BSScript
	{
		class __declspec(novtable) IVMRemoteDebuggerInterface
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IVMRemoteDebuggerInterface };
			static constexpr auto VTABLE{ VTABLE::BSScript__IVMRemoteDebuggerInterface };

			virtual ~IVMRemoteDebuggerInterface();  // 00

			virtual void Unk01();  // 01
			virtual void Unk02();  // 02
		};
		static_assert(sizeof(IVMRemoteDebuggerInterface) == 0x8);
	}
}
