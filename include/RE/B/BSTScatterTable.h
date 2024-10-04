#pragma once

namespace RE
{
	struct BSCRC32
	{
		static std::uint32_t GenerateCRC(std::uint32_t a_initial, const void* a_buf, std::size_t a_len)
		{
			static REL::Relocation<std::uint32_t*> crcTable{ REL::ID(292339) };
			std::uint32_t                          c = a_initial;
			const std::uint8_t*                    u = static_cast<const std::uint8_t*>(a_buf);
			for (std::size_t i = 0; i < a_len; ++i) {
				c = crcTable.get()[(c ^ u[i]) & 0xFF] ^ (c >> 8);
			}

			return c;
		}
	};

	namespace BSHash
	{
		struct FNV1a
		{
			std::size_t operator()(const std::uint32_t& key)
			{
				return std::_Fnv1a_append_bytes(0xCBF29CE484222325, reinterpret_cast<const unsigned char*>(&key), 4);
			}
		};

		template <typename T>
		struct String
		{
			std::size_t operator()(const T& key)
			{
				return BSCRC32::GenerateCRC(0, key.c_str(), key.size());
			}
		};

		struct XOR
		{
			std::size_t operator()(const BSFixedString& key)
			{
				return (reinterpret_cast<std::uint64_t>(key.c_str()) >> 32) ^ (reinterpret_cast<std::uint64_t>(key.c_str()) & 0xFFFFFFFF);
			}

			std::size_t operator()(const BSFixedStringW& key)
			{
				return (reinterpret_cast<std::uint64_t>(key.c_str()) >> 32) ^ (reinterpret_cast<std::uint64_t>(key.c_str()) & 0xFFFFFFFF);
			}
		};
	}

	template <typename T>
	struct BSTScatterTableDefaultHashPolicy
	{
		std::size_t operator()(const T& key) = delete;
	};

	template <>
	struct BSTScatterTableDefaultHashPolicy<BSFixedString>
	{
		std::size_t operator()(const BSFixedString& key)
		{
			return BSHash::XOR()(key);
		}
	};

	template <>
	struct BSTScatterTableDefaultHashPolicy<BSFixedStringCS>
	{
		std::size_t operator()(const BSFixedStringCS& key)
		{
			return BSHash::XOR()(key);
		}
	};

	template <>
	struct BSTScatterTableDefaultHashPolicy<BSFixedStringW>
	{
		std::size_t operator()(const BSFixedStringW& key)
		{
			return BSHash::XOR()(key);
		}
	};

	template <>
	struct BSTScatterTableDefaultHashPolicy<BSFixedStringWCS>
	{
		std::size_t operator()(const BSFixedStringW& key)
		{
			return BSHash::XOR()(key);
		}
	};

	template <>
	struct BSTScatterTableDefaultHashPolicy<std::uint32_t>
	{
		std::size_t operator()(const std::uint32_t& key)
		{
			return BSCRC32::GenerateCRC(0, &key, 4);
		}
	};

	template <class T1, class T2>
	struct BSTScatterTableDefaultKVStorage
	{
		BSTScatterTableDefaultKVStorage() = default;

		BSTScatterTableDefaultKVStorage(const T1& a_first, const T2& a_second) :
			key(a_first),
			value(a_second)
		{}

		BSTScatterTableDefaultKVStorage(const BSTScatterTableDefaultKVStorage& a_rhs) :
			key(a_rhs.Key),
			value(a_rhs.Value)
		{}

		BSTScatterTableDefaultKVStorage(const std::pair<T1, T2>& pair) :
			key(pair.first),
			value(pair.second)
		{}

		BSTScatterTableDefaultKVStorage& operator=(const BSTScatterTableDefaultKVStorage& a_rhs)
		{
			key = a_rhs.key;
			value = a_rhs.value;
		}

		BSTScatterTableDefaultKVStorage& operator=(BSTScatterTableDefaultKVStorage&& a_rhs)
		{
			key = std::move(a_rhs.key);
			value = std::move(a_rhs.value);
		}

		T1 key{};
		T2 value{};
	};

	template <class Key, class T, template <class, class> class Storage = BSTScatterTableDefaultKVStorage>
	struct BSTScatterTableTraits
	{
		using key_type = Key;
		using mapped_type = T;
		using value_type = Storage<Key, T>;

		const key_type& operator()(const value_type& a_value) const
		{
			return a_value.key;
		}
	};

	template <class Key, class T, template <class, class> class Storage = BSTScatterTableDefaultKVStorage>
	struct BSTScatterTableEntry
	{
		Storage<Key, T> value;
		std::int32_t    nextIndex;
		std::int32_t    index;
	};

	template <class T, std::uint32_t N = 8>
	struct BSTScatterTableHeapAllocator
	{
		using entry_type = T;
		using size_type = std::uint32_t;

		BSTScatterTableHeapAllocator() = default;

		entry_type* allocate(std::size_t a_num)
		{
			auto size = a_num * sizeof(entry_type);
			auto mem = (entry_type*)RE::malloc(size, 8);
			std::memset(mem, 0, size);
			for (std::uint64_t i = 0; i < a_num; ++i) {
				mem[i].nextIndex = -1;
				mem[i].index = -1;
			}

			return mem;
		}

		void deallocate(entry_type* a_ptr)
		{
			RE::free(a_ptr, true);
		}

		size_type min_size() const
		{
			return static_cast<size_type>(1) << 3;
		}

		size_type max_size() const
		{
			return static_cast<size_type>(1) << 31;
		}
	};

	// Maybe related to the allocator type?
	struct BSTScatterTableParent1
	{
	protected:
		void*         _unk00{ nullptr };
		std::uint64_t _unk08{ 0 };
		std::uint64_t _unk10{ 0 };
	};

	// Maybe related to the allocator type?
	struct BSTScatterTableParent2
	{
	protected:
		void*         _unk00{ nullptr };
		std::uint64_t _unk08{ 0 };
	};

	template <
		class Traits,
		std::uint32_t N,
		template <class, std::uint32_t> class Allocator,
		class Hash,
		class KeyEqual,
		class Parent>
	class BSTScatterTableBase : public Parent
	{
	public:
		using traits_type = Traits;
		using key_type = typename traits_type::key_type;
		using mapped_type = typename traits_type::mapped_type;
		using value_type = typename traits_type::value_type;
		using hasher = Hash;
		using key_equal = KeyEqual;
		using size_type = std::uint32_t;

		using entry_type = BSTScatterTableEntry<key_type, mapped_type>;
		using allocator_type = Allocator<entry_type, N>;

		BSTScatterTableBase() :
			Parent()
		{}

		~BSTScatterTableBase()
		{
			if (_table) {
				deallocate(_table);
				_table = nullptr;
			}
		}

		SF_HEAP_REDEFINE_NEW(BSTScatterTableBase);

		template <class U>
		struct iterator_base
		{
			using difference_type = std::ptrdiff_t;
			using value_type = U;
			using pointer = U*;
			using reference = U&;
			using iterator_category = std::forward_iterator_tag;

			iterator_base() = default;

			iterator_base(const iterator_base& a_rhs) :
				_entry(a_rhs._entry),
				_end(a_rhs._end)
			{}

			iterator_base(iterator_base&& a_rhs) noexcept :
				_entry(std::move(a_rhs._entry)),
				_end(a_rhs._end)
			{
				a_rhs._entry = a_rhs._end;
			}

			iterator_base(entry_type* a_entry, entry_type* a_end) :
				_entry(a_entry),
				_end(a_end)
			{
				while (_entry != _end && _entry->nextIndex == -1) {
					++_entry;
				}
			}

			~iterator_base() = default;

			iterator_base& operator=(const iterator_base& a_rhs)
			{
				_entry = a_rhs._entry;
			}

			iterator_base& operator=(iterator_base&& a_rhs)
			{
				_entry = std::move(a_rhs._entry);
				a_rhs._entry = a_rhs._end;
			}

			void swap(iterator_base& a_rhs)
			{
				std::swap(_entry, a_rhs._entry);
			}

			reference operator*() const
			{
				return _entry->value;
			}

			pointer operator->() const
			{
				return std::addressof(_entry->value);
			}

			bool operator==(const iterator_base& a_rhs) const
			{
				return _entry == a_rhs._entry;
			}

			bool operator!=(const iterator_base& a_rhs) const
			{
				return !operator==(a_rhs);
			}

			iterator_base& operator++()
			{
				do {
					++_entry;
				} while (_entry != _end && _entry->nextIndex == -1);
				return *this;
			}

			iterator_base operator++(int)
			{
				iterator_base tmp{ *this };
				operator++();
				return tmp;
			}

		private:
			entry_type* _entry{ nullptr };
			entry_type* _end{ nullptr };
		};

		using iterator = iterator_base<value_type>;
		using const_iterator = iterator_base<const value_type>;

		hasher hash_function() const
		{
			return hasher();
		}

		key_equal key_eq() const
		{
			return key_equal();
		}

		bool comp_key(const key_type& a_lhs, const key_type& a_rhs) const
		{
			return key_eq()(a_lhs, a_rhs);
		}

		iterator begin()
		{
			return get_entries() ? make_iterator(get_entries()) : iterator();
		}

		const_iterator begin() const
		{
			return get_entries() ? make_iterator(get_entries()) : const_iterator();
		}

		const_iterator cbegin() const
		{
			return begin();
		}

		iterator end()
		{
			return get_entries() ? make_iterator(get_entries() + _size) : iterator();
		}

		const_iterator end() const
		{
			return get_entries() ? make_iterator(get_entries() + _size) : const_iterator();
		}

		const_iterator cend() const
		{
			return end();
		}

		bool empty() const
		{
			return !get_entries() || _free == 0;
		}

		size_type size() const
		{
			return _size - _free;
		}

		size_type max_size() const
		{
			return allocator_type().max_size();
		}

		std::pair<iterator, bool> insert(const value_type& a_value)
		{
			return insert_impl(false, a_value);
		}

		std::pair<iterator, bool> insert(value_type&& a_value)
		{
			return insert_impl(false, std::move(a_value));
		}

		std::pair<iterator, bool> insert_or_assign(const value_type& a_value)
		{
			return insert_impl(true, a_value);
		}

		std::pair<iterator, bool> insert_or_assign(value_type&& a_value)
		{
			return insert_impl(true, std::move(a_value));
		}

		std::pair<iterator, bool> insert_or_assign(const key_type& a_key, const mapped_type& a_value)
		{
			return insert_impl(true, value_type(a_key, a_value));
		}

		size_type erase(const key_type& a_key)
		{
			if (!get_entries()) {  // no entries
				return 0;
			}

			auto entry = get_pos(calc_idx(a_key));
			if (entry->nextIndex == -1) {  // key not in table
				return 0;
			}

			entry_type* tail = nullptr;
			while (!comp_key(get_key(entry->value), a_key)) {  // find key in table
				tail = entry;
				entry = get_pos(entry->nextIndex);
				if (entry == get_pos(_size)) {
					return 0;
				}
			}

			entry->value.~value_type();

			if (entry->nextIndex == _size) {  // if no chain
				if (tail) {
					tail->nextIndex = static_cast<std::uint32_t>(_size);
				}
				entry->nextIndex = -1;
			} else {  // else move next entry into current
				new (entry) entry_type(std::move(*get_pos(entry->nextIndex)));
			}

			++_free;
			return 1;
		}

		iterator find(const key_type& a_key)
		{
			auto entry = find_impl(a_key);
			return entry ? make_iterator(entry) : end();
		}

		const_iterator find(const key_type& a_key) const
		{
			auto entry = find_impl(a_key);
			return entry ? make_iterator(entry) : end();
		}

		bool contains(const key_type& a_key) const
		{
			return find(a_key) != end();
		}

		void reserve(size_type a_count)
		{
			if (a_count <= _size) {
				return;
			}

			std::uint32_t leftShifts = 0;
			while ((a_count & static_cast<std::uint32_t>(1 << 31)) == 0) {
				a_count <<= 1;
				++leftShifts;
			}
			auto bitPos = 31 - leftShifts;
			auto newCount = static_cast<std::uint32_t>(1 << bitPos);
			grow(newCount);
		}

		void clear()
		{
			auto entries = get_entries();
			clear_entries(0, _size);
			_free = _size;
		}

		mapped_type& operator[](const key_type& a_key)
		{
			if (auto iter = find(a_key); iter != end()) {
				return iter->value;
			} else {
				return insert(value_type{ a_key, mapped_type{} }).first->value;
			}
		}

	private:
		bool grow()
		{
			if (_size == (std::uint32_t)1 << 31) {
				return false;
			}

			std::uint32_t newCapacity = static_cast<std::uint32_t>(_size ? _size << 1 : min_size());
			return grow(newCapacity);
		}

		void clear_entries(std::uint64_t a_start, std::uint64_t a_end)
		{
			for (std::uint64_t i = a_start; i < a_end; ++i) {
				auto entry = get_pos(i);
				if (entry->nextIndex != -1) {
					entry->value.~value_type();
					entry->nextIndex = -1;
					entry->index = -1;
				}
			}
		}

		bool grow(std::uint32_t a_newCapacity)
		{
			auto oldEntries = get_entries();
			auto begIter = begin();
			auto endIter = end();

			auto newEntries = allocate(a_newCapacity);
			if (!newEntries) {
				return false;
			} else if (newEntries == oldEntries) {
				_size = a_newCapacity;
				return true;
			} else {
				_size = a_newCapacity;
				_lastFree = a_newCapacity;
				_free = a_newCapacity;
				set_entries(newEntries);

				while (begIter != endIter) {
					insert(std::move(*begIter));
					++begIter;
				}

				deallocate(oldEntries);
				return true;
			}
		}

		std::size_t calc_hash(const key_type& a_key) const
		{
			return hash_function()(a_key);
		}

		std::uint64_t calc_idx(const key_type& a_key) const
		{
			return calc_hash(a_key) & (_size - 1);  // capacity is always a factor of 2, so this is a faster modulo
		}

		entry_type* find_impl(const key_type& a_key) const
		{
			if (!get_entries()) {
				return nullptr;
			}

			auto probe = get_pos(calc_idx(a_key));  // try ideal pos
			if (probe->nextIndex == -1) {
				return nullptr;  // nothing there
			}

			do {
				if (comp_key(get_key(probe->value), a_key)) {
					return probe;
				} else {
					probe = get_pos(probe->nextIndex);
				}
			} while (probe != get_pos(_size));  // follow chain

			return nullptr;
		}

		template <class Arg>
		std::pair<iterator, bool> insert_impl(bool a_overwrite, Arg&& a_value)
		{
			if (!get_entries() || !_free) {
				if (!grow()) {
					return std::make_pair(end(), false);  // maybe throw?
				}
			}

			auto idealEntry = calc_pos(get_key(a_value));

			// Slot is empty, fill it
			if (idealEntry->nextIndex == -1) {
				new (std::addressof(idealEntry->value)) value_type(std::forward<Arg>(a_value));
				idealEntry->nextIndex = static_cast<std::int32_t>(_size);
				idealEntry->index = static_cast<std::int32_t>(std::distance(get_pos(0), idealEntry));
				--_free;
				return std::make_pair(make_iterator(idealEntry), true);
			}

			for (auto iter = idealEntry; iter != get_pos(_size); iter = get_pos(iter->nextIndex)) {
				if (comp_key(get_key(iter->value), get_key(a_value))) {
					if (a_overwrite) {
						iter->value.~value_type();
						new (std::addressof(iter->value)) value_type(std::forward<Arg>(a_value));
					}
					return std::make_pair(make_iterator(iter), false);
				}
			}

			auto freeEntry = get_free_entry();

			auto takenIdealEntry = calc_pos(get_key(idealEntry->value));
			if (takenIdealEntry == idealEntry) {  // if entry occupying our slot would've hashed here anyway
				freeEntry->index = idealEntry->index;
				freeEntry->nextIndex = idealEntry->nextIndex;
				idealEntry->nextIndex = static_cast<std::int32_t>(std::distance(get_pos(0), freeEntry));
				new (std::addressof(freeEntry->value)) value_type(std::forward<Arg>(a_value));
				--_free;
				return std::make_pair(make_iterator(freeEntry), true);
			}

			while (takenIdealEntry->nextIndex != static_cast<std::int32_t>(std::distance(get_pos(0), idealEntry))) {  // find entry that links here
				takenIdealEntry = get_pos(takenIdealEntry->nextIndex);
			}

			// move taken slot out, so we can move in
			new (std::addressof(freeEntry->value)) value_type(std::move(idealEntry->value));
			freeEntry->nextIndex = idealEntry->nextIndex;
			freeEntry->index = idealEntry->index;
			takenIdealEntry->nextIndex = static_cast<std::int32_t>(std::distance(get_pos(0), freeEntry));
			new (std::addressof(idealEntry->value)) value_type(std::forward<Arg>(a_value));
			idealEntry->nextIndex = static_cast<std::int32_t>(_size);
			--_free;
			return std::make_pair(make_iterator(idealEntry), true);
		}

		entry_type* get_pos(std::uint64_t a_index) const
		{
			return const_cast<entry_type*>(get_entries() + a_index);
		}

		entry_type* calc_pos(const key_type& a_key) const
		{
			return get_pos(calc_idx(a_key));
		}

		entry_type* get_free_entry()
		{
			entry_type* entry = nullptr;
			do {
				_lastFree = (_size - 1) & (_lastFree - 1);
				entry = get_pos(_lastFree);
			} while (entry->nextIndex != -1);

			return entry;
		}

		const key_type& get_key(const value_type& a_value) const
		{
			traits_type traits;
			return traits(a_value);
		}

		iterator make_iterator(entry_type* a_entry)
		{
			return iterator(a_entry, _table + _size);
		}

		const_iterator make_iterator(entry_type* a_entry) const
		{
			return const_iterator(a_entry, _table + _size);
		}

		entry_type* allocate(std::size_t a_num)
		{
			return allocator_type().allocate(a_num);
		}

		void deallocate(entry_type* a_ptr)
		{
			allocator_type().deallocate(a_ptr);
		}

		entry_type* get_entries() const
		{
			return _table;
		}

		void set_entries(entry_type* a_entries)
		{
			_table = a_entries;
		}

		size_type min_size() const
		{
			return allocator_type().min_size();
		}

		entry_type*   _table{ nullptr };
		std::uint64_t _size{ 0 };
		std::uint64_t _free{ 0 };
		std::uint64_t _lastFree{ 0 };
	};

	template <class Key, class T, class Hash = BSTScatterTableDefaultHashPolicy<Key>, class KeyEqual = std::equal_to<Key>>
	using BSTHashMap = BSTScatterTableBase<BSTScatterTableTraits<Key, T>, 8, BSTScatterTableHeapAllocator, Hash, KeyEqual, BSTScatterTableParent1>;
	static_assert(sizeof(BSTHashMap<void*, void*>) == 0x38);

	template <class Key, class T, class Hash = BSTScatterTableDefaultHashPolicy<Key>, class KeyEqual = std::equal_to<Key>>
	using BSTHashMap2 = BSTScatterTableBase<BSTScatterTableTraits<Key, T>, 8, BSTScatterTableHeapAllocator, Hash, KeyEqual, BSTScatterTableParent2>;
	static_assert(sizeof(BSTHashMap2<void*, void*>) == 0x30);
}
