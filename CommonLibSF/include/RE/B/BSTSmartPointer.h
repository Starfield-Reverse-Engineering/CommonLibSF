#pragma once

namespace RE
{
	template <class T>
	struct BSTSmartPointerIntrusiveRefCount
	{
	public:
		static void Acquire(stl::not_null<T*> a_ptr) { a_ptr->IncRef(); }

		static void Release(stl::not_null<T*> a_ptr)
		{
			if (a_ptr->DecRef() == 0) {
				delete a_ptr;
			}
		}
	};

	template <class T>
	struct BSTSmartPointerAutoPtr
	{
	public:
		constexpr static void Acquire(stl::not_null<T*> a_ptr) { return; }
		static void           Release(stl::not_null<T*> a_ptr) { delete a_ptr; }
	};

	template <class T>
	struct BSTSmartPointerGamebryoRefCount
	{
	public:
		constexpr static void Acquire(stl::not_null<T*> a_ptr) { a_ptr->IncRefCount(); }
		static void           Release(stl::not_null<T*> a_ptr) { a_ptr->DecRefCount(); }
	};

	template <class T, template <class> class RefManager = BSTSmartPointerIntrusiveRefCount>
	class BSTSmartPointer
	{
	public:
		using element_type = T;
		using reference_manager = RefManager<T>;

		constexpr BSTSmartPointer() noexcept = default;

		constexpr BSTSmartPointer(std::nullptr_t) noexcept {}

		template <class Y>
		explicit BSTSmartPointer(Y* a_rhs)
			requires(std::convertible_to<Y*, element_type*>)
			:
			_ptr(static_cast<element_type*>(a_rhs))
		{
			TryAttach();
		}

		BSTSmartPointer(const BSTSmartPointer& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}

		template <class Y>
		BSTSmartPointer(const BSTSmartPointer<Y>& a_rhs)
			requires(std::convertible_to<Y*, element_type*>)
			:
			_ptr(static_cast<element_type*>(a_rhs._ptr))
		{
			TryAttach();
		}

		BSTSmartPointer(BSTSmartPointer&& a_rhs) noexcept :
			_ptr(std::exchange(a_rhs._ptr, nullptr))
		{}

		template <class Y>
		BSTSmartPointer(BSTSmartPointer<Y>&& a_rhs) noexcept
			requires(std::convertible_to<Y*, element_type*>)
			:
			_ptr(static_cast<element_type*>(std::exchange(a_rhs._ptr, nullptr)))
		{}

		~BSTSmartPointer() { reset(); }

		BSTSmartPointer& operator=(const BSTSmartPointer& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
			}
			return *this;
		}

		template <class Y>
		BSTSmartPointer& operator=(const BSTSmartPointer<Y>& a_rhs)
			requires(std::convertible_to<Y*, element_type*>)
		{
			TryDetach();
			_ptr = static_cast<element_type*>(a_rhs._ptr);
			TryAttach();
			return *this;
		}

		BSTSmartPointer& operator=(BSTSmartPointer&& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = std::exchange(a_rhs._ptr, nullptr);
			}
			return *this;
		}

		template <class Y>
		BSTSmartPointer& operator=(BSTSmartPointer<Y>&& a_rhs)
			requires(std::convertible_to<Y*, element_type*>)
		{
			TryDetach();
			_ptr = std::exchange(a_rhs._ptr, nullptr);
			return *this;
		}

		void reset() { TryDetach(); }

		template <class Y>
		void reset(Y* a_ptr)
			requires(std::convertible_to<Y*, element_type*>)
		{
			if (_ptr != a_ptr) {
				TryDetach();
				_ptr = static_cast<element_type*>(a_ptr);
				TryAttach();
			}
		}

		[[nodiscard]] constexpr element_type* get() const noexcept { return _ptr; }

		[[nodiscard]] explicit constexpr operator bool() const noexcept { return _ptr != nullptr; }

		[[nodiscard]] constexpr element_type& operator*() const noexcept
		{
			assert(static_cast<bool>(*this));
			return *_ptr;
		}

		[[nodiscard]] constexpr element_type* operator->() const noexcept
		{
			assert(static_cast<bool>(*this));
			return _ptr;
		}

	protected:
		template <class, template <class> class>
		friend class BSTSmartPointer;

		void TryAttach()
		{
			if (_ptr) {
				reference_manager::Acquire(_ptr);
			}
		}

		void TryDetach()
		{
			if (_ptr) {
				reference_manager::Release(_ptr);
				_ptr = nullptr;
			}
		}

		// members
		element_type* _ptr{};  // 0
	};
	static_assert(sizeof(BSTSmartPointer<void*>) == 0x8);

	template <class T, class... Args>
	[[nodiscard]] BSTSmartPointer<T> make_smart(Args&&... a_args)
	{
		return BSTSmartPointer<T>{ new T(std::forward<Args>(a_args)...) };
	}

	template <class T, class U>
	[[nodiscard]] constexpr bool operator==(const BSTSmartPointer<T>& a_lhs, const BSTSmartPointer<U>& a_rhs) noexcept
	{
		return a_lhs.get() == a_rhs.get();
	}

	template <class T, class U>
	[[nodiscard]] constexpr std::strong_ordering operator<=>(const BSTSmartPointer<T>& a_lhs, const BSTSmartPointer<U>& a_rhs) noexcept
	{
		return std::compare_three_way{}(a_lhs.get(), a_rhs.get());
	}

	template <class T>
	[[nodiscard]] constexpr bool operator==(const BSTSmartPointer<T>& a_lhs, std::nullptr_t) noexcept
	{
		return !a_lhs;
	}

	template <class T>
	[[nodiscard]] constexpr std::strong_ordering operator<=>(const BSTSmartPointer<T>& a_lhs, std::nullptr_t) noexcept
	{
		return std::compare_three_way{}(a_lhs.get(), static_cast<typename BSTSmartPointer<T>::element_type*>(nullptr));
	}

	template <class T>
	BSTSmartPointer(T*) -> BSTSmartPointer<T, BSTSmartPointerIntrusiveRefCount>;

	template <class T>
	using BSTAutoPointer = BSTSmartPointer<T, BSTSmartPointerAutoPtr>;
	static_assert(sizeof(BSTAutoPointer<void*>) == 0x8);
}

#define BSSmartPointer(className) \
	class className;              \
	using className##Ptr = RE::BSTSmartPointer<className>;
