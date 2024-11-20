#pragma once

#include "REL/Relocation.h"
#include "SFSE/API.h"

namespace SFSE::stl
{
	template <class T, std::size_t N = 5>
	constexpr void write_thunk_call(const std::uintptr_t a_address) noexcept
	{
		T::func = GetTrampoline().write_call<N>(a_address, T::thunk);
	}

	template <class T, std::size_t N = 5, class U>
	constexpr void write_thunk_call(const U a_id) noexcept
		requires(std::is_same_v<U, REL::ID> || std::is_same_v<U, REL::Offset>)
	{
		T::func = GetTrampoline().write_call<N>(a_id.address(), T::thunk);
	}

	template <class T, std::size_t N = 5, class U>
	constexpr void write_thunk_call(const REL::Relocation<U> a_id) noexcept
		requires(std::is_same_v<typename REL::Relocation<U>::value_type, std::uintptr_t>)
	{
		T::func = GetTrampoline().write_call<N>(a_id.address(), T::thunk);
	}

	template <class T, std::size_t N = 5>
	constexpr void write_thunk_call() noexcept
	{
		write_thunk_call<T, N>(T::address);
	}

	template <class T, std::size_t N = 5>
	constexpr void write_thunk_jump(const std::uintptr_t a_address) noexcept
	{
		T::func = GetTrampoline().write_branch<N>(a_address, T::thunk);
	}

	template <class T, std::size_t N = 5, class U>
	constexpr void write_thunk_jump(const U a_id) noexcept
		requires(std::is_same_v<U, REL::ID> || std::is_same_v<U, REL::Offset>)
	{
		T::func = GetTrampoline().write_branch<N>(a_id.address(), T::thunk);
	}

	template <class T, std::size_t N = 5, class U>
	constexpr void write_thunk_jump(const REL::Relocation<U> a_id) noexcept
		requires(std::is_same_v<typename REL::Relocation<U>::value_type, std::uintptr_t>)
	{
		T::func = GetTrampoline().write_branch<N>(a_id.address(), T::thunk);
	}

	template <class T, std::size_t N = 5>
	constexpr void write_thunk_jump() noexcept
	{
		write_thunk_jump<T, N>(T::address);
	}

	template <class T>
	constexpr void write_vfunc(const std::uintptr_t a_address) noexcept
	{
		static REL::Relocation vtbl{ REL::Offset(a_address) };
		T::func = vtbl.write_vfunc(T::idx, T::thunk);
	}

	template <class T, class U>
	constexpr void write_vfunc(const U a_id) noexcept
		requires(std::is_same_v<U, REL::ID> || std::is_same_v<U, REL::Offset>)
	{
		static REL::Relocation vtbl{ a_id };
		T::func = vtbl.write_vfunc(T::idx, T::thunk);
	}

	template <class T, class U>
	constexpr void write_vfunc(const REL::Relocation<U> a_id) noexcept
		requires(std::is_same_v<typename REL::Relocation<U>::value_type, std::uintptr_t>)
	{
		T::func = a_id.write_vfunc(T::idx, T::thunk);
	}

	template <class To, class From>
	constexpr void write_vfunc(const std::size_t a_vtableIdx = 0) noexcept
	{
		write_vfunc<From>(To::VTABLE[a_vtableIdx]);
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
