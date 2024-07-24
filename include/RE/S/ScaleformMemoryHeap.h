#pragma once

namespace RE::Scaleform
{
	class MemoryHeap
	{
	public:
		virtual ~MemoryHeap();
		virtual void  Unk1();
		virtual void  Unk2();
		virtual void  Unk3();
		virtual void  Unk4();
		virtual void  Unk5();
		virtual void  Unk6();
		virtual void  Unk7();
		virtual void  Unk8();
		virtual void  Unk9();
		virtual void* Allocate(uint64_t size, void* unk);
		virtual void  Unk11();
		virtual void  Free(void*);
		virtual void  Unk13();
		virtual void  Unk14();
		virtual void  Unk15();
		virtual void  Unk16();
		virtual void  Unk17();
		virtual void  Unk18();
		virtual void  Unk19();
		virtual void  Unk20();
		virtual void  Unk21();
		virtual void  Unk22();
		virtual void  Unk23();
		virtual void  Unk24();
		virtual void  Unk25();
		virtual void  Unk26();
		virtual void  Unk27();
		virtual void  Unk28();
		virtual void  Unk29();
		virtual void  Unk30();
		virtual void  Unk31();
		virtual void  Unk32();
		virtual void  Unk33();
		virtual void  Unk34();
		virtual void  Unk35();
		virtual void  Unk36();
		virtual void  Unk37();
		virtual void  Unk38();
		virtual void  Unk39();
		virtual void  Unk40();
		virtual void  Unk41();
		virtual void  Unk42();
		virtual void  Unk43();
	};

	class MemoryHeapPT : public MemoryHeap
	{
	public:
		static MemoryHeapPT* GetSingleton()
		{
			REL::Relocation<MemoryHeapPT**> memoryHeapPT(REL::ID(820297));
			return *memoryHeapPT;
		}
	};
}
