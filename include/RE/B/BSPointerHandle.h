#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class Actor;
	class HandleManager;
	class Projectile;
	class TESObjectREFR;

	template <std::uint32_t = 21, std::uint32_t = 5>
	class BSUntypedPointerHandle;

	template <class, class = BSUntypedPointerHandle<>>
	class BSPointerHandle;

	template <class, class = HandleManager>
	class BSPointerHandleManagerInterface;

	template <std::uint32_t FREE_LIST_BITS, std::uint32_t AGE_SHIFT>
	class BSUntypedPointerHandle
	{
	public:
		using HandleType = std::uint32_t;

		enum : std::uint32_t
		{
			kFreeListBits = FREE_LIST_BITS,
			kAgeShift = AGE_SHIFT,
		};

		BSUntypedPointerHandle() noexcept = default;
		BSUntypedPointerHandle(const BSUntypedPointerHandle&) noexcept = default;

		explicit BSUntypedPointerHandle(HandleType a_handle) noexcept :
			_handle(a_handle)
		{}

		~BSUntypedPointerHandle() noexcept { reset(); }

		BSUntypedPointerHandle& operator=(const BSUntypedPointerHandle&) noexcept = default;

		BSUntypedPointerHandle& operator=(HandleType a_rhs) noexcept
		{
			_handle = a_rhs;
			return *this;
		}

		[[nodiscard]] explicit operator bool() const noexcept { return has_value(); }
		[[nodiscard]] bool     has_value() const noexcept { return _handle != 0; }

		[[nodiscard]] HandleType value() const noexcept { return _handle; }

		void reset() noexcept { _handle = 0; }

		[[nodiscard]] friend bool operator==(const BSUntypedPointerHandle& a_lhs, const BSUntypedPointerHandle& a_rhs) noexcept
		{
			return a_lhs.value() == a_rhs.value();
		}

	private:
		HandleType _handle{ 0 };  // 00
	};

	extern template class BSUntypedPointerHandle<>;

	template <class T, class Handle>
	class BSPointerHandle
	{
	public:
		BSPointerHandle() noexcept = default;

		template <class Y>
		BSPointerHandle(BSPointerHandle<Y, Handle> a_rhs) noexcept
			requires(std::convertible_to<Y*, T*>)
			:
			_handle(a_rhs._handle)
		{}

		~BSPointerHandle() noexcept = default;

		template <class Y>
		BSPointerHandle& operator=(BSPointerHandle<Y, Handle> a_rhs) noexcept
			requires(std::convertible_to<Y*, T*>)
		{
			_handle = a_rhs._handle;
			return *this;
		}

		void reset() noexcept { _handle.reset(); }

		[[nodiscard]] NiPointer<T> get() const
		{
			return BSPointerHandleManagerInterface<T>::GetSmartPointer(*this);
		}

		[[nodiscard]] Handle::HandleType get_handle() noexcept
		{
			return _handle.value();
		}

		[[nodiscard]] explicit operator bool() const noexcept { return _handle.has_value(); }

		[[nodiscard]] friend bool operator==(const BSPointerHandle& a_lhs, const BSPointerHandle& a_rhs) noexcept
		{
			return a_lhs._handle == a_rhs._handle;
		}

		[[nodiscard]] NiPointer<T> operator*() const noexcept
		{
			assert(static_cast<bool>(*this));
			return get();
		}

		[[nodiscard]] NiPointer<T> operator->() const noexcept
		{
			assert(static_cast<bool>(*this));
			return get();
		}

	private:
		template <class, class>
		friend class BSPointerHandle;

		Handle _handle;  // 00
	};

	extern template class BSPointerHandle<Actor>;
	extern template class BSPointerHandle<Projectile>;
	extern template class BSPointerHandle<TESObjectREFR>;

	template <class T, class Manager>
	class BSPointerHandleManagerInterface
	{
	public:
		static bool GetSmartPointer(const BSPointerHandle<T>& a_in, NiPointer<T>& a_out)
		{
			using func_t = bool (*)(const BSPointerHandle<T>& a_in, NiPointer<T>& a_out);
			static REL::Relocation<func_t> func{ ID::BSPointerHandleManagerInterface::GetSmartPointer };
			return func(a_in, a_out);
		}

		static NiPointer<T> GetSmartPointer(const BSPointerHandle<T>& a_in)
		{
			NiPointer<T> out;
			GetSmartPointer(a_in, out);
			return out;
		}
	};

	extern template class BSPointerHandleManagerInterface<Actor>;
	extern template class BSPointerHandleManagerInterface<Projectile>;
	extern template class BSPointerHandleManagerInterface<TESObjectREFR>;
}
