#pragma once

namespace RE
{
	template <class CharT, std::uint16_t>
	class DynamicMemoryManagementPol
	{
	public:
		using value_type = CharT;
		using size_type = std::uint16_t;
		using propagate_on_container_move_assignment = std::true_type;

		[[nodiscard]] value_type* allocate(size_type a_count) { return calloc<value_type>(a_count); }

		void deallocate(value_type* a_ptr, size_type) { free(a_ptr); }
	};

	template <
		class CharT,
		std::uint16_t N = static_cast<std::uint16_t>(-1),
		template <class, std::uint16_t> class Allocator = DynamicMemoryManagementPol>
	class BSStringT :
		public Allocator<CharT, N>  // 00
	{
	public:
		using value_type = CharT;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using reference = value_type&;
		using const_reference = const value_type&;
		using size_type = std::uint16_t;
		using allocator_type = Allocator<value_type, N>;
		using traits_type = std::char_traits<value_type>;

		constexpr BSStringT() noexcept = default;

		BSStringT(const BSStringT& a_rhs) { copy_from(a_rhs); }

		BSStringT(BSStringT&& a_rhs) noexcept
		{
			if constexpr (allocator_type::propagate_on_container_move_assignment::value) {
				move_from(std::move(a_rhs));
			} else {
				copy_from(a_rhs);
			}
		}

		~BSStringT() { release(); }

		BSStringT& operator=(const BSStringT& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				copy_from(a_rhs);
			}
			return *this;
		}

		BSStringT& operator=(BSStringT&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				if constexpr (allocator_type::propagate_on_container_move_assignment::value) {
					move_from(std::move(a_rhs));
				} else {
					copy_from(a_rhs);
				}
			}
			return *this;
		}

		[[nodiscard]] const_pointer data() const noexcept { return _data; }
		[[nodiscard]] pointer       data() noexcept { return _data; }

		[[nodiscard]] const_pointer c_str() const noexcept { return data(); }

		[[nodiscard]] operator std::basic_string_view<value_type, traits_type>() const noexcept { return { data(), size() }; }

		[[nodiscard]] bool empty() const noexcept { return size() == 0; }

		[[nodiscard]] size_type size() const noexcept { return length(); }
		[[nodiscard]] size_type length() const noexcept { return _size == N ? static_cast<size_type>(traits_type::length(c_str())) : _size; }

		[[nodiscard]] size_type capacity() const noexcept { return _capacity; }

	private:
		void release()
		{
			allocator_type::deallocate(_data, _capacity);
			_data = nullptr;
			_size = 0;
			_capacity = 0;
		}

		void copy_from(const BSStringT& a_rhs)
		{
			release();

			_size = a_rhs._size;
			_capacity = a_rhs._capacity;
			_data = allocator_type::allocate(_capacity);

			std::uninitialized_copy_n(a_rhs._data, _size, _data);
		}

		void move_from(BSStringT&& a_rhs)
		{
			release();

			_data = a_rhs._data;
			_size = a_rhs._size;
			_capacity = a_rhs._capacity;

			a_rhs._data = nullptr;
			a_rhs._size = 0;
			a_rhs._capacity = 0;
		}

		pointer   _data{};      // ??
		size_type _size{};      // ??
		size_type _capacity{};  // ??
	};
}
