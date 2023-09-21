#pragma once

#include "REL/Relocation.h"
#include "SFSE/API.h"

namespace SFSE
{
	namespace stl
	{
		template <class T, std::size_t Size = 5>
		constexpr void write_thunk_call(const std::uintptr_t a_address) noexcept
		{
			SFSE::AllocTrampoline(14);
			auto& trampoline = SFSE::GetTrampoline();
			T::func = trampoline.write_call<Size>(a_address, T::Thunk);
		}
		
		template <class T, std::size_t Size = 5>
		constexpr void write_thunk_call() noexcept
		{
			write_thunk_call<T, Size>(T::address);
		}

		template <class T>
		constexpr void write_vfunc(const REL::Offset a_offset) noexcept
		{
			REL::Relocation<std::uintptr_t> vtbl{ a_offset };
			T::func = vtbl.write_vfunc(T::idx, T::Thunk);
		}

		template <class To, class From>
		constexpr void write_vfunc(const std::size_t a_vtable_idx) noexcept
		{
			write_vfunc<From>(To::VTABLE[a_vtable_idx]);
		}

		template <class To, class From>
		constexpr void write_vfunc() noexcept
		{
			write_vfunc<From>(To::VTABLE[0]);
		}
	}  // namespace stl
}  // namespace SFSE
