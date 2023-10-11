#pragma once

namespace RE
{
	class MemoryManager
	{
	public:
		[[nodiscard]] static MemoryManager* GetSingleton()
		{
			using func_t = decltype(&MemoryManager::GetSingleton);
			const REL::Relocation<func_t> func{ REL::ID(33961) };
			return func();
		}

		[[nodiscard]] void* Allocate(std::size_t a_size, std::uint32_t a_alignment, bool a_alignmentRequired)
		{
			using func_t = decltype(&MemoryManager::Allocate);
			const REL::Relocation<func_t> func{ REL::ID(33962) };
			return func(this, a_size, a_alignment, a_alignmentRequired);
		}

		void Free(void* a_ptr, bool a_alignmentRequired)
		{
			using func_t = decltype(&MemoryManager::Free);
			const REL::Relocation<func_t> func{ REL::ID(34032) };
			return func(this, a_ptr, a_alignmentRequired);
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
