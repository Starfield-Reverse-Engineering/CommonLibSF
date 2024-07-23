#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	template <class T1, class T2, class T3>
	struct BSTTuple3
	{
	public:
		using first_type = T1;
		using second_type = T2;
		using third_type = T3;

		BSTTuple3()  //
			noexcept(std::is_nothrow_default_constructible_v<first_type> &&
					 std::is_nothrow_default_constructible_v<second_type> &&
					 std::is_nothrow_default_constructible_v<third_type>)  //
			requires(std::is_default_constructible_v<first_type> &&
						std::is_default_constructible_v<second_type> &&
						std::is_default_constructible_v<third_type>)
			:
			first(),
			second(),
			third()
		{}

		explicit(!std::is_convertible_v<const first_type&, first_type> ||
				 !std::is_convertible_v<const second_type&, second_type> ||
				 !std::is_convertible_v<const third_type&, third_type>)                                   //
			BSTTuple3(const first_type& a_first, const second_type& a_second, const third_type& a_third)  //
			noexcept(std::is_nothrow_copy_constructible_v<first_type> &&
					 std::is_nothrow_copy_constructible_v<second_type> &&
					 std::is_nothrow_copy_constructible_v<third_type>)  //
			requires(std::is_copy_constructible_v<first_type> &&
						std::is_copy_constructible_v<second_type> &&
						std::is_copy_constructible_v<third_type>)
			:
			first(a_first),
			second(a_second),
			third(a_third)
		{}

		template <class U1, class U2, class U3>
		explicit(!std::is_convertible_v<U1&&, first_type> ||
				 !std::is_convertible_v<U2&&, second_type> ||
				 !std::is_convertible_v<U3&&, third_type>)        //
			BSTTuple3(U1&& a_first, U2&& a_second, U3&& a_third)  //
			noexcept(std::is_nothrow_constructible_v<first_type, U1&&> &&
					 std::is_nothrow_constructible_v<second_type, U2&&> &&
					 std::is_nothrow_constructible_v<third_type, U3&&>)  //
			requires(std::is_constructible_v<first_type, U1 &&> &&
						std::is_constructible_v<second_type, U2 &&> &&
						std::is_constructible_v<third_type, U3 &&>)
			:
			first(std::forward<U1>(a_first)),
			second(std::forward<U2>(a_second)),
			third(std::forward<U3>(a_third))
		{}

		template <class U1, class U2, class U3>
		explicit(!std::is_convertible_v<const U1&, first_type> ||
				 !std::is_convertible_v<const U2&, second_type> ||
				 !std::is_convertible_v<const U3&, third_type>)  //
			BSTTuple3(const BSTTuple3<U1, U2, U3>& a_rhs)        //
			noexcept(std::is_nothrow_constructible_v<first_type, const U1&> &&
					 std::is_nothrow_constructible_v<second_type, const U2&> &&
					 std::is_nothrow_constructible_v<third_type, const U3&>)  //
			requires(std::is_constructible_v<first_type, const U1&> &&
						std::is_constructible_v<second_type, const U2&> &&
						std::is_constructible_v<third_type, const U3&>)
			:
			first(a_rhs.first),
			second(a_rhs.second),
			third(a_rhs.third)
		{}

		template <class U1, class U2, class U3>
		explicit(!std::is_convertible_v<U1&&, first_type> ||
				 !std::is_convertible_v<U2&&, second_type> ||
				 !std::is_convertible_v<U3&&, third_type>)  //
			BSTTuple3(BSTTuple3<U1, U2, U3>&& a_rhs)        //
			noexcept(std::is_nothrow_constructible_v<first_type, U1&&> &&
					 std::is_nothrow_constructible_v<second_type, U2&&> &&
					 std::is_nothrow_constructible_v<third_type, U3&&>)  //
			requires(std::is_constructible_v<first_type, U1 &&> &&
						std::is_constructible_v<second_type, U2 &&> &&
						std::is_constructible_v<third_type, U3 &&>)
			:
			first(std::forward<U1>(a_rhs.first)),
			second(std::forward<U2>(a_rhs.second)),
			third(std::forward<U3>(a_rhs.third))
		{}

		template <
			class... Args1,
			class... Args2,
			class... Args3>
		BSTTuple3(std::piecewise_construct_t, std::tuple<Args1...> a_firstArgs, std::tuple<Args2...> a_secondArgs, std::tuple<Args3...> a_thirdArgs) :
			BSTTuple3(a_firstArgs, a_secondArgs, a_thirdArgs, std::index_sequence_for<Args1...>(), std::index_sequence_for<Args2...>(), std::index_sequence_for<Args3...>())
		{}

	private:
		template <
			class Tuple1,
			class Tuple2,
			class Tuple3,
			std::size_t... I1,
			std::size_t... I2,
			std::size_t... I3>
		BSTTuple3(Tuple1& a_firstArgs, Tuple2& a_secondArgs, Tuple3& a_thirdArgs, std::index_sequence<I1...>, std::index_sequence<I2...>, std::index_sequence<I3...>) :
			first(std::get<I1>(std::move(a_firstArgs))...),
			second(std::get<I2>(std::move(a_secondArgs))...),
			third(std::get<I3>(std::move(a_thirdArgs))...)
		{}

	public:
		BSTTuple3(const BSTTuple3&) = default;
		BSTTuple3(BSTTuple3&&) = default;

		~BSTTuple3() = default;

		BSTTuple3& operator=(const BSTTuple3& a_rhs)  //
			noexcept(std::is_nothrow_copy_assignable_v<first_type> &&
					 std::is_nothrow_copy_assignable_v<second_type> &&
					 std::is_nothrow_copy_assignable_v<third_type>)  //
			requires(std::is_copy_assignable_v<first_type> &&
					 std::is_copy_assignable_v<second_type> &&
					 std::is_copy_assignable_v<third_type>)
		{
			if (this != std::addressof(a_rhs)) {
				first = a_rhs.first;
				second = a_rhs.second;
				third = a_rhs.third;
			}
			return *this;
		}

		template <class U1, class U2, class U3>
		BSTTuple3& operator=(const BSTTuple3<U1, U2, U3>& a_rhs)  //
			noexcept(std::is_nothrow_assignable_v<first_type&, const U1&> &&
					 std::is_nothrow_assignable_v<second_type&, const U2&> &&
					 std::is_nothrow_assignable_v<third_type&, const U3&>)  //
			requires(std::is_assignable_v<first_type&, const U1&> &&
					 std::is_assignable_v<second_type&, const U2&> &&
					 std::is_assignable_v<third_type&, const U3&>)
		{
			first = a_rhs.first;
			second = a_rhs.second;
			third = a_rhs.third;
			return *this;
		}

		BSTTuple3& operator=(BSTTuple3&& a_rhs)  //
			noexcept(std::is_nothrow_move_assignable_v<first_type> &&
					 std::is_nothrow_move_assignable_v<second_type> &&
					 std::is_nothrow_move_assignable_v<third_type>)  //
			requires(std::is_move_assignable_v<first_type> &&
					 std::is_move_assignable_v<second_type> &&
					 std::is_move_assignable_v<third_type>)
		{
			if (this != std::addressof(a_rhs)) {
				first = std::move(a_rhs.first);
				second = std::move(a_rhs.second);
				third = std::move(a_rhs.third);
			}
			return *this;
		}

		template <class U1, class U2, class U3>
		BSTTuple3& operator=(BSTTuple3<U1, U2, U3>&& a_rhs)  //
			noexcept(std::is_nothrow_assignable_v<first_type&, U1> &&
					 std::is_nothrow_assignable_v<second_type&, U2> &&
					 std::is_nothrow_assignable_v<third_type&, U3>)  //
			requires(std::is_assignable_v<first_type&, U1> &&
					 std::is_assignable_v<second_type&, U2> &&
					 std::is_assignable_v<third_type&, U3>)
		{
			first = std::move(a_rhs.first);
			second = std::move(a_rhs.second);
			third = std::move(a_rhs.third);
			return *this;
		}

		SF_HEAP_REDEFINE_NEW(BSTTuple3<T1, T2, T3>);

		void swap(BSTTuple3& a_rhs)  //
			noexcept(std::is_nothrow_swappable_v<first_type> &&
					 std::is_nothrow_swappable_v<second_type> &&
					 std::is_nothrow_swappable_v<third_type>)
		{
			using std::swap;
			if (this != std::addressof(a_rhs)) {
				swap(first, a_rhs.first);
				swap(second, a_rhs.second);
				swap(third, a_rhs.third);
			}
		}

		// members
		first_type  first;   // 00
		second_type second;  // ??
		third_type  third;   // ??
	};

	template <class T1, class T2, class T3>
	[[nodiscard]] auto make_tuple(T1&& a_first, T2&& a_second, T3&& a_third)
	{
		using result_t =
			BSTTuple3<
				std::decay_t<T1>,
				std::decay_t<T2>,
				std::decay_t<T3>>;
		return result_t(std::forward<T1>(a_first), std::forward<T2>(a_second), std::forward<T3>(a_third));
	}

	template <class T1, class T2, class T3>
	[[nodiscard]] bool operator==(const BSTTuple3<T1, T2, T3>& a_lhs, const BSTTuple3<T1, T2, T3>& a_rhs)
	{
		return a_lhs.first == a_rhs.first && a_lhs.second == a_rhs.second && a_lhs.third == a_rhs.third;
	}

	template <class T1, class T2, class T3>
	[[nodiscard]] bool operator<(const BSTTuple3<T1, T2, T3>& a_lhs, const BSTTuple3<T1, T2, T3>& a_rhs)
	{
		return a_lhs.first < a_rhs.first   ? true :
		       a_rhs.first < a_lhs.first   ? false :
		       a_lhs.second < a_rhs.second ? true :
		       a_rhs.second < a_lhs.second ? false :
		       a_lhs.third < a_rhs.third   ? true :
		                                     false;
	}

	template <class T1, class T2, class T3>
	void swap(BSTTuple3<T1, T2, T3>& a_lhs, BSTTuple3<T1, T2, T3>& a_rhs)  //
		noexcept(noexcept(a_lhs.swap(a_rhs)))                              //
		requires(std::is_swappable_v<T1> &&
				 std::is_swappable_v<T2> &&
				 std::is_swappable_v<T3>)
	{
		a_lhs.swap(a_rhs);
	}

	template <class T1, class T2, class T3>
	BSTTuple3(T1, T2, T3) -> BSTTuple3<T1, T2, T3>;
}
