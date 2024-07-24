#pragma once

namespace RE
{

	class ScrapHeap;
	struct HeapStats;
	struct MemoryStats;

	enum class MEM_CONTEXT : std::int32_t;

	class MemoryManager
	{
	public:
		struct AutoScrapBuffer
		{
		public:
			AutoScrapBuffer() { ctor(0, 0); }
			AutoScrapBuffer(std::size_t a_size, std::size_t a_alignment) { ctor(a_size, a_alignment); }
			~AutoScrapBuffer() { dtor(); }

			[[nodiscard]] void* GetPtr() const noexcept { return ptr; }

			// members
			void* ptr{ nullptr };  // 0

		private:
			AutoScrapBuffer* ctor(std::size_t a_size, std::size_t a_alignment)
			{
				using func_t = decltype(&AutoScrapBuffer::ctor);
				REL::Relocation<func_t> func{ ID::MemoryManager::AutoScrapBuffer::ctor };
				return func(this, a_size, a_alignment);
			}

			void dtor()
			{
				using func_t = decltype(&AutoScrapBuffer::dtor);
				REL::Relocation<func_t> func{ ID::MemoryManager::AutoScrapBuffer::dtor };
				return func(this);
			}
		};
		static_assert(sizeof(AutoScrapBuffer) == 0x8);

		[[nodiscard]] static MemoryManager* GetSingleton()
		{
			using func_t = decltype(&MemoryManager::GetSingleton);
			const REL::Relocation<func_t> func{ ID::MemoryManager::GetSingleton };
			return func();
		}

		[[nodiscard]] void* Allocate(std::size_t a_size, std::uint32_t a_alignment, bool a_alignmentRequired)
		{
			using func_t = decltype(&MemoryManager::Allocate);
			const REL::Relocation<func_t> func{ ID::MemoryManager::Allocate };
			return func(this, a_size, a_alignment, a_alignmentRequired);
		}

		void Free(void* a_ptr, bool a_alignmentRequired)
		{
			using func_t = decltype(&MemoryManager::Free);
			const REL::Relocation<func_t> func{ ID::MemoryManager::Free };
			return func(this, a_ptr, a_alignmentRequired);
		}

		ScrapHeap* GetThreadScrapHeap()
		{
			using func_t = decltype(&MemoryManager::GetThreadScrapHeap);
			const REL::Relocation<func_t> func{ ID::MemoryManager::GetThreadScrapHeap };
			return func(this);
		}
	};

	[[nodiscard]] inline void* malloc(std::size_t a_size, std::size_t a_alignment = 0)
	{
		auto mem = MemoryManager::GetSingleton();
		return mem->Allocate(a_size, a_alignment, a_alignment > 0);
	}

	template <class T>
	[[nodiscard]] T* malloc(bool a_alignmentRequired = false)
	{
		if (a_alignmentRequired)
			return static_cast<T*>(malloc(sizeof(T), alignof(T)));

		return static_cast<T*>(malloc(sizeof(T)));
	}

	[[nodiscard]] inline void* calloc(std::size_t a_count, std::size_t a_size)
	{
		const auto mem = malloc(a_count * a_size);
		if (mem)
			std::memset(mem, 0, a_count * a_size);

		return mem;
	}

	template <class T>
	[[nodiscard]] T* calloc(std::size_t a_count)
	{
		return static_cast<T*>(calloc(a_count, sizeof(T)));
	}

	inline void free(void* a_ptr, bool a_alignmentRequired = false)
	{
		auto mem = MemoryManager::GetSingleton();
		mem->Free(a_ptr, a_alignmentRequired);
	}

	class __declspec(novtable) IMemoryStoreBase
	{
	public:
		static constexpr auto RTTI{ RTTI::IMemoryStoreBase };
		static constexpr auto VTABLE{ VTABLE::IMemoryStoreBase };

		virtual ~IMemoryStoreBase() = default;  // 00

		// add
		virtual std::size_t Size(void const* a_mem) const = 0;                 // 01
		virtual void        GetMemoryStats(MemoryStats* a_stats) = 0;          // 02
		virtual bool        ContainsBlockImpl(const void* a_block) const = 0;  // 03
	};
	static_assert(sizeof(IMemoryStoreBase) == 0x8);

	class __declspec(novtable) IMemoryStore :
		public IMemoryStoreBase  // 0
	{
	public:
		static constexpr auto RTTI{ RTTI::IMemoryStore };
		static constexpr auto VTABLE{ VTABLE::IMemoryStore };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~IMemoryStore() = default;  // 00

		// add
		virtual void* AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) = 0;                                                 // 04
		virtual void  DeallocateAlignImpl(void*& a_block) = 0;                                                                              // 05
		virtual void* TryAllocateImpl([[maybe_unused]] std::size_t a_size, [[maybe_unused]] std::uint32_t a_alignment) { return nullptr; }  // 06
	};
	static_assert(sizeof(IMemoryStore) == 0x8);

	class __declspec(novtable) IMemoryHeap :
		public IMemoryStore  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::IMemoryHeap };
		//static constexpr auto VTABLE{ VTABLE::IMemoryHeap }; -- optimized out?

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~IMemoryHeap() = default;

		// override (IMemoryStore)
		bool  ContainsBlockImpl(const void* a_block) const override { return PointerInHeap(a_block); }                             // 03
		void* AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) override { return Allocate(a_size, a_alignment); }  // 04
		void  DeallocateAlignImpl(void*& a_block) override { Deallocate(a_block, 0); }                                             // 05

		// add
		virtual const char*   GetName() const = 0;                                                      // 07
		virtual void          Unk08() = 0;                                                              // 08 -- Sets value of ptr[rax] to 0 in all implementations?
		virtual void          Unk09() = 0;                                                              // 09 -- Same here
		virtual void*         Allocate(std::size_t a_size, std::uint32_t a_alignment) = 0;              // 0A
		virtual void          Deallocate(void* a_mem, std::uint32_t) = 0;                               // 0B
		virtual bool          PointerInHeap(const void* a_pointer) const = 0;                           // 0C
		virtual std::size_t   TotalSize(const void* a_pointer) const = 0;                               // 0D
		virtual void          GetHeapStats(HeapStats* a_stats, bool a_fullBlockInfo) = 0;               // 0E
		virtual bool          ShouldTrySmallBlockPools(std::size_t a_size, MEM_CONTEXT a_context) = 0;  // 0F
		virtual std::uint32_t GetPageSize() const = 0;                                                  // 10
	};
	static_assert(sizeof(IMemoryHeap) == 0x8);

	template <class store_type>
	class __declspec(novtable) TAllocatorAddressSpace :
		public store_type  // 00
	{
		// This is a templated class that overrides Unk08, Unk09, Allocate, and Deallocate.
		// The only classes that seem to be used with it are IMemoryHeap and BSFixedSizeBlockAllocator::BuddyAllocTag
		// Also seems to have member variables that are not used in the functions that are overridden.

		// TODO: implement an allocator traits class to test if store_type interface has these functions

		// override (store_type)
		virtual void  Unk08() override;                                                  // ??
		virtual void  Unk09() override;                                                  // ??
		virtual void* Allocate(std::size_t a_size, std::uint32_t a_alignment) override;  // ??
		virtual void  Deallocate(void* a_mem, std::uint32_t) override;                   // ??
	};

	class HeapAllocator :
		public TAllocatorAddressSpace<IMemoryHeap>  // 00
	{
	public:
		SF_RTTI_VTABLE(HeapAllocator);

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~HeapAllocator();  // 00
		// override (IMemoryStoreBase)
		std::size_t Size(void const* a_mem) const override;                 // 01
		void        GetMemoryStats(MemoryStats* a_stats) override;          // 02
		bool        ContainsBlockImpl(const void* a_block) const override;  // 03

		// override (IMemoryStore)
		void*         AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) override;                                  // 04
		void          DeallocateAlignImpl(void*& a_block) override;                                                               // 05
		virtual void* TryAllocateImpl([[maybe_unused]] std::size_t a_size, [[maybe_unused]] std::uint32_t a_alignment) override;  // 06

		// override (IMemoryHeap)
		const char*   GetName() const override;                                                      // 07
		bool          PointerInHeap(const void* a_pointer) const override;                           // 0C
		std::size_t   TotalSize(const void* a_pointer) const override;                               // 0D
		void          GetHeapStats(HeapStats* a_stats, bool a_fullBlockInfo) override;               // 0E
		bool          ShouldTrySmallBlockPools(std::size_t a_size, MEM_CONTEXT a_context) override;  // 0F
		std::uint32_t GetPageSize() const override;                                                  // 10

		// members
		char          name[128];  // 08
		void*         unk_88;     // 088
		std::uint64_t unk_90;     // 090
		std::uint64_t unk_98;     // 098
		std::uint64_t unk_a0;     // 0a0
		std::uint64_t unk_a8;     // 0a8
		std::uint64_t unk_b0;     // 0b0
		std::uint64_t unk_b8;     // 0b8
		std::uint64_t unk_c0;     // 0c0
		std::int32_t  unk_c8;     // 0c8
		std::int16_t  unk_cc;     // 0cc
		std::uint16_t gap_CE;     // 0CE
		std::uint64_t unk_d0;     // 0d0
		std::uint64_t unk_d8;     // 0d8
		std::uint64_t unk_e0;     // 0e0
		std::uint64_t unk_e8;     // 0e8
		std::uint64_t unk_f0;     // 0f0
		std::uint64_t unk_f8;     // 0f8
		std::uint64_t unk_100;    // 100
		std::uint64_t unk_108;    // 108
		std::uint64_t unk_110;    // 110
		std::uint64_t unk_118;    // 118
		std::uint64_t unk_120;    // 120
		std::uint64_t unk_128;    // 128
		std::uint64_t unk_130;    // 130
		std::uint64_t unk_138;    // 138
		std::uint64_t unk_140;    // 140
		std::uint64_t unk_148;    // 148
		std::uint64_t unk_150;    // 150
		std::uint64_t unk_158;    // 158
		std::uint64_t unk_160;    // 160
		std::uint64_t unk_168;    // 168
		std::uint64_t unk_170;    // 170
		std::uint64_t unk_178;    // 178
		std::uint64_t unk_180;    // 180
		std::uint64_t unk_188;    // 188
		std::uint64_t unk_190;    // 190
		std::uint64_t unk_198;    // 198
		std::uint64_t unk_1a0;    // 1a0
		std::uint64_t unk_1a8;    // 1a8
		std::uint64_t unk_1b0;    // 1b0
		std::uint64_t unk_1b8;    // 1b8
		std::uint64_t unk_1c0;    // 1c0
		std::uint64_t unk_1c8;    // 1c8
		std::uint64_t unk_1d0;    // 1d0
		std::uint64_t unk_1d8;    // 1d8
		std::uint64_t unk_1e0;    // 1e0
		std::uint64_t unk_1e8;    // 1e8
		std::uint64_t unk_1f0;    // 1f0
		std::uint64_t unk_1f8;    // 1f8
		std::uint64_t unk_200;    // 200
		std::uint64_t unk_208;    // 208
		std::uint64_t unk_210;    // 210
		std::uint64_t unk_218;    // 218
		std::uint64_t unk_220;    // 220
		std::uint64_t unk_228;    // 228
		std::uint64_t unk_230;    // 230
		std::uint64_t unk_238;    // 238
		std::uint64_t unk_240;    // 240
		std::uint64_t unk_248;    // 248
		std::uint64_t unk_250;    // 250
		std::uint64_t unk_258;    // 258
		std::uint64_t unk_260;    // 260
		std::uint64_t unk_268;    // 268
		std::uint64_t unk_270;    // 270
		std::uint64_t unk_278;    // 278
		std::uint64_t unk_280;    // 280
		std::uint64_t unk_288;    // 288
		std::uint64_t unk_290;    // 290
		std::uint64_t unk_298;    // 298
		std::uint64_t unk_2a0;    // 2a0
		std::uint64_t unk_2a8;    // 2a8
		std::uint64_t unk_2b0;    // 2b0
		std::uint64_t unk_2b8;    // 2b8
		std::uint64_t unk_2c0;    // 2c0
		std::uint64_t unk_2c8;    // 2c8
		std::uint64_t unk_2d0;    // 2d0
		std::uint64_t unk_2d8;    // 2d8
		std::uint64_t unk_2e0;    // 2e0
		std::uint64_t unk_2e8;    // 2e8
		std::uint64_t unk_2f0;    // 2f0
		std::uint64_t unk_2f8;    // 2f8
		std::uint64_t unk_300;    // 300
		std::uint64_t unk_308;    // 308
		std::uint64_t unk_310;    // 310
		std::uint64_t unk_318;    // 318
		std::uint64_t unk_320;    // 320
		std::uint64_t unk_328;    // 328
		std::uint64_t unk_330;    // 330
		std::uint64_t unk_338;    // 338
		std::uint64_t unk_340;    // 340
		std::uint64_t unk_348;    // 348
		std::uint64_t unk_350;    // 350
		std::uint64_t unk_358;    // 358
		std::uint64_t unk_360;    // 360
		std::uint64_t unk_368;    // 368
		std::uint64_t unk_370;    // 370
		std::uint64_t unk_378;    // 378
		std::uint64_t unk_380;    // 380
		std::uint64_t unk_388;    // 388
		std::uint64_t unk_390;    // 390
		std::uint64_t unk_398;    // 398
		std::uint64_t unk_3a0;    // 3a0
		std::uint64_t unk_3a8;    // 3a8
		std::uint64_t unk_3b0;    // 3b0
		std::uint64_t unk_3b8;    // 3b8
		std::uint64_t unk_3c0;    // 3c0
		std::uint64_t unk_3c8;    // 3c8
		std::uint64_t unk_3d0;    // 3d0
		std::uint64_t unk_3d8;    // 3d8
		std::uint64_t unk_3e0;    // 3e0
		std::uint64_t unk_3e8;    // 3e8
		std::uint64_t unk_3f0;    // 3f0
		std::uint64_t unk_3f8;    // 3f8
		std::uint64_t unk_400;    // 400
		bool          unk_408;    // 408
		bool          unk_409;    // 409
		bool          unk_40a;    // 40a
	};
	static_assert(sizeof(HeapAllocator) == 0x410);

	class ScrapHeap :
		public HeapAllocator  // 00
	{
	public:
		SF_RTTI_VTABLE(ScrapHeap);

		~ScrapHeap();  // 00

		void* Allocate(std::size_t a_size, std::uint32_t a_alignment) override;  // 0A
		void  Deallocate(void* a_mem, std::uint32_t) override;                   // 0B

		// members

		std::uint64_t  unk_410;      // 410
		std::byte      unk_418;      // 418
		std::byte      gap_419[31];  // 419
		std::uint64_t  unk_438;      // 438
		std::byte      gap_440[32];  // 440
		std::uint64_t  unk_460;      // 460
		std::uint64_t  unk_468;      // 468
		std::uint64_t  unk_470;      // 470
		std::uint64_t  unk_478;      // 478
		std::uint64_t  unk_480;      // 480
		std::uint64_t* unk_488;      // 488
		char           unk_490;      // 490
		std::byte      gap_491[7];   // 491
		std::uint64_t* unk_498;      // 498
		std::uint32_t  unk_4a0;      // 4a0
		std::byte      gap_4A4[4];   // 4A4
		char           unk_4a8;      // 4a8
		std::byte      gap_4A9[7];   // 4A9
		std::uint64_t  unk_4b0;      // 4b0
		std::uint32_t  unk_4b8;      // 4b8
	};
}

#define SF_HEAP_REDEFINE_NEW_HELPER(...)                                                             \
	[[nodiscard]] void* operator new(std::size_t a_count, std::align_val_t a_alignment)              \
	{                                                                                                \
		const auto mem = RE::malloc(a_count, static_cast<std::size_t>(a_alignment));                 \
		if (mem)                                                                                     \
			return mem;                                                                              \
                                                                                                     \
		SFSE::stl::report_and_fail("out of memory");                                                 \
	}                                                                                                \
                                                                                                     \
	[[nodiscard]] void* operator new[](std::size_t a_count, std::align_val_t a_alignment)            \
	{                                                                                                \
		const auto mem = RE::malloc(a_count, static_cast<std::size_t>(a_alignment));                 \
		if (mem)                                                                                     \
			return mem;                                                                              \
                                                                                                     \
		SFSE::stl::report_and_fail("out of memory");                                                 \
	}                                                                                                \
                                                                                                     \
	[[nodiscard]] void* operator new(std::size_t, void* a_ptr) { return a_ptr; }                     \
	[[nodiscard]] void* operator new[](std::size_t, void* a_ptr) { return a_ptr; }                   \
	[[nodiscard]] void* operator new(std::size_t, std::align_val_t, void* a_ptr) { return a_ptr; }   \
	[[nodiscard]] void* operator new[](std::size_t, std::align_val_t, void* a_ptr) { return a_ptr; } \
                                                                                                     \
	void operator delete(void*, void*) { return; }                                                   \
	void operator delete[](void*, void*) { return; }                                                 \
                                                                                                     \
	void operator delete(void* a_ptr, std::align_val_t) { RE::free(a_ptr, true); }                   \
	void operator delete[](void* a_ptr, std::align_val_t) { RE::free(a_ptr, true); }                 \
	void operator delete(void* a_ptr, std::size_t, std::align_val_t) { RE::free(a_ptr, true); }      \
	void operator delete[](void* a_ptr, std::size_t, std::align_val_t) { RE::free(a_ptr, true); }

#define SF_HEAP_REDEFINE_NEW(...)                                         \
	[[nodiscard]] void* operator new(std::size_t a_count)                 \
	{                                                                     \
		const auto mem = RE::malloc(a_count);                             \
		if (mem)                                                          \
			return mem;                                                   \
                                                                          \
		SFSE::stl::report_and_fail("out of memory");                      \
	}                                                                     \
                                                                          \
	[[nodiscard]] void* operator new[](std::size_t a_count)               \
	{                                                                     \
		const auto mem = RE::malloc(a_count);                             \
		if (mem)                                                          \
			return mem;                                                   \
                                                                          \
		SFSE::stl::report_and_fail("out of memory");                      \
	}                                                                     \
                                                                          \
	void operator delete(void* a_ptr) { RE::free(a_ptr); }                \
	void operator delete[](void* a_ptr) { RE::free(a_ptr); }              \
	void operator delete(void* a_ptr, std::size_t) { RE::free(a_ptr); }   \
	void operator delete[](void* a_ptr, std::size_t) { RE::free(a_ptr); } \
                                                                          \
	SF_HEAP_REDEFINE_NEW_HELPER(__VA_ARGS__)

#define SF_HEAP_REDEFINE_NEW_ALIGNED(...)                                       \
	[[nodiscard]] void* operator new(std::size_t a_count)                       \
	{                                                                           \
		const auto mem = RE::malloc(a_count, alignof(__VA_ARGS__));             \
		if (mem)                                                                \
			return mem;                                                         \
                                                                                \
		SFSE::stl::report_and_fail("out of memory");                            \
	}                                                                           \
                                                                                \
	[[nodiscard]] void* operator new[](std::size_t a_count)                     \
	{                                                                           \
		const auto mem = RE::malloc(a_count, alignof(__VA_ARGS__));             \
		if (mem)                                                                \
			return mem;                                                         \
                                                                                \
		SFSE::stl::report_and_fail("out of memory");                            \
	}                                                                           \
                                                                                \
	void operator delete(void* a_ptr) { RE::free(a_ptr, true); }                \
	void operator delete[](void* a_ptr) { RE::free(a_ptr, true); }              \
	void operator delete(void* a_ptr, std::size_t) { RE::free(a_ptr, true); }   \
	void operator delete[](void* a_ptr, std::size_t) { RE::free(a_ptr, true); } \
                                                                                \
	SF_HEAP_REDEFINE_NEW_HELPER(__VA_ARGS__)
