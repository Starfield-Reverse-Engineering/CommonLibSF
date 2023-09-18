#pragma once

#include "SFSE/Impl/Stubs.h"
#include "SFSE/Interfaces.h"
#include "SFSE/Trampoline.h"

#define SFSEAPI __cdecl

namespace SFSE
{
	void Init(const LoadInterface* a_intfc, bool a_log = true) noexcept;
	void RegisterForAPIInitEvent(std::function<void()> a_fn);

	[[nodiscard]] PluginHandle GetPluginHandle() noexcept;
	// NOTE: SFSE does not include GetReleaseIndex() yet, declaration and definition are preserved for future-proofing
	// [[nodiscard]] std::uint32_t GetReleaseIndex() noexcept;

	[[nodiscard]] const TrampolineInterface* GetTrampolineInterface() noexcept;
	[[nodiscard]] const MessagingInterface*  GetMessagingInterface() noexcept;

	[[nodiscard]] Trampoline& GetTrampoline();
	void                      AllocTrampoline(std::size_t a_size, bool a_trySFSEReserve = true);

	namespace stl  // this was put here to avoid #include hell
	{
		template <class T, std::size_t Size = 5>
		constexpr auto write_thunk_call() noexcept
		{
			AllocTrampoline(14);
			auto& trampoline = GetTrampoline();
			T::func = trampoline.write_call<Size>(T::address, T::Thunk);
		}

		template <class To, class From>
		constexpr auto write_vfunc() noexcept
		{
			REL::Relocation<std::uintptr_t> vtbl{ To::VTABLE[0] };
			From::func = vtbl.write_vfunc(From::idx, From::Thunk);
		}

		template <class To, class From>
		constexpr auto write_vfunc(const std::size_t a_vtable_idx) noexcept
		{
			REL::Relocation<std::uintptr_t> vtbl{ To::VTABLE[a_vtable_idx] };
			From::func = vtbl.write_vfunc(From::idx, From::Thunk);
		}

		template <class T>
		constexpr auto write_vfunc(const REL::Offset a_offset) noexcept
		{
			REL::Relocation<std::uintptr_t> vtbl{ a_offset };
			T::func = vtbl.write_vfunc(T::idx, T::Thunk);
		}
	}  // namespace stl
}  // namespace SFSE
