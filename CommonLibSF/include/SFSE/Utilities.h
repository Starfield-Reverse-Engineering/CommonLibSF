#pragma once

#include "REL/Relocation.h"
#include "SFSE/API.h"

namespace SFSE
{
	namespace stl
	{
		template <class T, std::size_t Size = 5>
		constexpr void write_thunk_call() noexcept
		{
			SFSE::AllocTrampoline(14);
			auto& trampoline = SFSE::GetTrampoline();
			T::func = trampoline.write_call<Size>(T::address, T::Thunk);
		}

		template <class To, class From>
		constexpr void write_vfunc() noexcept
		{
			REL::Relocation<std::uintptr_t> vtbl{ To::VTABLE[0] };
			From::func = vtbl.write_vfunc(From::idx, From::Thunk);
		}

		template <class To, class From>
		constexpr void write_vfunc(const std::size_t a_vtable_idx) noexcept
		{
			REL::Relocation<std::uintptr_t> vtbl{ To::VTABLE[a_vtable_idx] };
			From::func = vtbl.write_vfunc(From::idx, From::Thunk);
		}

		template <class T>
		constexpr void write_vfunc(const REL::Offset a_offset) noexcept
		{
			REL::Relocation<std::uintptr_t> vtbl{ a_offset };
			T::func = vtbl.write_vfunc(T::idx, T::Thunk);
		}
	}  // namespace stl
}  // namespace SFSE
