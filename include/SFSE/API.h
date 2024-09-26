#pragma once

#include "SFSE/Impl/Stubs.h"
#include "SFSE/Interfaces.h"

#define SFSEAPI __cdecl

namespace RE::BSScript
{
	class IVirtualMachine;
}

namespace SFSE
{
	void Init(const LoadInterface* a_intfc, bool a_log = true) noexcept;

	void RegisterForAPIInitEvent(const std::function<void()>& a_fn);

	std::string_view GetPluginName() noexcept;
	std::string_view GetPluginAuthor() noexcept;
	REL::Version     GetPluginVersion() noexcept;

	PluginHandle GetPluginHandle() noexcept;

	const TrampolineInterface* GetTrampolineInterface() noexcept;
	const MessagingInterface*  GetMessagingInterface() noexcept;
	const MenuInterface*       GetMenuInterface() noexcept;
	const TaskInterface*       GetTaskInterface() noexcept;

	void AllocTrampoline(std::size_t a_size, bool a_trySFSEReserve = true);

	void SetPapyrusCallback(const std::function<void(RE::BSScript::IVirtualMachine**)> a_callback, bool a_trySFSEReserve = true);
}
