#pragma once

namespace RE
{
	struct BSCRC32
	{
		static uint32_t GenerateCRC(uint32_t initial, const void* buf, size_t len)
		{
			static REL::Relocation<uint32_t*> uiCRCTable{ REL::ID(292339) };
			uint32_t c = initial;
			const uint8_t* u = static_cast<const uint8_t*>(buf);
			for (size_t i = 0; i < len; ++i)
			{
				c = uiCRCTable.get()[(c ^ u[i]) & 0xFF] ^ (c >> 8);
			}
			return c;
		}
	};

	namespace BSHash
	{
		class FNV1a
		{
		public:
			size_t operator()(const uint32_t& key)
			{
				return std::_Fnv1a_append_bytes(0xCBF29CE484222325, reinterpret_cast<const unsigned char*>(&key), 4);
			}
		};

		template<typename T>
		class String
		{
			size_t operator()(const T& key)
			{
				return BSCRC32::GenerateCRC(0, key.c_str(), key.size());
			}
		};

		class XOR
		{
		public:
			size_t operator()(const BSFixedString& key)
			{
				return (reinterpret_cast<uint64_t>(key.c_str()) >> 32) ^ (reinterpret_cast<uint64_t>(key.c_str()) & 0xFFFFFFFF);
			}
			size_t operator()(const BSFixedStringW& key)
			{
				return (reinterpret_cast<uint64_t>(key.c_str()) >> 32) ^ (reinterpret_cast<uint64_t>(key.c_str()) & 0xFFFFFFFF);
			}
		};
	}

	template<typename T>
	class BSTScatterTableDefaultHashPolicy
	{
	public:
		size_t operator()(const T& key) = delete;
	};

	template<> class BSTScatterTableDefaultHashPolicy<BSFixedString>
	{
	public:
		size_t operator()(const BSFixedString& key)
		{
			return BSHash::XOR()(key);
		}
	};

	template<> class BSTScatterTableDefaultHashPolicy<BSFixedStringCS>
	{
	public:
		size_t operator()(const BSFixedStringCS& key)
		{
			return BSHash::XOR()(key);
		}
	};

	template<> class BSTScatterTableDefaultHashPolicy<BSFixedStringW>
	{
	public:
		size_t operator()(const BSFixedStringW& key)
		{
			return BSHash::XOR()(key);
		}
	};

	template<> class BSTScatterTableDefaultHashPolicy<BSFixedStringWCS>
	{
	public:
		size_t operator()(const BSFixedStringW& key)
		{
			return BSHash::XOR()(key);
		}
	};

	template<> class BSTScatterTableDefaultHashPolicy<uint32_t>
	{
	public:
		size_t operator()(const uint32_t& key)
		{
			return BSCRC32::GenerateCRC(0, &key, 4);
		}
	};

	template <class T1, class T2>
	struct BSTScatterTableDefaultKVStorage
	{
	public:
		BSTScatterTableDefaultKVStorage() :
			Key(),
			Value()
		{}

		BSTScatterTableDefaultKVStorage(const T1& a_first, const T2& a_second) :
			Key(a_first),
			Value(a_second)
		{}

		BSTScatterTableDefaultKVStorage(const BSTScatterTableDefaultKVStorage& a_rhs) :
			Key(a_rhs.Key),
			Value(a_rhs.Value)
		{}

		BSTScatterTableDefaultKVStorage& operator=(const BSTScatterTableDefaultKVStorage& a_rhs)
		{
			Key = a_rhs.Key;
			Value = a_rhs.Value;
		}

		BSTScatterTableDefaultKVStorage& operator=(BSTScatterTableDefaultKVStorage&& a_rhs)
		{
			Key = std::move(a_rhs.Key);
			Value = std::move(a_rhs.Value);
		}

		// Convenience to convert from std::make_pair
		BSTScatterTableDefaultKVStorage(const std::pair<T1, T2>& pair) : 
			Key(pair.first), 
			Value(pair.second)
		{}


		T1 Key;	// 00
		T2 Value;	// ??
	};

	template <class Key, class T, template<class, class> class Storage = BSTScatterTableDefaultKVStorage>
	struct BSTScatterTableTraits
	{
	public:
		using key_type = Key;
		using mapped_type = T;
		using value_type = Storage<Key, T>;


		const key_type& operator()(const value_type& a_value) const
		{
			return a_value.Key;
		}
	};

	template <class Key, class T, template<class,class> class Storage = BSTScatterTableDefaultKVStorage>
	struct BSTScatterTableEntry
	{
		Storage<Key, T> Value;
		int32_t iNextIndex;
		int32_t iIndex;
	};

	template <class T, uint32_t N = 8>
	struct BSTScatterTableHeapAllocator
	{
	public:
		using entry_type = T;
		using size_type = uint32_t;

		BSTScatterTableHeapAllocator() {}

		entry_type* allocate(std::size_t a_num)
		{
			auto size = a_num * sizeof(entry_type);
			auto mem = (entry_type*)RE::malloc(size, 8);
			memset(mem, 0, size);
			for (uint64_t i = 0; i < a_num; ++i)
			{
				mem[i].iNextIndex = -1;
				mem[i].iIndex = -1;
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
		void* unk00 = nullptr;
		uint64_t unk08 = 0;
		uint64_t unk10 = 0;
	};

	// Maybe related to the allocator type?
	struct BSTScatterTableParent2
	{
		void* unk00 = nullptr;
		uint64_t unk08 = 0;
	};

	template <
		class Traits,
		uint32_t N, 
		template <class, uint32_t> class Allocator, 
		class Hash, 
		class KeyEqual,
		class Parent
	>
	class BSTScatterTableBase : public Parent
	{
	public:
		using traits_type = Traits;
		using key_type = typename traits_type::key_type;
		using mapped_type = typename traits_type::mapped_type;
		using value_type = typename traits_type::value_type;
		using hasher = Hash;
		using key_equal = KeyEqual;
		using size_type = uint32_t;

		using entry_type = BSTScatterTableEntry<key_type, mapped_type>;
		using allocator_type = Allocator<entry_type, N>;

		BSTScatterTableBase() : Parent(),
			pTable(nullptr),
			uiSize(0),
			uiFree(0),
			uiLastFree(0)
		{
		}
		~BSTScatterTableBase()
		{
			if (pTable)
			{
				deallocate(pTable);
				pTable = nullptr;
			}
		}

		SF_HEAP_REDEFINE_NEW(BSTScatterTableBase);

		template <class U>
		struct iterator_base
		{
		public:
			typedef std::ptrdiff_t difference_type;
			typedef U value_type;
			typedef U* pointer;
			typedef U& reference;
			typedef std::forward_iterator_tag iterator_category;

			iterator_base() :
				_entry(nullptr),
				_end(nullptr)
			{}

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
				while (_entry != _end && _entry->iNextIndex == -1) {
					++_entry;
				}
			}

			~iterator_base(){}

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
				return _entry->Value;
			}

			pointer operator->() const
			{
				return std::addressof(_entry->Value);
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
				} while (_entry != _end && _entry->iNextIndex == -1);
				return *this;
			}

			iterator_base operator++(int)
			{
				iterator_base tmp{ *this };
				operator++();
				return tmp;
			}

		private:
			entry_type* _entry;
			entry_type* _end;
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
			return get_entries() ? make_iterator(get_entries() + uiSize) : iterator();
		}


		const_iterator end() const
		{
			return get_entries() ? make_iterator(get_entries() + uiSize) : const_iterator();
		}


		const_iterator cend() const
		{
			return end();
		}


		bool empty() const
		{
			return !get_entries() || uiFree == 0;
		}


		size_type size() const
		{
			return uiSize - uiFree;
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
			if (entry->iNextIndex == -1) {	 // key not in table
				return 0;
			}

			entry_type* tail = nullptr;
			while (!comp_key(get_key(entry->Value), a_key)) {  // find key in table
				tail = entry;
				entry = get_pos(entry->iNextIndex);
				if (entry == get_pos(uiSize)) {
					return 0;
				}
			}

			entry->Value.~value_type();

			if (entry->iNextIndex == uiSize) {	 // if no chain
				if (tail) {
					tail->iNextIndex = static_cast<uint32_t>(uiSize);
				}
				entry->iNextIndex = -1;
			}
			else {  // else move next entry into current
				new (entry) entry_type(std::move(*get_pos(entry->iNextIndex)));
			}

			++uiFree;
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
			if (a_count <= uiSize) {
				return;
			}

			uint32_t leftShifts = 0;
			while ((a_count & static_cast<uint32_t>(1 << 31)) == 0) {
				a_count <<= 1;
				++leftShifts;
			}
			auto bitPos = 31 - leftShifts;
			auto newCount = static_cast<uint32_t>(1 << bitPos);
			grow(newCount);
		}

		void clear()
		{
			auto entries = get_entries();
			clear_entries(0, uiSize);
			uiFree = uiSize;
		}

		mapped_type& operator[](const key_type& a_key)
		{
			if (auto iter = find(a_key); iter != end()) {
				return iter->Value;
			} else {
				return insert(value_type{ a_key, mapped_type{} }).first->Value;
			}
		}

	private:
		 bool grow()
		 {
			 if (uiSize == (uint32_t)1 << 31) {
				 return false;
			 }

			 uint32_t newCapacity = static_cast<uint32_t>(uiSize ? uiSize << 1 : min_size());
			 return grow(newCapacity);
		 }

		 void clear_entries(uint64_t start, uint64_t end)
		 {
			 for (uint64_t i = start; i < end; ++i)
			 {
				 auto entry = get_pos(i);
				 if (entry->iNextIndex != -1)
				 {
					 entry->Value.~value_type();
					 entry->iNextIndex = -1;
					 entry->iIndex = -1;
				 }
			 }
		 }

		 bool grow(uint32_t a_newCapacity)
		 {
			 auto oldEntries = get_entries();
			 auto begIter = begin();
			 auto endIter = end();

			 auto newEntries = allocate(a_newCapacity);
			 if (!newEntries) {
				 return false;
			 }
			 else if (newEntries == oldEntries) {
				 uiSize = a_newCapacity;
				 return true;
			 }
			 else {
				 uiSize = a_newCapacity;
				 uiLastFree = a_newCapacity;
				 uiFree = a_newCapacity;
				 set_entries(newEntries);

				 while (begIter != endIter) {
					 insert(std::move(*begIter));
					 ++begIter;
				 }

				 deallocate(oldEntries);
				 return true;
			 }
		 }

		 size_t calc_hash(const key_type& a_key) const
		 {
			 return hash_function()(a_key);
		 }

		 uint64_t calc_idx(const key_type& a_key) const
		 {
			 return calc_hash(a_key) & (uiSize - 1);	// capacity is always a factor of 2, so this is a faster modulo
		 }

		 entry_type* find_impl(const key_type& a_key) const
		 {
			 if (!get_entries()) {
				 return nullptr;
			 }

			 auto probe = get_pos(calc_idx(a_key));  // try ideal pos
			 if (probe->iNextIndex == -1) {
				 return nullptr;	 // nothing there
			 }

			 do {
				 if (comp_key(get_key(probe->Value), a_key)) {
					 return probe;
				 }
				 else {
					 probe = get_pos(probe->iNextIndex);
				 }
			 } while (probe != get_pos(uiSize));  // follow chain

			 return nullptr;
		 }

		 template <class Arg>
		 std::pair<iterator, bool> insert_impl(bool a_overwrite, Arg&& a_value)
		 {
			 if (!get_entries() || !uiFree) {
				 if (!grow()) {
					 return std::make_pair(end(), false);  // maybe throw?
				 }
			 }

			 auto idealEntry = calc_pos(get_key(a_value));

			 // Slot is empty, fill it
			 if (idealEntry->iNextIndex == -1) {
				 new (std::addressof(idealEntry->Value)) value_type(std::forward<Arg>(a_value));
				 idealEntry->iNextIndex = static_cast<int32_t>(uiSize);
				 idealEntry->iIndex = static_cast<int32_t>(std::distance(get_pos(0), idealEntry));
				 --uiFree;
				 return std::make_pair(make_iterator(idealEntry), true);
			 }

			 for (auto iter = idealEntry; iter != get_pos(uiSize); iter = get_pos(iter->iNextIndex)) {
				 if (comp_key(get_key(iter->Value), get_key(a_value))) {
					 if (a_overwrite) {
						 iter->Value.~value_type();
						 new (std::addressof(iter->Value)) value_type(std::forward<Arg>(a_value));
					 }
					 return std::make_pair(make_iterator(iter), false);
				 }
			 }

			 auto freeEntry = get_free_entry();

			 auto takenIdealEntry = calc_pos(get_key(idealEntry->Value));
			 if (takenIdealEntry == idealEntry) {  // if entry occupying our slot would've hashed here anyway
				 freeEntry->iIndex = idealEntry->iIndex;
				 freeEntry->iNextIndex = idealEntry->iNextIndex;
				 idealEntry->iNextIndex = static_cast<int32_t>(std::distance(get_pos(0), freeEntry));
				 new (std::addressof(freeEntry->Value)) value_type(std::forward<Arg>(a_value));
				 --uiFree;
				 return std::make_pair(make_iterator(freeEntry), true);
			 }

			 while (takenIdealEntry->iNextIndex != static_cast<int32_t>(std::distance(get_pos(0), idealEntry))) {  // find entry that links here
				 takenIdealEntry = get_pos(takenIdealEntry->iNextIndex);
			 }

			 // move taken slot out, so we can move in
			 new (std::addressof(freeEntry->Value)) value_type(std::move(idealEntry->Value));
			 freeEntry->iNextIndex = idealEntry->iNextIndex;
			 freeEntry->iIndex = idealEntry->iIndex;
			 takenIdealEntry->iNextIndex = static_cast<int32_t>(std::distance(get_pos(0), freeEntry));
			 new (std::addressof(idealEntry->Value)) value_type(std::forward<Arg>(a_value));
			 idealEntry->iNextIndex = static_cast<int32_t>(uiSize);
			 --uiFree;
			 return std::make_pair(make_iterator(idealEntry), true);
		 }

		 entry_type* get_pos(uint64_t index) const
		 {
			 return const_cast<entry_type*>(get_entries() + index);
		 }

		 entry_type* calc_pos(const key_type& a_key) const
		 {
			 return get_pos(calc_idx(a_key));
		 }

		 entry_type* get_free_entry()
		 {
			 entry_type* entry = nullptr;
			 do {
				 uiLastFree = (uiSize - 1) & (uiLastFree - 1);
				 entry = get_pos(uiLastFree);
			 } while (entry->iNextIndex != -1);

			 return entry;
		 }

		 const key_type& get_key(const value_type& a_value) const
		 {
			 traits_type traits;
			 return traits(a_value);
		 }

		 iterator make_iterator(entry_type* a_entry)
		 {
			 return iterator(a_entry, pTable + uiSize);
		 }

		 const_iterator make_iterator(entry_type* a_entry) const
		 {
			 return const_iterator(a_entry, pTable + uiSize);
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
			 return pTable;
		 }
		 void set_entries(entry_type* a_entries)
		 {
			 pTable = a_entries;
		 }
		 size_type min_size() const
		 {
			 return allocator_type().min_size();
		 }

		entry_type* pTable;
		uint64_t uiSize;
		uint64_t uiFree;
		uint64_t uiLastFree;
	};

	template <class Key, class T, class Hash = BSTScatterTableDefaultHashPolicy<Key>, class KeyEqual = std::equal_to<Key>>
	using BSTHashMap = BSTScatterTableBase<BSTScatterTableTraits<Key, T>, 8, BSTScatterTableHeapAllocator, Hash, KeyEqual, BSTScatterTableParent1>;
	static_assert(sizeof(BSTHashMap<void*, void*>) == 0x38);

	template <class Key, class T, class Hash = BSTScatterTableDefaultHashPolicy<Key>, class KeyEqual = std::equal_to<Key>>
	using BSTHashMap2 = BSTScatterTableBase<BSTScatterTableTraits<Key, T>, 8, BSTScatterTableHeapAllocator, Hash, KeyEqual, BSTScatterTableParent2>;
	static_assert(sizeof(BSTHashMap2<void*, void*>) == 0x30);
}
