#pragma once

namespace RE
{
	template <class T>
	struct BSTFreeListElem
	{
	public:
		// members
		std::byte           rawElem[sizeof(T)];  // 00
		BSTFreeListElem<T>* next;                // ??
	};

	template <class T>
	class __declspec(novtable) BSTFreeList
	{
	public:
		virtual ~BSTFreeList();  // 00

		// members
		std::uint32_t       lock;  // 08
		BSTFreeListElem<T>* free;  // 10
	};
	//static_assert(sizeof(BSTFreeList<void*>) == 0x18);

	template <class T, std::uint32_t N>
	class __declspec(novtable) BSTStaticFreeList :
		public BSTFreeList<T>  // 00
	{
	public:
		// members
		BSTFreeListElem<T> elems[N];  // ??
	};
}
