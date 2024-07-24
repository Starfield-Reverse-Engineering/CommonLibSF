#pragma once

#include "SFSE/Impl/Stubs.h"
#include "SFSE/Interfaces.h"
#include "SFSE/Trampoline.h"

#define SFSEAPI __cdecl

namespace RE::BSScript
{
	class IVirtualMachine;
}

namespace SFSE
{
	void Init(const LoadInterface* a_intfc, bool a_log = true) noexcept;

	void RegisterForAPIInitEvent(const std::function<void()>& a_fn);

	PluginHandle GetPluginHandle() noexcept;

	const TrampolineInterface* GetTrampolineInterface() noexcept;

	const MessagingInterface* GetMessagingInterface() noexcept;

	const MenuInterface* GetMenuInterface() noexcept;

	const TaskInterface* GetTaskInterface() noexcept;

	Trampoline& GetTrampoline();

	void AllocTrampoline(std::size_t a_size, bool a_trySFSEReserve = true);

	void SetPapyrusCallback(const std::function<void(RE::BSScript::IVirtualMachine**)> a_callback, bool a_trySFSEReserve = true);
}
