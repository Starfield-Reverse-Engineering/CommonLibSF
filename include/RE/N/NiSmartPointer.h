#pragma once

namespace RE
{
	template <class T>
	class NiPointer
	{
	public:
		using element_type = T;

		constexpr NiPointer() noexcept = default;

		constexpr NiPointer(std::nullptr_t) noexcept {}

		template <class Y>
		explicit NiPointer(Y* a_rhs)
			requires(std::convertible_to<Y*, element_type*>)
			:
			_ptr(static_cast<element_type*>(a_rhs))
		{
			TryAttach();
		}

		NiPointer(const NiPointer& a_rhs) :
			_ptr(a_rhs._ptr)
		{
			TryAttach();
		}

		template <class Y>
		NiPointer(const NiPointer<Y>& a_rhs)
			requires(std::convertible_to<Y*, element_type*>)
			:
			_ptr(static_cast<element_type*>(a_rhs._ptr))
		{
			TryAttach();
		}

		NiPointer(NiPointer&& a_rhs) noexcept :
			_ptr(std::exchange(a_rhs._ptr, nullptr))
		{}

		template <class Y>
		NiPointer(NiPointer<Y>&& a_rhs) noexcept
			requires(std::convertible_to<Y*, element_type*>)
			:
			_ptr(static_cast<element_type*>(std::exchange(a_rhs._ptr, nullptr)))
		{}

		~NiPointer() noexcept { reset(); }

		NiPointer& operator=(const NiPointer& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = a_rhs._ptr;
				TryAttach();
			}
			return *this;
		}

		template <class Y>
		NiPointer& operator=(const NiPointer<Y>& a_rhs)
			requires(std::convertible_to<Y*, element_type*>)
		{
			TryDetach();
			_ptr = static_cast<element_type*>(a_rhs._ptr);
			TryAttach();
			return *this;
		}

		NiPointer& operator=(NiPointer&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				TryDetach();
				_ptr = std::exchange(a_rhs._ptr, nullptr);
			}
			return *this;
		}

		template <class Y>
		NiPointer& operator=(NiPointer<Y>&& a_rhs) noexcept
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
		template <class>
		friend class NiPointer;

		void TryAttach()
		{
			if (_ptr) {
				_ptr->IncRefCount();
			}
		}

		void TryDetach()
		{
			if (_ptr) {
				_ptr->DecRefCount();
				_ptr = nullptr;
			}
		}

		// members
		element_type* _ptr{};  // 0
	};
	static_assert(sizeof(NiPointer<void*>) == 0x8);

	template <class T, class... Args>
	[[nodiscard]] NiPointer<T> make_nismart(Args&&... a_args)
	{
		return NiPointer<T>{ new T(std::forward<Args>(a_args)...) };
	}

	template <class T, class U>
	[[nodiscard]] constexpr bool operator==(const NiPointer<T>& a_lhs, const NiPointer<U>& a_rhs) noexcept
	{
		return a_lhs.get() == a_rhs.get();
	}

	template <class T, class U>
	[[nodiscard]] constexpr std::strong_ordering operator<=>(const NiPointer<T>& a_lhs, const NiPointer<U>& a_rhs) noexcept
	{
		return std::compare_three_way{}(a_lhs.get(), a_rhs.get());
	}

	template <class T>
	[[nodiscard]] constexpr bool operator==(const NiPointer<T>& a_lhs, std::nullptr_t) noexcept
	{
		return !a_lhs;
	}

	template <class T>
	[[nodiscard]] constexpr std::strong_ordering operator<=>(const NiPointer<T>& a_lhs, std::nullptr_t) noexcept
	{
		return std::compare_three_way{}(a_lhs.get(), static_cast<typename NiPointer<T>::element_type*>(nullptr));
	}

	template <class T>
	NiPointer(T*) -> NiPointer<T>;
}

#define NiSmartPointer(className) \
	class className;              \
	using className##Ptr = RE::NiPointer<className>
