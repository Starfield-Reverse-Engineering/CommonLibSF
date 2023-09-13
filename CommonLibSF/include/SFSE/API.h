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

	namespace stl
	{
		template <typename T>
		constexpr void write_thunk_call() noexcept
		{
			SFSE::AllocTrampoline(14);
			auto& trampoline{ SFSE::GetTrampoline() };
			T::func = trampoline.write_call<5>(T::address, T::Thunk);
		}

		template <typename TDest, typename TSource>
		constexpr void write_vfunc() noexcept
		{
			REL::Relocation vtbl{ TDest::VTABLE[0] };
			TSource::func = vtbl.write_vfunc(TSource::idx, TSource::Thunk);
		}

		template <typename T>
		constexpr void write_vfunc(const REL::Offset a_offset) noexcept
		{
			REL::Relocation vtbl{ a_offset };
			T::func = vtbl.write_vfunc(T::idx, T::Thunk);
		}
	}
}  // namespace SFSE
