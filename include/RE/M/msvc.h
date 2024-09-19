#pragma once

namespace SFSE::stl::detail
{
	// TODO: Have this be the default deleter if the object is allocated aligned
	template <class T>
	struct AlignedDelete
	{
		constexpr AlignedDelete() noexcept = default;

		template <class U>
		AlignedDelete(const AlignedDelete<U>&) noexcept
			requires(std::convertible_to<U*, T*>)
		{}

		void operator()(T* a_ptr) const { delete a_ptr; }
	};
}

namespace RE::msvc
{
	class type_info;

	template <class>
	class function;

	// class std::_Func_class
	template <class R, class... Args>
	class function<R(Args...)>
	{
	public:
		using result_type = R;

		[[nodiscard]] explicit operator bool() const noexcept { return good(); }

		result_type operator()(Args&&... a_args) const
		{
			assert(good());
			return _fn->do_call(std::forward<Args>(a_args)...);
		}

	private:
		// class std::_Func_base
		class __declspec(novtable) proxy_t
		{
		public:
			// add
			virtual proxy_t*         copy(void*) = 0;          // 00
			virtual proxy_t*         move(void*) = 0;          // 01
			virtual result_type      do_call(Args&&...) = 0;   // 02
			virtual const type_info& target_type() const = 0;  // 03
			virtual void             delete_this(bool) = 0;    // 04
			virtual ~proxy_t() = default;                      // 05
			virtual const void* get() const = 0;               // 06
		};

		[[nodiscard]] bool good() const noexcept { return _fn != nullptr; }

		std::aligned_storage_t<3 * sizeof(void*), alignof(long double)> _storage;  // 00
		proxy_t*                                                        _fn;       // 18
	};

	template <class T>
	struct default_delete;

	template <class T, class Deleter = default_delete<T>>
	class unique_ptr;

	namespace detail
	{
		// std::_Get_deleter_pointer_type
		template <class T, class Deleter, class = void>
		struct _deleter_pointer_type
		{
			using type = std::add_pointer_t<std::remove_extent_t<T>>;
		};

		template <class T, class Deleter>
		struct _deleter_pointer_type<
			T,
			Deleter,
			std::void_t<
				typename Deleter::pointer>>
		{
			using type = typename Deleter::pointer;
		};

		template <class T, class Deleter>
		using deleter_pointer_type = _deleter_pointer_type<
			T,
			std::remove_reference_t<
				Deleter>>;

		template <class T, class Deleter>
		using deleter_pointer_type_t = typename deleter_pointer_type<T, Deleter>::type;

		// std::_Unique_ptr_base

		// default template
		template <class T, class Deleter, class = void>
		class unique_ptr
		{
		public:
			using pointer = deleter_pointer_type_t<T, Deleter>;
			using deleter_type = Deleter;

			template <class... Args>
			unique_ptr(pointer a_ptr, Args... a_args) noexcept
				requires(std::is_nothrow_constructible_v<deleter_type, Args...>)
				:
				_pointer(a_ptr),
				_deleter(std::forward<Args>(a_args)...)
			{}

			unique_ptr(unique_ptr&& a_rhs) noexcept
				requires(std::is_nothrow_move_constructible_v<deleter_type>)
				:
				_pointer(std::move(a_rhs._pointer)),
				_deleter(std::move(a_rhs._deleter))
			{
				a_rhs._pointer = pointer();
			}

			// copy reference
			template <class U, class E>
			unique_ptr(unique_ptr<U, E>&& a_rhs) noexcept
				requires((std::is_reference_v<E> &&
							std::is_nothrow_constructible_v<deleter_type, const E&>))
				:
				_pointer(std::move(a_rhs._pointer)),
				_deleter(a_rhs._deleter)
			{
				a_rhs._pointer = typename unique_ptr<U, E>::pointer();
			}

			// move non-reference
			template <class U, class E>
			unique_ptr(unique_ptr<U, E>&& a_rhs) noexcept
				requires(!std::is_reference_v<E> &&
							std::is_nothrow_constructible_v<deleter_type, E &&>)
				:
				_pointer(std::move(a_rhs._pointer)),
				_deleter(std::move(a_rhs._deleter))
			{
				a_rhs._pointer = typename unique_ptr<U, E>::pointer();
			}

			[[nodiscard]] deleter_type&       get_deleter() noexcept { return _deleter; }
			[[nodiscard]] const deleter_type& get_deleter() const noexcept { return _deleter; }

		protected:
			// members
			pointer _pointer;

		private:
			template <class, class, class>
			friend class unique_ptr;

			// members
			deleter_type _deleter;
		};

		// empty deleter
		template <class T, class Deleter>
		class unique_ptr<
			T,
			Deleter,
			std::enable_if_t<
				std::disjunction_v<
					std::is_empty<
						Deleter>,
					std::is_same<
						default_delete<T>,
						Deleter>>>> :
			public Deleter
		{
		private:
			using super = Deleter;

		public:
			using pointer = deleter_pointer_type_t<T, Deleter>;
			using deleter_type = Deleter;

			template <class... Args>
			unique_ptr(pointer a_ptr, Args... a_args) noexcept
				requires(std::is_nothrow_constructible_v<deleter_type, Args...>)
				:
				super(std::forward<Args>(a_args)...),
				_pointer(a_ptr)
			{}

			unique_ptr(unique_ptr&& a_rhs) noexcept
				requires(std::is_nothrow_move_constructible_v<deleter_type>)
				:
				super(std::move(a_rhs)),
				_pointer(std::move(a_rhs._pointer))
			{
				a_rhs._pointer = pointer();
			}

			// copy reference
			template <class U, class E>
			unique_ptr(unique_ptr<U, E>&& a_rhs) noexcept
				requires((std::is_reference_v<E> &&
							std::is_nothrow_constructible_v<deleter_type, const E&>))
				:
				super(a_rhs),
				_pointer(std::move(a_rhs._pointer))
			{
				a_rhs._pointer = typename unique_ptr<U, E>::pointer();
			}

			// move non-reference
			template <class U, class E>
			unique_ptr(unique_ptr<U, E>&& a_rhs) noexcept
				requires(!std::is_reference_v<E> &&
							std::is_nothrow_constructible_v<deleter_type, E &&>)
				:
				super(std::move(a_rhs)),
				_pointer(std::move(a_rhs._pointer))
			{
				a_rhs._pointer = typename unique_ptr<U, E>::pointer();
			}

			[[nodiscard]] deleter_type&       get_deleter() noexcept { return *this; }
			[[nodiscard]] const deleter_type& get_deleter() const noexcept { return *this; }

		protected:
			// members
			pointer _pointer;

		private:
			template <class, class, class>
			friend class unique_ptr;
		};
	}

	// scalar
	template <class T>
	struct default_delete
	{
	public:
		constexpr default_delete() noexcept = default;

		template <class U>
		default_delete(const default_delete<U>&) noexcept
			requires(std::convertible_to<U*, T*>)
		{}

		void operator()(T* a_ptr) const { delete a_ptr; }
	};

	// array
	template <class T>
	struct default_delete<T[]>
	{
	public:
		constexpr default_delete() noexcept = default;

		template <class U>
		default_delete(const default_delete<U[]>&) noexcept
			requires(std::convertible_to<U (*)[], T (*)[]>)
		{}

		template <class U>
		void operator()(U* a_ptr) const
			requires(std::convertible_to<U (*)[], T (*)[]>)
		{
			delete[] a_ptr;
		}
	};

	// scalar
	template <class T, class Deleter>
	class unique_ptr :
		public detail::unique_ptr<T, Deleter>
	{
	private:
		using super = detail::unique_ptr<T, Deleter>;
		using super::_pointer;

	public:
		// member types
		using pointer = typename super::pointer;
		using element_type = T;
		using deleter_type = typename super::deleter_type;

		// constructors

		// 1a
		constexpr unique_ptr() noexcept
			requires(std::is_nothrow_default_constructible_v<deleter_type> &&
					 !std::is_pointer_v<deleter_type>)
			:
			super(pointer())
		{}

		// 1b
		constexpr unique_ptr(std::nullptr_t) noexcept
			requires(std::is_nothrow_default_constructible_v<deleter_type> &&
					 !std::is_pointer_v<deleter_type>)
			:
			super(pointer())
		{}

		// 2
		explicit unique_ptr(pointer a_ptr) noexcept
			requires(std::is_nothrow_default_constructible_v<deleter_type> &&
					 !std::is_pointer_v<deleter_type>)
			:
			super(a_ptr)
		{}

		// 3a
		unique_ptr(pointer a_ptr, const deleter_type& a_dtor) noexcept
			requires(!std::is_reference_v<deleter_type> &&
					 std::is_nothrow_copy_constructible_v<deleter_type>)
			:
			super(a_ptr, a_dtor)
		{}

		// 4a
		unique_ptr(pointer a_ptr, deleter_type&& a_dtor) noexcept
			requires(!std::is_reference_v<deleter_type> &&
					 std::is_nothrow_move_constructible_v<deleter_type>)
			:
			super(a_ptr, std::move(a_dtor))
		{}

		// 3b
		unique_ptr(pointer a_ptr, deleter_type& a_dtor) noexcept
			requires(std::is_lvalue_reference_v<deleter_type> &&
					 !std::is_const_v<deleter_type>)
			:
			super(a_ptr, a_dtor)
		{}

		// 4b
		unique_ptr(pointer, deleter_type&&)
			requires(std::is_lvalue_reference_v<deleter_type> &&
						!std::is_const_v<deleter_type>)
		= delete;

		// 3c
		unique_ptr(pointer a_ptr, const deleter_type& a_dtor) noexcept
			requires((std::is_lvalue_reference_v<deleter_type> && std::is_const_v<deleter_type>))
			:
			super(a_ptr, a_dtor)
		{}

		// 4c
		unique_ptr(pointer, const deleter_type&&)
			requires((std::is_lvalue_reference_v<deleter_type> &&
						std::is_const_v<deleter_type>))
		= delete;

		// 5
		unique_ptr(unique_ptr&& a_rhs) noexcept
			requires(std::is_nothrow_move_constructible_v<deleter_type>)
			:
			super(std::move(a_rhs))
		{}

		// 6
		template <class U, class E>
		unique_ptr(unique_ptr<U, E>&& a_rhs) noexcept
			requires(std::convertible_to<typename unique_ptr<U, E>::pointer, pointer> &&
					 !std::is_array_v<U> &&
					 std::same_as<E, deleter_type> &&
					 (std::is_reference_v<deleter_type> ?
							 std::is_nothrow_constructible_v<deleter_type, const E&> :
							 std::is_nothrow_constructible_v<deleter_type, E &&>))
			:
			super(std::move(a_rhs))
		{}

		// destructor

		~unique_ptr() noexcept
		{
			if (_pointer) {
				get_deleter()(_pointer);
			}
		}

		// assignment

		// 1a
		unique_ptr& operator=(unique_ptr&& a_rhs) noexcept
			requires(((std::is_reference_v<deleter_type> ?
							 std::is_nothrow_copy_assignable_v<std::remove_reference_t<deleter_type>> :
							 std::is_nothrow_move_assignable_v<deleter_type>)) &&
					 std::is_move_assignable_v<deleter_type>)
		{
			if (this != std::addressof(a_rhs)) {
				reset(a_rhs.release());
				get_deleter() = std::forward<deleter_type>(a_rhs.get_deleter());
			}
			return *this;
		}

		// 1b
		template <class U, class E>
		unique_ptr& operator=(unique_ptr<U, E>&& a_rhs) noexcept
			requires(((std::is_reference_v<deleter_type> ?
							 std::is_nothrow_copy_assignable_v<std::remove_reference_t<deleter_type>> :
							 std::is_nothrow_move_assignable_v<deleter_type>)) &&
					 !std::is_array_v<U> &&
					 std::convertible_to<typename unique_ptr<U, E>::pointer, pointer> &&
					 std::is_assignable_v<deleter_type, E &&>)
		{
			reset(a_rhs.release());
			get_deleter() = std::forward<E>(a_rhs.get_deleter());
			return *this;
		}

		// 2
		unique_ptr& operator=(std::nullptr_t) noexcept
		{
			reset();
			return *this;
		}

		// modifiers

		pointer release() noexcept
		{
			auto old = _pointer;
			_pointer = pointer();
			return old;
		}

		void reset(pointer a_ptr = pointer()) noexcept
		{
			auto old = _pointer;
			_pointer = a_ptr;
			if (old) {
				get_deleter()(old);
			}
		}

		void swap(unique_ptr& a_other) noexcept
		{
			using std::swap;
			swap(_pointer, a_other._pointer);
			swap(get_deleter(), a_other.get_deleter());
		}

		// observers

		[[nodiscard]] pointer get() const noexcept { return _pointer; }

		using super::get_deleter;

		[[nodiscard]] explicit operator bool() const noexcept { return good(); }

		[[nodiscard]] auto operator*() const
			-> std::add_lvalue_reference_t<T>
		{
			assert(good());
			return *get();
		}

		[[nodiscard]] pointer operator->() const noexcept
		{
			assert(good());
			return get();
		}

	private:
		[[nodiscard]] constexpr bool good() const noexcept { return get() != pointer(); }
	};

	namespace detail
	{
		template <class T, class Ptr>
		concept unique_ptr_array_convertible =
			std::same_as<T, typename Ptr::pointer> ||
			std::same_as<T, std::nullptr_t> ||
			((std::same_as<typename Ptr::pointer, typename Ptr::element_type*> &&
				std::is_pointer_v<T> &&
				std::same_as<std::remove_pointer_t<T> (*)[], typename Ptr::element_type (*)[]>));
	}

	// array
	template <class T, class Deleter>
	class unique_ptr<T[], Deleter> :
		public detail::unique_ptr<T[], Deleter>
	{
	private:
		using super = detail::unique_ptr<T[], Deleter>;
		using super::_pointer;

	public:
		// member types
		using pointer = typename super::pointer;
		using element_type = T;
		using deleter_type = typename super::deleter_type;

	public:
		// constructors

		// 1a
		constexpr unique_ptr() noexcept
			requires(std::is_nothrow_default_constructible_v<deleter_type> &&
					 !std::is_pointer_v<deleter_type>)
			:
			super(pointer())
		{}

		// 1b
		constexpr unique_ptr(std::nullptr_t) noexcept
			requires(std::is_nothrow_default_constructible_v<deleter_type> &&
					 !std::is_pointer_v<deleter_type>)
			:
			super(pointer())
		{}

		// 2
		template <class U>
		explicit unique_ptr(U a_ptr) noexcept
			requires(std::is_nothrow_default_constructible_v<deleter_type> &&
					 !std::is_pointer_v<deleter_type> &&
					 detail::unique_ptr_array_convertible<U, unique_ptr>)
			:
			super(a_ptr)
		{}

		// 3a
		template <class U>
		unique_ptr(U a_ptr, const deleter_type& a_dtor) noexcept
			requires(!std::is_reference_v<deleter_type> &&
					 std::is_nothrow_copy_constructible_v<deleter_type> &&
					 detail::unique_ptr_array_convertible<U, unique_ptr>)
			:
			super(a_ptr, a_dtor)
		{}

		// 4a
		template <class U>
		unique_ptr(U a_ptr, deleter_type&& a_dtor) noexcept
			requires(!std::is_reference_v<deleter_type> &&
					 std::is_nothrow_move_constructible_v<deleter_type> &&
					 detail::unique_ptr_array_convertible<U, unique_ptr>)
			:
			super(a_ptr, std::move(a_dtor))
		{}

		// 3b
		template <class U>
		unique_ptr(U a_ptr, deleter_type& a_dtor) noexcept
			requires(std::is_lvalue_reference_v<deleter_type> &&
					 !std::is_const_v<deleter_type> &&
					 detail::unique_ptr_array_convertible<U, unique_ptr>)
			:
			super(a_ptr, a_dtor)
		{}

		// 4b
		template <class U>
		unique_ptr(U, deleter_type&&) noexcept
			requires(std::is_lvalue_reference_v<deleter_type> &&
						!std::is_const_v<deleter_type> &&
						detail::unique_ptr_array_convertible<U, unique_ptr>)
		= delete;

		// 3c
		template <class U>
		unique_ptr(U a_ptr, const deleter_type& a_dtor) noexcept
			requires((std::is_lvalue_reference_v<deleter_type> &&
					  std::is_const_v<deleter_type> &&
					  detail::unique_ptr_array_convertible<U, unique_ptr>))
			:
			super(a_ptr, a_dtor)
		{}

		// 4c
		template <class U>
		unique_ptr(U, const deleter_type&&) noexcept
			requires((std::is_lvalue_reference_v<deleter_type> &&
						std::is_const_v<deleter_type> &&
						detail::unique_ptr_array_convertible<U, unique_ptr>))
		= delete;

		// 5
		unique_ptr(unique_ptr&& a_rhs) noexcept
			requires(std::is_nothrow_move_constructible_v<deleter_type>)
			:
			super(std::move(a_rhs))
		{}

		// 6
		template <class U, class E>
		unique_ptr(unique_ptr<U, E>&& a_rhs) noexcept
			requires((std::is_array_v<U> &&
					  std::same_as<pointer, element_type*> &&
					  std::same_as<typename unique_ptr<U, E>::pointer, typename unique_ptr<U, E>::element_type*> &&
					  std::convertible_to<typename unique_ptr<U, E>::element_type (*)[], element_type (*)[]> &&
					  (std::is_reference_v<deleter_type> ?
							  std::same_as<E, deleter_type> && std::is_nothrow_constructible_v<deleter_type, const E&> :
							  std::convertible_to<E, deleter_type> && std::is_nothrow_constructible_v<deleter_type, E &&>)))
			:
			super(std::move(a_rhs))
		{}

		// destructor

		~unique_ptr() noexcept
		{
			if (_pointer) {
				get_deleter()(_pointer);
			}
		}

		// assignment

		// 1a
		unique_ptr& operator=(unique_ptr&& a_rhs) noexcept
			requires(((std::is_reference_v<deleter_type> ?
							 std::is_nothrow_copy_assignable_v<std::remove_reference_t<deleter_type>> :
							 std::is_nothrow_move_assignable_v<deleter_type>)) &&
					 std::is_move_assignable_v<deleter_type>)
		{
			if (this != std::addressof(a_rhs)) {
				reset(a_rhs.release());
				get_deleter() = std::forward<deleter_type>(a_rhs.get_deleter());
			}
			return *this;
		}

		// 1b
		template <class U, class E>
		unique_ptr& operator=(unique_ptr<U, E>&& a_rhs) noexcept
			requires((std::is_array_v<U> &&
					  std::same_as<pointer, element_type*> &&
					  std::same_as<typename unique_ptr<U, E>::pointer, typename unique_ptr<U, E>::element_type*> &&
					  std::convertible_to<typename unique_ptr<U, E>::element_type (*)[], element_type (*)[]> &&
					  std::is_assignable_v<deleter_type&, E &&>))
		{
			if (this != std::addressof(a_rhs)) {
				reset(a_rhs.release());
				get_deleter() = std::forward<E>(a_rhs.get_deleter());
			}
			return *this;
		}

		// 2
		unique_ptr& operator=(std::nullptr_t) noexcept
		{
			reset();
			return *this;
		}

		// modifiers

		pointer release() noexcept
		{
			auto old = _pointer;
			_pointer = pointer{};
			return old;
		}

		// 3
		template <class U>
		void reset(U a_ptr) noexcept
			requires(detail::unique_ptr_array_convertible<U, unique_ptr>)
		{
			auto old = _pointer;
			_pointer = a_ptr;
			if (old) {
				get_deleter()(old);
			}
		}

		// 4
		void reset(std::nullptr_t = nullptr) noexcept { reset(pointer()); }

		void swap(unique_ptr& a_other) noexcept
		{
			using std::swap;
			swap(_pointer, a_other._pointer);
			swap(get_deleter(), a_other.get_deleter());
		}

		// observers

		[[nodiscard]] pointer get() const noexcept { return _pointer; }

		using super::get_deleter;

		[[nodiscard]] explicit operator bool() const noexcept { return good(); }

		[[nodiscard]] element_type& operator[](std::size_t a_idx) const
		{
			assert(good());
			return get()[a_idx];
		}

	private:
		[[nodiscard]] constexpr bool good() const noexcept { return get() != pointer(); }
	};

	// 1
	template <class T, class... Args>
	[[nodiscard]] unique_ptr<T> make_unique(Args&&... a_args)
		requires(!std::is_array_v<T>)
	{
		return unique_ptr<T>(new T(std::forward<Args>(a_args)...));
	}

	// 2
	template <class T>
	[[nodiscard]] unique_ptr<T> make_unique(std::size_t a_size)
		requires(std::is_unbounded_array_v<T>)
	{
		return unique_ptr<T>(new std::remove_extent_t<T>[a_size]());
	}

	// 3
	template <class T, class... Args>
	void make_unique(Args&&...)
		requires(std::is_bounded_array_v<T>)
	= delete;

	// 4
	template <class T, class... Args>
	[[nodiscard]] unique_ptr<T> make_unique_for_overwrite()
		requires(!std::is_array_v<T>)
	{
		return unique_ptr<T>(new T);
	}

	// 5
	template <class T>
	[[nodiscard]] unique_ptr<T> make_unique_for_overwrite(std::size_t a_size)
		requires(std::is_unbounded_array_v<T>)
	{
		return unique_ptr<T>(new std::remove_extent_t<T>[a_size]);
	}

	// 6
	template <class T, class... Args>
	void make_unique_for_overwrite(Args&&...)
		requires(std::is_bounded_array_v<T>)
	= delete;

	// 1
	template <class T1, class D1, class T2, class D2>
	[[nodiscard]] bool operator==(const unique_ptr<T1, D1>& a_lhs, const unique_ptr<T2, D2>& a_rhs)
	{
		return a_lhs.get() == a_rhs.get();
	}

	// 7
	template <class T1, class D1, class T2, class D2>
	[[nodiscard]] auto operator<=>(const unique_ptr<T1, D1>& a_lhs, const unique_ptr<T2, D2>& a_rhs)
		-> std::compare_three_way_result_t<
			typename unique_ptr<T1, D1>::pointer,
			typename unique_ptr<T2, D2>::pointer>
		requires(std::three_way_comparable_with<
			typename unique_ptr<T1, D1>::pointer,
			typename unique_ptr<T2, D2>::pointer>)
	{
		return a_lhs.get() <=> a_rhs.get();
	}

	// 8
	template <class T, class D>
	[[nodiscard]] bool operator==(const unique_ptr<T, D>& a_lhs, std::nullptr_t) noexcept
	{
		return !a_lhs;
	}

	// 20
	template <class T, class D>
	[[nodiscard]] auto operator<=>(const unique_ptr<T, D>& a_lhs, std::nullptr_t)
		-> std::compare_three_way_result_t<typename unique_ptr<T, D>::pointer>
		requires(std::three_way_comparable<typename unique_ptr<T, D>::pointer>)
	{
		return a_lhs.get() <=> nullptr;
	}

	template <class T, class Deleter>
	void swap(unique_ptr<T, Deleter>& a_lhs, unique_ptr<T, Deleter>& a_rhs) noexcept
	{
		a_lhs.swap(a_rhs);
	}

	class type_info
	{
	public:
		SF_RTTI_VTABLE(type_info);
		virtual ~type_info();  // 00

		[[nodiscard]] const char* name() const noexcept
		{
			using func_t = const char* (*)(const type_info*, __type_info_node*) noexcept;
			static REL::Relocation<func_t*> func{ ID::msvc::type_info::name };
			return (*func)(this, std::addressof(get_root_node()));
		}

		[[nodiscard]] const char* mangled_name() const noexcept { return _name; }

		[[nodiscard]] bool operator==(const type_info& a_rhs) const noexcept { return compare(a_rhs) == 0; }
		[[nodiscard]] bool operator!=(const type_info& a_rhs) const noexcept { return compare(a_rhs) != 0; }

	private:
		[[nodiscard]] int compare(const type_info& a_rhs) const
		{
			using func_t = int (*)(const type_info*, const type_info*) noexcept;
			static REL::Relocation<func_t*> func{ ID::msvc::type_info::compare };
			return (*func)(this, &a_rhs);
		}

		[[nodiscard]] static __type_info_node& get_root_node() noexcept
		{
			static REL::Relocation<__type_info_node*> root{ ID::msvc::type_info::_RootNode };
			return *root;
		}

		// members
		char* _undecorated_name;  // 08
		char  _name[1];           // 10
	};
	static_assert(sizeof(type_info) == 0x18);
}
