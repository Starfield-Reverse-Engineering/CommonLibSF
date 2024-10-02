#pragma once

namespace RE
{
	template <class T>
	class BSTOptional
	{
	public:
		using value_type = T;

		// 1a)
		constexpr BSTOptional() noexcept = default;

		// 1b)
		constexpr BSTOptional(std::nullopt_t) noexcept {}

		// 2) non-trivial
		constexpr BSTOptional(const BSTOptional& a_rhs)                 //
			noexcept(std::is_nothrow_copy_constructible_v<value_type>)  //
			requires(std::is_copy_constructible_v<value_type> &&
					 !std::is_trivially_copy_constructible_v<value_type>)
		{
			if (a_rhs.has_value()) {
				std::construct_at(std::addressof(_value), a_rhs.value());
				_active = true;
			}
		}

		// 2) trivial
		constexpr BSTOptional(const BSTOptional&)
			requires(std::is_trivially_copy_constructible_v<value_type>)
		= default;

		// 2) trivial
		constexpr BSTOptional(BSTOptional&&)
			requires(std::is_trivially_move_constructible_v<value_type>)
		= default;

		// 3) non-trivial
		constexpr BSTOptional(BSTOptional&& a_rhs)                      //
			noexcept(std::is_nothrow_move_constructible_v<value_type>)  //
			requires(std::is_move_constructible_v<value_type> &&
					 !std::is_trivially_move_constructible_v<value_type>)
		{
			if (a_rhs.has_value()) {
				std::construct_at(std::addressof(_value), std::move(a_rhs).value());
				_active = true;
			}
		}

		// 4)
		template <class U>
		explicit(!std::is_convertible_v<const U&, value_type>)               //
			BSTOptional(const BSTOptional<U>& a_rhs)                         //
			noexcept(std::is_nothrow_constructible_v<value_type, const U&>)  //
			requires(std::is_constructible_v<value_type, const U&> &&
					 !std::is_constructible_v<value_type, BSTOptional<U>&> &&
					 !std::is_constructible_v<value_type, const BSTOptional<U>&> &&
					 !std::is_constructible_v<value_type, BSTOptional<U> &&> &&
					 !std::is_constructible_v<value_type, const BSTOptional<U> &&> &&
					 !std::is_convertible_v<BSTOptional<U>&, value_type> &&
					 !std::is_convertible_v<const BSTOptional<U>&, value_type> &&
					 !std::is_convertible_v<BSTOptional<U> &&, value_type> &&
					 !std::is_convertible_v<const BSTOptional<U> &&, value_type>)
		{
			if (a_rhs.has_value()) {
				std::construct_at(std::addressof(_value), a_rhs.value());
				_active = true;
			}
		}

		// 5)
		template <class U>
		explicit(!std::is_convertible_v<U&&, T>)                        //
			BSTOptional(BSTOptional<U>&& a_rhs)                         //
			noexcept(std::is_nothrow_constructible_v<value_type, U&&>)  //
			requires(std::is_constructible_v<value_type, U &&> &&
					 !std::is_constructible_v<value_type, BSTOptional<U>&> &&
					 !std::is_constructible_v<value_type, const BSTOptional<U>&> &&
					 !std::is_constructible_v<value_type, BSTOptional<U> &&> &&
					 !std::is_constructible_v<value_type, const BSTOptional<U> &&> &&
					 !std::is_convertible_v<BSTOptional<U>&, value_type> &&
					 !std::is_convertible_v<const BSTOptional<U>&, value_type> &&
					 !std::is_convertible_v<BSTOptional<U> &&, value_type> &&
					 !std::is_convertible_v<const BSTOptional<U> &&, value_type>)
		{
			if (a_rhs.has_value()) {
				std::construct_at(std::addressof(_value), std::move(a_rhs).value());
				_active = true;
			}
		}

		// 6)
		template <class... Args>
		constexpr explicit BSTOptional(std::in_place_t, Args&&... a_args)     //
			noexcept(std::is_nothrow_constructible_v<value_type, Args&&...>)  //
			requires(std::is_constructible_v<value_type, Args && ...>)
		{
			std::construct_at(std::addressof(_value), std::forward<Args>(a_args)...);
			_active = true;
		}

		// 7)
		template <class U, class... Args>
		constexpr explicit BSTOptional(std::in_place_t, std::initializer_list<U> a_ilist, Args&&... a_args)  //
			noexcept(std::is_nothrow_constructible_v<value_type, std::initializer_list<U>&, Args&&...>)      //
			requires(std::is_constructible_v<value_type, std::initializer_list<U>&, Args && ...>)
		{
			std::construct_at(std::addressof(_value), a_ilist, std::forward<Args>(a_args)...);
			_active = true;
		}

		// 8)
		template <class U = value_type>
		constexpr explicit(!std::is_convertible_v<U&&, value_type>)     //
			BSTOptional(U&& a_value)                                    //
			noexcept(std::is_nothrow_constructible_v<value_type, U&&>)  //
			requires(std::is_constructible_v<value_type, U &&> &&
					 !std::same_as<std::remove_cvref_t<U>, std::in_place_t> &&
					 !std::same_as<std::remove_cvref_t<U>, BSTOptional<value_type>>)
		{
			std::construct_at(std::addressof(_value), std::forward<U>(a_value));
			_active = true;
		}

		// non-trivial
		~BSTOptional()                                            //
			noexcept(std::is_nothrow_destructible_v<value_type>)  //
			requires(!std::is_trivially_destructible_v<value_type>)
		{
			reset();
		}

		// trivial
		~BSTOptional()
			requires(std::is_trivially_destructible_v<value_type>)
		= default;

		// 1)
		BSTOptional& operator=(std::nullopt_t)  //
			noexcept(noexcept(reset()))
		{
			reset();
			return *this;
		}

		// 2) defined
		constexpr BSTOptional& operator=(const BSTOptional& a_rhs)  //
			noexcept((std::is_nothrow_destructible_v<value_type> &&
					  std::is_nothrow_copy_constructible_v<value_type> &&
					  std::is_nothrow_copy_assignable_v<value_type>))  //
			requires((std::is_copy_constructible_v<value_type> &&
					  std::is_copy_assignable_v<value_type>))
		{
			if (this != std::addressof(a_rhs)) {
				if (a_rhs.has_value()) {
					if (has_value()) {
						_value = a_rhs.value();
					} else {
						std::construct_at(std::addressof(_value), a_rhs.value());
						_active = true;
					}
				} else if (has_value()) {
					do_reset();
				}
			}
			return *this;
		}

		// 2) deleted
		BSTOptional& operator=(const BSTOptional&)  //
			requires(!std::is_copy_constructible_v<value_type> ||
						!std::is_copy_assignable_v<value_type>)
		= delete;

		// 3) defined
		constexpr BSTOptional& operator=(BSTOptional&& a_rhs)  //
			noexcept((std::is_nothrow_destructible_v<value_type> &&
					  std::is_nothrow_move_constructible_v<value_type> &&
					  std::is_nothrow_move_assignable_v<value_type>))  //
			requires((std::is_move_constructible_v<value_type> &&
					  std::is_move_assignable_v<value_type>))
		{
			if (this != std::addressof(a_rhs)) {
				if (a_rhs.has_value()) {
					if (has_value()) {
						_value = std::move(a_rhs).value();
					} else {
						std::construct_at(std::addressof(_value), std::move(a_rhs).value());
						_active = true;
					}
				} else if (has_value()) {
					do_reset();
				}
			}
			return *this;
		}

		// 3) deleted
		BSTOptional& operator=(BSTOptional&&)  //
			requires(!std::is_move_constructible_v<value_type> ||
						!std::is_move_assignable_v<value_type>)
		= delete;

		// 4)
		template <class U = value_type>
		BSTOptional& operator=(U&& a_value)  //
			noexcept((std::is_nothrow_destructible_v<value_type> &&
					  std::is_nothrow_constructible_v<value_type, U&&> &&
					  std::is_nothrow_assignable_v<value_type&, U&&>))  //
			requires(!std::same_as<std::remove_cvref_t<U>, BSTOptional<value_type>> &&
					 std::is_constructible_v<value_type, U &&> &&
					 std::is_assignable_v<value_type&, U &&> &&
					 (!std::is_scalar_v<value_type> || !std::same_as<std::decay_t<U>, T>))
		{
			if (has_value()) {
				_value = std::forward<U>(a_value);
			} else {
				std::construct_at(std::addressof(_value), std::forward<U>(a_value));
				_active = true;
			}
			return *this;
		}

		// 5)
		template <class U>
		BSTOptional& operator=(const BSTOptional<U>& a_rhs)  //
			noexcept((std::is_nothrow_destructible_v<value_type> &&
					  std::is_nothrow_constructible_v<value_type, const U&> &&
					  std::is_nothrow_assignable_v<value_type&, const U&>))  //
			requires(!std::is_constructible_v<value_type, BSTOptional<U>&> &&
					 !std::is_constructible_v<value_type, const BSTOptional<U>&> &&
					 !std::is_constructible_v<value_type, BSTOptional<U> &&> &&
					 !std::is_constructible_v<value_type, const BSTOptional<U> &&> &&
					 !std::is_convertible_v<BSTOptional<U>&, value_type> &&
					 !std::is_convertible_v<const BSTOptional<U>&, value_type> &&
					 !std::is_convertible_v<BSTOptional<U> &&, value_type> &&
					 !std::is_convertible_v<const BSTOptional<U> &&, value_type> &&
					 !std::is_assignable_v<value_type&, BSTOptional<U>&> &&
					 !std::is_assignable_v<value_type&, const BSTOptional<U>&> &&
					 !std::is_assignable_v<value_type&, BSTOptional<U> &&> &&
					 !std::is_assignable_v<value_type&, const BSTOptional<U> &&> &&
					 std::is_constructible_v<value_type, const U&> &&
					 std::is_assignable_v<value_type&, const U&>)
		{
			if (a_rhs.has_value()) {
				if (has_value()) {
					_value = a_rhs.value();
				} else {
					std::construct_at(std::addressof(_value), a_rhs.value());
					_active = true;
				}
			} else if (has_value()) {
				reset();
			}
			return *this;
		}

		// 6)
		template <class U>
		BSTOptional& operator=(BSTOptional<U>&& a_rhs)  //
			noexcept((std::is_nothrow_destructible_v<value_type> &&
					  std::is_nothrow_constructible_v<value_type, U> &&
					  std::is_nothrow_assignable_v<value_type&, U>))  //
			requires(!std::is_constructible_v<value_type, BSTOptional<U>&> &&
					 !std::is_constructible_v<value_type, const BSTOptional<U>&> &&
					 !std::is_constructible_v<value_type, BSTOptional<U> &&> &&
					 !std::is_constructible_v<value_type, const BSTOptional<U> &&> &&
					 !std::is_convertible_v<BSTOptional<U>&, value_type> &&
					 !std::is_convertible_v<const BSTOptional<U>&, value_type> &&
					 !std::is_convertible_v<BSTOptional<U> &&, value_type> &&
					 !std::is_convertible_v<const BSTOptional<U> &&, value_type> &&
					 !std::is_assignable_v<value_type&, BSTOptional<U>&> &&
					 !std::is_assignable_v<value_type&, const BSTOptional<U>&> &&
					 !std::is_assignable_v<value_type&, BSTOptional<U> &&> &&
					 !std::is_assignable_v<value_type&, const BSTOptional<U> &&> &&
					 std::is_constructible_v<value_type, U> &&
					 std::is_assignable_v<value_type&, U>)
		{
			if (a_rhs.has_value()) {
				if (has_value()) {
					_value = std::move(a_rhs).value();
				} else {
					std::construct_at(std::addressof(_value), std::move(a_rhs).value());
					_active = true;
				}
			} else if (has_value()) {
				reset();
			}
			return *this;
		}

		[[nodiscard]] constexpr const value_type*  operator->() const noexcept { return std::addressof(value()); }
		[[nodiscard]] constexpr value_type*        operator->() noexcept { return std::addressof(value()); }
		[[nodiscard]] constexpr const value_type&  operator*() const& noexcept { return value(); }
		[[nodiscard]] constexpr value_type&        operator*() & noexcept { return value(); }
		[[nodiscard]] constexpr const value_type&& operator*() const&& noexcept { return std::move(*this).value(); }
		[[nodiscard]] constexpr value_type&&       operator*() && noexcept { return std::move(*this).value(); }

		[[nodiscard]] constexpr explicit operator bool() const noexcept { return has_value(); }
		[[nodiscard]] constexpr bool     has_value() const noexcept { return _active; }

		[[nodiscard]] constexpr value_type& value() & noexcept
		{
			assert(has_value());
			return _value;
		}

		[[nodiscard]] constexpr const value_type& value() const& noexcept
		{
			assert(has_value());
			return _value;
		}

		[[nodiscard]] constexpr value_type&& value() && noexcept
		{
			assert(has_value());
			return std::move(_value);
		}

		[[nodiscard]] constexpr const value_type&& value() const&& noexcept
		{
			assert(has_value());
			return std::move(_value);
		}

		// 1)
		template <class U>
		[[nodiscard]] constexpr value_type value_or(U&& a_default) const&  //
			requires((std::is_copy_constructible_v<value_type> &&
					  std::convertible_to<U &&, value_type>))
		{
			return has_value() ? value() : static_cast<T>(std::forward<U>(a_default));
		}

		// 2)
		template <class U>
			[[nodiscard]] constexpr value_type value_or(U&& a_default) &&  //
			requires((std::is_move_constructible_v<value_type> &&
					  std::convertible_to<U&&, value_type>)) {
				return has_value() ? std::move(*this).value() : static_cast<T>(std::forward<U>(a_default));
			}

			void reset() noexcept(noexcept(do_reset()))
		{
			do_reset();
		}

		// 1)
		template <class... Args>
		value_type& emplace(Args&&... a_args)                                 //
			noexcept(std::is_nothrow_constructible_v<value_type, Args&&...>)  //
			requires(std::is_constructible_v<value_type, Args && ...>)
		{
			reset();
			std::construct_at(std::addressof(_value), std::forward<Args>(a_args)...);
			_active = true;
			return value();
		}

		// 2)
		template <class U, class... Args>
		value_type& emplace(std::initializer_list<U> a_ilist, Args&&... a_args)                          //
			noexcept(std::is_nothrow_constructible_v<value_type, std::initializer_list<U>&, Args&&...>)  //
			requires(std::is_constructible_v<value_type, std::initializer_list<U>&, Args && ...>)
		{
			reset();
			std::construct_at(std::addressof(_value), a_ilist, std::forward<Args>(a_args)...);
			_active = true;
			return value();
		}

	private:
		constexpr void
			do_reset()  //
			noexcept(std::is_nothrow_destructible_v<value_type>)
		{
			if (has_value()) {
				std::destroy_at(std::addressof(_value));
				_active = false;
			}
		}

		// members
		union
		{
			std::remove_const_t<value_type> _value;
			std::byte                       _buffer[sizeof(value_type)]{};
		};  // 00
		bool _active{ false };  // ??
	};

	template <class T>
	BSTOptional(T) -> BSTOptional<T>;
}
