#pragma once

#include "REL/Relocation.h"
#include "SFSE/API.h"

namespace SFSE::stl
{
	template <class T, std::size_t Size = 5>
	constexpr void write_thunk_call(const std::uintptr_t a_address) noexcept
	{
		AllocTrampoline(14);
		auto& trampoline = GetTrampoline();
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
		static REL::Relocation<std::uintptr_t> vtbl{ a_id };
		T::func = vtbl.write_vfunc(T::idx, T::thunk);
	}

	template <class To, class From>
	constexpr void write_vfunc(const std::size_t a_vtableIdx = 0) noexcept
	{
		write_vfunc<From>(To::VTABLE[a_vtableIdx]);
	}

	template <class T, std::size_t Size = 5>
	constexpr void write_thunk_jump(const std::uintptr_t a_src) noexcept
	{
		AllocTrampoline(14);
		auto& trampoline = GetTrampoline();
		T::func = trampoline.write_branch<Size>(a_src, T::thunk);
	}

	namespace detail
	{
		template <class T>
		struct is_chrono_duration : std::false_type
		{};

		template <class Rep, class Duration>
		struct is_chrono_duration<std::chrono::duration<Rep, Duration>> : std::true_type
		{};

		template <typename T>
		concept is_duration = is_chrono_duration<T>::value;
	}

	void add_thread_task(const std::function<void()> a_fn, detail::is_duration auto a_wait_for = 0ms) noexcept
	{
		std::jthread([=] {
			std::this_thread::sleep_for(a_wait_for);
			GetTaskInterface()->AddTask(a_fn);
		}).detach();
	}

	void add_thread_task_permanent(const std::function<void()> a_fn, detail::is_duration auto a_wait_for = 0ms) noexcept
	{
		std::jthread([=] {
			std::this_thread::sleep_for(a_wait_for);
			GetTaskInterface()->AddPermanentTask(a_fn);
		}).detach();
	}
}
