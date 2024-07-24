#include "RE/V/VirtualMachine.h"
#include "RE/G/GameVM.h"

namespace RE::BSScript::Internal
{
	VirtualMachine* VirtualMachine::GetSingleton()
	{
		auto vm = GameVM::GetSingleton();
		return vm ? static_cast<VirtualMachine*>(vm->impl.get()) : nullptr;
	}
}