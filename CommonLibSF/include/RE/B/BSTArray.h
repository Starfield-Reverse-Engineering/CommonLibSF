#pragma once

namespace RE
{
	template <class T, class Allocator = void /* BSTArrayHeapAllocator? */>
	class BSTArray
	{
	public:
		//using allocator_type = Allocator
		using value_type = T;
		using size_type = std::uint32_t;
		using difference_type = std::ptrdiff_t;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = pointer;
		using const_iterator = const_pointer;

		[[nodiscard]] constexpr pointer data() noexcept
		{
			return static_cast<pointer>(_data);
		}

		[[nodiscard]] constexpr const_pointer data() const noexcept
		{
			return static_cast<const_pointer>(_data);
		}

		[[nodiscard]] constexpr iterator begin() noexcept
		{
			return data();
		}

		[[nodiscard]] constexpr const_iterator begin() const noexcept
		{
			return data();
		}

		[[nodiscard]] constexpr iterator end() noexcept
		{
			return begin() + size();
		}

		[[nodiscard]] constexpr const_iterator end() const noexcept
		{
			return begin() + size();
		}

		[[nodiscard]] constexpr bool empty() const noexcept
		{
			return _size == 0;
		}

		[[nodiscard]] constexpr size_type size() const noexcept
		{
			return _size;
		}

	private:
		// members
		std::uint32_t _size;
		std::uint32_t _capacity;
		void*         _data;
	};
}
