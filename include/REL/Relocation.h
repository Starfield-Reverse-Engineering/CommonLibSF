#pragma once

#include "REL/ID.h"
#include "REL/Module.h"
#include "REL/Offset.h"

#include "SFSE/Trampoline.h"

#define REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL(a_nopropQual, a_propQual, ...)              \
	template <class R, class Cls, class... Args>                                                  \
	struct member_function_pod_type<R (Cls::*)(Args...) __VA_ARGS__ a_nopropQual a_propQual>      \
	{                                                                                             \
		using type = R(__VA_ARGS__ Cls*, Args...) a_propQual;                                     \
	};                                                                                            \
                                                                                                  \
	template <class R, class Cls, class... Args>                                                  \
	struct member_function_pod_type<R (Cls::*)(Args..., ...) __VA_ARGS__ a_nopropQual a_propQual> \
	{                                                                                             \
		using type = R(__VA_ARGS__ Cls*, Args..., ...) a_propQual;                                \
	};

#define REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(a_qualifer, ...)              \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL(a_qualifer, , ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL(a_qualifer, noexcept, ##__VA_ARGS__)

#define REL_MAKE_MEMBER_FUNCTION_POD_TYPE(...)                 \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(, __VA_ARGS__)    \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(&, ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(&&, ##__VA_ARGS__)

#define REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL(a_nopropQual, a_propQual, ...)              \
	template <class R, class Cls, class... Args>                                                      \
	struct member_function_non_pod_type<R (Cls::*)(Args...) __VA_ARGS__ a_nopropQual a_propQual>      \
	{                                                                                                 \
		using type = R&(__VA_ARGS__ Cls*, void*, Args...)a_propQual;                                  \
	};                                                                                                \
                                                                                                      \
	template <class R, class Cls, class... Args>                                                      \
	struct member_function_non_pod_type<R (Cls::*)(Args..., ...) __VA_ARGS__ a_nopropQual a_propQual> \
	{                                                                                                 \
		using type = R&(__VA_ARGS__ Cls*, void*, Args..., ...)a_propQual;                             \
	};

#define REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(a_qualifer, ...)              \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL(a_qualifer, , ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL(a_qualifer, noexcept, ##__VA_ARGS__)

#define REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(...)                 \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(, __VA_ARGS__)    \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(&, ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(&&, ##__VA_ARGS__)

namespace REL
{
	namespace detail
	{
		template <class>
		struct member_function_pod_type;

		REL_MAKE_MEMBER_FUNCTION_POD_TYPE();
		REL_MAKE_MEMBER_FUNCTION_POD_TYPE(const);
		REL_MAKE_MEMBER_FUNCTION_POD_TYPE(volatile);
		REL_MAKE_MEMBER_FUNCTION_POD_TYPE(const volatile);

		template <class F>
		using member_function_pod_type_t = typename member_function_pod_type<F>::type;

		template <class>
		struct member_function_non_pod_type;

		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE();
		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(const);
		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(volatile);
		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(const volatile);

		template <class F>
		using member_function_non_pod_type_t = typename member_function_non_pod_type<F>::type;

		// https://docs.microsoft.com/en-us/cpp/build/x64-calling-convention

		template <class T>
		struct meets_length_req : std::disjunction<std::bool_constant<sizeof(T) == 1>, std::bool_constant<sizeof(T) == 2>, std::bool_constant<sizeof(T) == 4>, std::bool_constant<sizeof(T) == 8>>
		{};

		template <class T>
		struct meets_function_req : std::conjunction<std::is_trivially_constructible<T>, std::is_trivially_destructible<T>, std::is_trivially_copy_assignable<T>, std::negation<std::is_polymorphic<T>>>
		{};

		template <class T>
		struct meets_member_req : std::is_standard_layout<T>
		{};

		template <class T, class = void>
		struct is_x64_pod : std::true_type
		{};

		template <class T>
		struct is_x64_pod<T, std::enable_if_t<std::is_union_v<T>>> : std::false_type
		{};

		template <class T>
		struct is_x64_pod<T, std::enable_if_t<std::is_class_v<T>>> : std::conjunction<meets_length_req<T>, meets_function_req<T>, meets_member_req<T>>
		{};

		template <class T>
		static constexpr bool is_x64_pod_v = is_x64_pod<T>::value;

		template <class F, class First, class... Rest>
		constexpr decltype(auto) invoke_member_function_non_pod(F&& a_func, First&& a_first, Rest&&... a_rest)  //
			noexcept(std::is_nothrow_invocable_v<F, First, Rest...>)
		{
			using result_t = std::invoke_result_t<F, First, Rest...>;
			alignas(result_t) std::byte result[sizeof(result_t)]{};

			using func_t = member_function_non_pod_type_t<F>;
			auto func = std::bit_cast<func_t*>(std::forward<F>(a_func));

			return func(std::forward<First>(a_first), std::addressof(result), std::forward<Rest>(a_rest)...);
		}
	}

	inline constexpr std::uint8_t NOP = 0x90;
	inline constexpr std::uint8_t NOP2[] = { 0x66, 0x90 };
	inline constexpr std::uint8_t NOP3[] = { 0x0F, 0x1F, 0x00 };
	inline constexpr std::uint8_t NOP4[] = { 0x0F, 0x1F, 0x40, 0x00 };
	inline constexpr std::uint8_t NOP5[] = { 0x0F, 0x1F, 0x44, 0x00, 0x00 };
	inline constexpr std::uint8_t NOP6[] = { 0x66, 0x0F, 0x1F, 0x44, 0x00, 0x00 };
	inline constexpr std::uint8_t NOP7[] = { 0x0F, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00 };
	inline constexpr std::uint8_t NOP8[] = { 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };
	inline constexpr std::uint8_t NOP9[] = { 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };

	inline constexpr std::uint8_t JMP8 = 0xEB;
	inline constexpr std::uint8_t JMP32 = 0xE9;
	inline constexpr std::uint8_t RET = 0xC3;
	inline constexpr std::uint8_t INT3 = 0xCC;

	template <class T, class U>
	[[nodiscard]] auto AdjustPointer(U* a_ptr, const std::ptrdiff_t a_adjust) noexcept
	{
		auto addr = a_ptr ? reinterpret_cast<std::uintptr_t>(a_ptr) + a_adjust : 0;
		if constexpr (std::is_const_v<U> && std::is_volatile_v<U>) {
			return reinterpret_cast<std::add_cv_t<T>*>(addr);
		} else if constexpr (std::is_const_v<U>) {
			return reinterpret_cast<std::add_const_t<T>*>(addr);
		} else if constexpr (std::is_volatile_v<U>) {
			return reinterpret_cast<std::add_volatile_t<T>*>(addr);
		} else {
			return reinterpret_cast<T*>(addr);
		}
	}

	template <class T>
	bool EmplaceVTable(T* a_ptr)
	{
		auto address = T::VTABLE[0].address();
		if (address) {
			reinterpret_cast<std::uintptr_t*>(a_ptr)[0] = address;
			return true;
		}

		return true;
	}

	template <class F, class... Args>
	constexpr std::invoke_result_t<F, Args...> invoke(F&& a_func, Args&&... a_args)  //
		noexcept(std::is_nothrow_invocable_v<F, Args...>)
		requires(std::invocable<F, Args...>)
	{
		if constexpr (std::is_member_function_pointer_v<std::decay_t<F>>) {
			if constexpr (detail::is_x64_pod_v<std::invoke_result_t<F, Args...>>) {  // member functions == free functions in x64
				using func_t = detail::member_function_pod_type_t<std::decay_t<F>>;
				auto func = stl::unrestricted_cast<func_t*>(std::forward<F>(a_func));
				return func(std::forward<Args>(a_args)...);
			} else {  // shift args to insert result
				return detail::invoke_member_function_non_pod(std::forward<F>(a_func), std::forward<Args>(a_args)...);
			}
		} else {
			return std::forward<F>(a_func)(std::forward<Args>(a_args)...);
		}
	}

	inline void safe_write(const std::uintptr_t a_dst, const void* a_src, const std::size_t a_count)
	{
		std::uint32_t old{};
		auto          success = REX::W32::VirtualProtect(reinterpret_cast<void*>(a_dst), a_count, REX::W32::PAGE_EXECUTE_READWRITE, std::addressof(old));
		if (success) {
			std::memcpy(reinterpret_cast<void*>(a_dst), a_src, a_count);
			success = REX::W32::VirtualProtect(reinterpret_cast<void*>(a_dst), a_count, old, std::addressof(old));
		}

		assert(success);
	}

	template <std::integral T>
	constexpr void safe_write(const std::uintptr_t a_dst, const T& a_data)
	{
		safe_write(a_dst, std::addressof(a_data), sizeof(T));
	}

	template <class T>
	constexpr void safe_write(const std::uintptr_t a_dst, std::span<T> a_data)
	{
		safe_write(a_dst, a_data.data(), a_data.size_bytes());
	}

	inline void safe_fill(const std::uintptr_t a_dst, const std::uint8_t a_value, const std::size_t a_count)
	{
		std::uint32_t old{};
		auto          success = REX::W32::VirtualProtect(reinterpret_cast<void*>(a_dst), a_count, REX::W32::PAGE_EXECUTE_READWRITE, std::addressof(old));
		if (success) {
			std::fill_n(reinterpret_cast<std::uint8_t*>(a_dst), a_count, a_value);
			success = REX::W32::VirtualProtect(reinterpret_cast<void*>(a_dst), a_count, old, std::addressof(old));
		}

		assert(success);
	};

	template <typename T = std::uintptr_t>
	class Relocation
	{
	public:
		using value_type = std::conditional_t<std::is_member_pointer_v<T> || std::is_function_v<std::remove_pointer_t<T>>, std::decay_t<T>, T>;

		constexpr Relocation() noexcept = default;

		explicit constexpr Relocation(const std::uintptr_t a_addr) noexcept :
			_address(a_addr)
		{}

		explicit constexpr Relocation(const Offset a_rva) noexcept :
			_address(a_rva.address())
		{}

		explicit constexpr Relocation(const Offset a_rva, const std::ptrdiff_t a_offset) noexcept :
			_address(a_rva.address() + a_offset)
		{}

		explicit constexpr Relocation(const ID a_id) noexcept :
			_address(a_id.address())
		{}

		explicit constexpr Relocation(const ID a_id, const std::ptrdiff_t a_offset) noexcept :
			_address(a_id.address() + a_offset)
		{}

		constexpr auto& operator=(const std::uintptr_t a_addr)
		{
			_address = a_addr;
			return *this;
		}

		[[nodiscard]] constexpr decltype(auto) operator*() const noexcept
			requires(std::is_pointer_v<value_type>)
		{
			return *get();
		}

		[[nodiscard]] constexpr auto operator->() const noexcept
			requires(std::is_pointer_v<value_type>)
		{
			return get();
		}

		template <class... Args>
		constexpr std::invoke_result_t<const value_type&, Args...> operator()(Args&&... a_args) const
			noexcept(std::is_nothrow_invocable_v<const value_type&, Args...>)
			requires(std::invocable<const value_type&, Args...>)
		{
			return invoke(get(), std::forward<Args>(a_args)...);
		}

		[[nodiscard]] constexpr decltype(auto) address() const noexcept { return _address; }
		[[nodiscard]] constexpr std::size_t    offset() const noexcept { return _address - base(); }

		[[nodiscard]] constexpr value_type get() const
			noexcept(std::is_nothrow_copy_constructible_v<value_type>)
		{
			return stl::unrestricted_cast<value_type>(_address);
		}

		template <std::ptrdiff_t O = 0>
		void replace_func(const std::size_t a_count, const std::uintptr_t a_dst)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
#pragma pack(push, 1)
			struct Assembly
			{
				std::uint8_t  jmp;
				std::uint8_t  modrm;
				std::int32_t  disp;
				std::uint64_t addr;
			};
			static_assert(sizeof(Assembly) == 0xE);
#pragma pack(pop)

			Assembly assembly{
				.jmp = static_cast<std::uint8_t>(0xFF),
				.modrm = static_cast<std::uint8_t>(0x25),
				.disp = static_cast<std::int32_t>(0),
				.addr = static_cast<std::uint64_t>(a_dst),
			};

			safe_fill(address() + O, INT3, a_count);
			safe_write(address() + O, &assembly, sizeof(assembly));
		}

		template <std::ptrdiff_t O = 0, class F>
		void replace_func(const std::size_t a_count, const F a_dst)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			replace_func<O>(a_count, stl::unrestricted_cast<std::uintptr_t>(a_dst));
		}

		void write(const void* a_src, std::size_t a_count)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			safe_write(address(), a_src, a_count);
		}

		template <std::integral U>
		void write(const U& a_data)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			safe_write(address(), std::addressof(a_data), sizeof(U));
		}

		void write(const std::initializer_list<std::uint8_t> a_data)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			safe_write(address(), a_data.begin(), a_data.size());
		}

		template <class U>
		void write(const std::span<U> a_data)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			safe_write(address(), a_data.data(), a_data.size_bytes());
		}

		template <std::size_t N, std::ptrdiff_t O = 0>
		std::uintptr_t write_branch(const std::uintptr_t a_dst)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			return SFSE::GetTrampoline().write_branch<N>(address() + O, a_dst);
		}

		template <std::size_t N, std::ptrdiff_t O = 0, class F>
		std::uintptr_t write_branch(const F a_dst)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			return SFSE::GetTrampoline().write_branch<N>(address() + O, stl::unrestricted_cast<std::uintptr_t>(a_dst));
		}

		template <std::size_t N, std::ptrdiff_t O = 0>
		std::uintptr_t write_call(const std::uintptr_t a_dst)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			return SFSE::GetTrampoline().write_call<N>(address() + O, a_dst);
		}

		template <std::size_t N, std::ptrdiff_t O = 0, class F>
		std::uintptr_t write_call(const F a_dst)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			return SFSE::GetTrampoline().write_call<N>(address() + O, stl::unrestricted_cast<std::uintptr_t>(a_dst));
		}

		void write_fill(const std::uint8_t a_value, const std::size_t a_count)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			safe_fill(address(), a_value, a_count);
		}

		constexpr std::uintptr_t write_vfunc(const std::size_t a_idx, const std::uintptr_t a_newFunc)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			const auto addr = address() + (sizeof(void*) * a_idx);
			const auto result = *std::bit_cast<std::uintptr_t*>(addr);
			safe_write(addr, a_newFunc);
			return result;
		}

		template <class F>
		constexpr std::uintptr_t write_vfunc(const std::size_t a_idx, F a_newFunc)
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			return write_vfunc(a_idx, stl::unrestricted_cast<std::uintptr_t>(a_newFunc));
		}

	private:
		[[nodiscard]] static constexpr std::uintptr_t base()
		{
			return Module::get().base();
		}

		std::uintptr_t _address{};
	};
}

#undef REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE
#undef REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER
#undef REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL

#undef REL_MAKE_MEMBER_FUNCTION_POD_TYPE
#undef REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER
#undef REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL
