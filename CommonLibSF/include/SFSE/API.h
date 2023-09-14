#pragma once

#include "SFSE/Impl/Stubs.h"
#include "SFSE/Interfaces.h"
#include "SFSE/Trampoline.h"
#include "SFSE/Version.h"

#define SFSEAPI __cdecl

namespace SFSE
{
	void Init(const LoadInterface* a_intfc, bool a_log = true) noexcept;
	void RegisterForAPIInitEvent(std::function<void()> a_fn);

	PluginHandle GetPluginHandle() noexcept;

	const TrampolineInterface* GetTrampolineInterface() noexcept;
	const MessagingInterface*  GetMessagingInterface() noexcept;

	Trampoline& GetTrampoline();
	void        AllocTrampoline(std::size_t a_size, bool a_trySFSEReserve = true);
}  // namespace SFSE
