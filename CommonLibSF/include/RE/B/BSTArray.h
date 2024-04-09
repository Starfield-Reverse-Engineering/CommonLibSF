#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	class ScrapHeap;

	class BSTArrayBase
	{
	public:
		using size_type = std::uint32_t;

		struct IAllocatorFunctor
		{
		public:
			SF_RTTI(BSTArrayBase__IAllocatorFunctor);

			// add
			virtual bool Allocate(std::uint32_t a_num, std::uint32_t a_elemSize) = 0;                                                                                                             // 00
			virtual bool Reallocate(std::uint32_t a_minNewSizeInItems, std::uint32_t a_frontCopyCount, std::uint32_t a_shiftCount, std::uint32_t a_backCopyCount, std::uint32_t a_elemSize) = 0;  // 01
			virtual void Deallocate() = 0;                                                                                                                                                        // 02

			virtual ~IAllocatorFunctor() = default;  // 03

			SF_HEAP_REDEFINE_NEW();
		};
		static_assert(sizeof(IAllocatorFunctor) == 0x8);

		constexpr BSTArrayBase() noexcept = default;
		constexpr BSTArrayBase(const BSTArrayBase&) noexcept = default;
		constexpr BSTArrayBase(BSTArrayBase&&) noexcept = default;

		~BSTArrayBase() noexcept
		{
			_size = 0;
			_capacity = 0;
		}

		BSTArrayBase& operator=(const BSTArrayBase&) noexcept = default;
		BSTArrayBase& operator=(BSTArrayBase&&) noexcept = default;

		[[nodiscard]] constexpr bool      empty() const noexcept { return _size == 0; }
		[[nodiscard]] constexpr size_type size() const noexcept { return _size; }
		[[nodiscard]] constexpr size_type capacity() const noexcept { return _capacity; }

	protected:
		constexpr void set_size(size_type a_size) noexcept { _size = a_size; }
		constexpr void set_capacity(size_type a_capacity, size_t) noexcept { _capacity = a_capacity; }

		// members
		std::uint32_t _size{ 0 };      // 0
		std::uint32_t _capacity{ 0 };  // 4
	};
	static_assert(sizeof(BSTArrayBase) == 0x8);

	template <class Allocator>
	class BSTArrayAllocatorFunctor : public BSTArrayBase::IAllocatorFunctor
	{
	public:
		// members
		Allocator* _allocator;  // 00
	};
	static_assert(sizeof(BSTArrayAllocatorFunctor<void*>) == 0x10);

	class BSTArrayHeapAllocator
	{
	public:
		[[nodiscard]] void* allocate(std::size_t a_size)
		{
			const auto mem = malloc(a_size);
			if (!mem) {
				stl::report_and_fail("out of memory"sv);
			}
			std::memset(mem, 0, a_size);
			return mem;
		}

		void deallocate(void* a_ptr) { free(a_ptr); }
	};
	static_assert(std::is_empty<BSTArrayHeapAllocator>());

	class BSScrapArrayAllocator
	{
	public:
		void* allocate(std::size_t a_size)
		{
			const auto mem = _allocator->Allocate(a_size, 0);
			if (!mem) {
				stl::report_and_fail("out of memory"sv);
			}
			std::memset(mem, 0, a_size);
			return mem;
		}
		void deallocate(void* a_ptr) { _allocator->Deallocate(a_ptr, 0); }

	protected:
		// members
		ScrapHeap* _allocator{ nullptr };  // 00
	};
	static_assert(sizeof(BSScrapArrayAllocator) == 0x8);

	template <class T, class Allocator = BSTArrayHeapAllocator>
	class BSTArray :
		public BSTArrayBase,
		public Allocator
	{
	public:
		using value_type = T;
		using allocator_type = Allocator;
		using size_type = std::uint32_t;
		using difference_type = std::ptrdiff_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using iterator = pointer;
		using const_iterator = const_pointer;
		using reverse_iterator = std::reverse_iterator<iterator>;
		using const_reverse_iterator = std::reverse_iterator<const_iterator>;

		// 1)
		BSTArray() noexcept = default;

		// 4)
		explicit BSTArray(size_type a_count) { resize(a_count); }

		~BSTArray()
		{
			if (capacity() > 0) {
				clear();
				allocator_type().deallocate(data());
				set_data(nullptr);
				set_capacity(0, 0);
			}
		}

		SF_HEAP_REDEFINE_NEW(BSTArray<T, Allocator>)

		[[nodiscard]] constexpr reference       operator[](size_type a_pos) noexcept { return data()[a_pos]; }
		[[nodiscard]] constexpr const_reference operator[](size_type a_pos) const noexcept { return data()[a_pos]; }

		[[nodiscard]] constexpr reference       front() noexcept { return *begin(); }
		[[nodiscard]] constexpr const_reference front() const noexcept { return *begin(); }

		[[nodiscard]] constexpr reference       back() noexcept { return *std::prev(end()); }
		[[nodiscard]] constexpr const_reference back() const noexcept { return *std::prev(end()); }

		[[nodiscard]] constexpr pointer       data() noexcept { return static_cast<pointer>(_data); }
		[[nodiscard]] constexpr const_pointer data() const noexcept { return static_cast<const_pointer>(_data); }

		[[nodiscard]] constexpr iterator       begin() noexcept { return data(); }
		[[nodiscard]] constexpr const_iterator begin() const noexcept { return data(); }
		[[nodiscard]] constexpr const_iterator cbegin() const noexcept { return begin(); }

		[[nodiscard]] constexpr iterator       end() noexcept { return begin() + size(); }
		[[nodiscard]] constexpr const_iterator end() const noexcept { return begin() + size(); }
		[[nodiscard]] constexpr const_iterator cend() const noexcept { return end(); }

		[[nodiscard]] constexpr bool empty() const noexcept { return BSTArrayBase::empty(); }

		[[nodiscard]] constexpr size_type size() const noexcept { return BSTArrayBase::size(); }

		[[nodiscard]] size_type max_size() const noexcept { return std::numeric_limits<size_type>::max(); }

		void reserve(size_type a_capacity)
		{
			if (a_capacity > capacity()) {
				reserve_exact(a_capacity);
			}
		}

		[[nodiscard]] constexpr size_type capacity() const noexcept { return BSTArrayBase::capacity(); }

		void shrink_to_fit() { reserve_exact(size()); }

		void clear() { erase(begin(), end()); }

		template <class ForwardIt>
		iterator insert(const_iterator a_pos, ForwardIt a_first, ForwardIt a_last)  //
			requires(std::derived_from<typename std::iterator_traits<ForwardIt>::iterator_category, std::forward_iterator_tag>)
		{
			const auto distance = static_cast<size_type>(std::distance(a_first, a_last));
			if (distance == 0) {
				return decay_iterator(a_pos);
			}

			const auto pos = static_cast<size_type>(std::distance(cbegin(), a_pos));
			resize(size() + distance);
			const auto iter = begin() + pos;
			std::move_backward(iter, iter + distance, end());
			std::copy(a_first, a_last, iter);
			return iter;
		}

		template <class... Args>
		iterator emplace(const_iterator a_pos, Args&&... a_args)  //
			requires(std::constructible_from<value_type, Args && ...>)
		{
			const auto pos = static_cast<size_type>(std::distance(cbegin(), a_pos));
			if (pos < size()) {
				emplace_back(std::move(back()));
				std::move_backward(begin() + pos, end() - 2, end() - 1);
			} else {
				reserve_auto(size() + 1);
				_size += 1;
			}

			std::construct_at(data() + pos, std::forward<Args>(a_args)...);
			return begin() + pos;
		}

		iterator erase(const_iterator a_first, const_iterator a_last)
		{
			const auto first = decay_iterator(a_first);
			const auto last = decay_iterator(a_last);
			const auto distance = static_cast<size_type>(std::distance(first, last));
			if (distance == 0) {
				return last;
			}

			assert(distance <= size());
			std::move(last, end(), first);
			std::destroy(end() - distance, end());
			_size -= distance;
			return end();
		}

		iterator erase(const_iterator a_pos) { return erase(a_pos, std::next(a_pos)); }

		void push_back(const value_type& a_value) { emplace_back(a_value); }
		void push_back(value_type&& a_value) { emplace_back(std::move(a_value)); }

		template <class... Args>
		reference emplace_back(Args&&... a_args)  //
			requires(std::constructible_from<value_type, Args && ...>)
		{
			return *emplace(end(), std::forward<Args>(a_args)...);
		}

		void pop_back() { erase(std::prev(end())); }

		void resize(size_type a_count) { resize_impl(a_count, nullptr); }
		void resize(size_type a_count, const value_type& a_value) { resize_impl(a_count, std::addressof(a_value)); }

		void swap(BSTArray& a_rhs) noexcept
		{
			auto tmp = std::move(*this);
			*this = std::move(a_rhs);
			a_rhs = std::move(tmp);
		}

	private:
		[[nodiscard]] iterator decay_iterator(const_iterator a_iter) noexcept { return const_cast<pointer>(std::addressof(*a_iter)); }

		void reserve_auto(size_type a_capacity)
		{
			if (a_capacity > capacity()) {
				const auto grow = std::max(a_capacity, capacity() * 2);
				reserve_exact(grow);
			}
		}

		void reserve_exact(size_type a_capacity)
		{
			assert(a_capacity >= size());
			if (a_capacity == capacity()) {
				return;
			}

			const auto ndata =
				static_cast<pointer>(
					allocator_type().allocate(a_capacity * sizeof(value_type)));
			const auto odata = data();
			if (ndata != odata) {
				std::uninitialized_move_n(odata, size(), ndata);
				std::destroy_n(odata, size());
				allocator_type().deallocate(odata);
				set_data(ndata);
				set_capacity(a_capacity, a_capacity * sizeof(value_type));
			}
		}

		void resize_impl(size_type a_count, const value_type* a_value)
		{
			if (a_count < size()) {
				erase(begin() + a_count, end());
			} else if (a_count > size()) {
				reserve_auto(a_count);
				std::span<value_type> range{ data() + _size, a_count - _size };
				if (a_value) {
					std::for_each(
						range.begin(),
						range.end(),
						[=](auto& a_elem) {
							std::construct_at(std::addressof(a_elem), *a_value);
						});
				} else {
					std::uninitialized_default_construct(
						range.begin(),
						range.end());
				}
				_size = a_count;
			}
		}

		constexpr void set_data(void* a_data) noexcept { _data = a_data; }

		// members
		void* _data{ nullptr };
	};
	static_assert(sizeof(BSTArray<void*>) == 0x10);

	template <class T>
	using BSScrapArray = BSTArray<T, BSScrapArrayAllocator>;
	static_assert(sizeof(BSScrapArray<void*>) == 0x18);
}
