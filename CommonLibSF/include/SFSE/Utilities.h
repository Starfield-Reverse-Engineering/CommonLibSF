#pragma once

#include "REL/Relocation.h"
#include "SFSE/API.h"

namespace SFSE::stl
{
	template <class T, std::size_t Size = 5>
	constexpr void write_thunk_call(const std::uintptr_t a_address) noexcept
	{
		SFSE::AllocTrampoline(14);
		auto& trampoline = SFSE::GetTrampoline();
		T::func = trampoline.write_call<Size>(a_address, T::thunk);
	}

	template <class T, std::size_t Size = 5>
	constexpr void write_thunk_call() noexcept
	{
		write_thunk_call<T, Size>(T::address);
	}

	template <class T>
	constexpr void write_vfunc(const REL::ID a_id) noexcept
	{
		REL::Relocation<std::uintptr_t> vtbl{ a_id };
		T::func = vtbl.write_vfunc(T::idx, T::thunk);
	}

	template <class To, class From>
	constexpr void write_vfunc(const std::size_t a_vtableIdx = 0) noexcept
	{
		write_vfunc<From>(To::VTABLE[a_vtableIdx]);
	}
}
