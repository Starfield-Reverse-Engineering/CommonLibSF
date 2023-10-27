#pragma once

#include "RE/I/ISavePatcherInterface.h"

namespace RE::GameScript
{
	class __declspec(novtable) SavePatcher :
		public BSScript::ISavePatcherInterface  // 0
	{
	public:
		static constexpr auto RTTI{ RTTI::GameScript__SavePatcher };
		static constexpr auto VTABLE{ VTABLE::GameScript__SavePatcher };

		// override (BSScript::ISavePatcherInterface)
		void PatchStackFrame(BSScript::StackFrame&, BSScript::IVirtualMachine&) override { return; }  // 01
	};
	static_assert(sizeof(SavePatcher) == 0x8);
}