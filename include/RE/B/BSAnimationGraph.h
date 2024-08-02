#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSLock.h"

namespace RE
{
	class BSAnimationGraphEvent;
	struct BSMovementDataChangedEvent;
	struct BSSubGraphActivationUpdate;
	class BSTransformDeltaEvent;
	class BSAnimationUpdateData;

	class BSAnimationGraph :
		public BSIntrusiveRefCounted,
		public BSTEventSource<BSAnimationGraphEvent>,
		public BSTEventSource<BSMovementDataChangedEvent>,
		public BSTEventSource<BSSubGraphActivationUpdate>,
		public BSTEventSource<BSTransformDeltaEvent>
	{
	public:
		virtual ~BSAnimationGraph();

		virtual void Unk_01();                                     // 01
		virtual void Unk_02();                                     // 02
		virtual void Unk_03();                                     // 03
		virtual void Update(BSAnimationUpdateData& a_updateData);  // 04
		virtual void Unk_05();                                     // 05
		virtual void Unk_06();                                     // 06
		virtual void Unk_07();                                     // 07
		virtual void Unk_08();                                     // 08
		virtual void Unk_09();                                     // 09
		virtual void Unk_0A();                                     // 0A
		virtual void Unk_0B();                                     // 0B
		virtual void Unk_0C();                                     // 0C
		virtual void Unk_0D();                                     // 0D
		virtual void Unk_0E();                                     // 0E
		virtual void Unk_0F();                                     // 0F
		virtual void Unk_10();                                     // 10
		virtual void Unk_11();                                     // 11
		virtual void Unk_12();                                     // 12
		virtual void Unk_13();                                     // 13
		virtual void Unk_14();                                     // 14
		virtual void Unk_15();                                     // 15
		virtual void Unk_16();                                     // 16
		virtual void Unk_17();                                     // 17
		virtual void Unk_18();                                     // 18
		virtual void Unk_19();                                     // 19
		virtual void Unk_1A();                                     // 1A
		virtual void Unk_1B();                                     // 1B
		virtual void Unk_1C();                                     // 1C
		virtual void Unk_1D();                                     // 1D
		virtual void Unk_1E();                                     // 1E
		virtual void Unk_1F();                                     // 1F
		virtual void Unk_20();                                     // 20
		virtual void Unk_21();                                     // 21
		virtual void Unk_22();                                     // 22
		virtual void Unk_23();                                     // 23
		virtual void Unk_24();                                     // 24
		virtual void Unk_25();                                     // 25
		virtual void Unk_26();                                     // 26
		virtual void Unk_27();                                     // 27
		virtual void Unk_28();                                     // 28
		virtual void Unk_29();                                     // 29
		virtual void Unk_2A();                                     // 2A
		virtual void Unk_2B();                                     // 2B
		virtual void Unk_2C();                                     // 2C
	};

	class AnimationManager : public BSAnimationGraph
	{
	public:
		virtual ~AnimationManager();

		std::byte unkB0[0x3C0 - 0xB0];  // B0
	};
	// FIXME: compiler doesn't recognize vtable pointer as part of the size, but intellisense does.
	static_assert(sizeof(AnimationManager) == 0x3C0 - 0x8);

	class BSAnimationGraphManager :
		public BSTEventSink<BSAnimationGraphEvent>,
		public BSIntrusiveRefCounted
	{
	public:
		// TODO: Properly implement BSTSmallArray
		template <typename T, std::uint32_t N>
		class SmallArray
		{
		public:
			inline std::uint32_t size() { return _size; }
			inline void*         data() { return _local ? _stack : _heap; }

			inline T& operator[](std::uint32_t a_idx)
			{
				return static_cast<T*>(data())[a_idx];
			}

			std::uint32_t _size;
			std::uint32_t _unk;
			std::uint32_t _capacity: 31;
			std::uint32_t _local: 1;
			union
			{
				void*     _heap;
				std::byte _stack[sizeof(T) * N];
			};
		};

		virtual ~BSAnimationGraphManager();

		std::uint32_t                                    unk0C;                 // 0C
		std::uint32_t                                    unk10;                 // 10
		std::uint32_t                                    unk14;                 // 14
		std::uint32_t                                    unk18;                 // 18
		std::uint32_t                                    unk1C;                 // 1C
		std::uint32_t                                    unk20;                 // 20
		std::uint32_t                                    unk24;                 // 24
		std::uint32_t                                    unk28;                 // 28
		std::uint32_t                                    unk2C;                 // 2C
		SmallArray<BSTSmartPointer<BSAnimationGraph>, 1> graphs;                // 30
		std::uint32_t                                    unk50[0x8];            // 50
		BSSpinLock                                       updateLock;            // 68
		BSSpinLock                                       dependentManagerLock;  // 70
		std::uint32_t                                    activeGraph;           // 78
		std::uint32_t                                    generateDepth;         // 7C
	};
	static_assert(sizeof(BSAnimationGraphManager) == 0x80);
}
