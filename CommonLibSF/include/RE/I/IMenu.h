#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSInputEventUser.h"
#include "RE/B/BSTEvent.h"
#include "RE/S/SWFToCodeFunctionHandler.h"
#include "RE/S/ScaleformGFxMovie.h"
#include "RE/S/ScaleformGFxValue.h"
#include "RE/S/ScaleformMemoryHeap.h"
#include "RE/U/UIMessageQueue.h"

namespace RE
{
	struct UpdateSceneRectEvent;

	class IMenu :
		public SWFToCodeFunctionHandler,           // 00
		public BSInputEventUser,                   // 10
		public BSTEventSink<UpdateSceneRectEvent>  // 50
	{
	public:
		SF_RTTI_VTABLE(IMenu);

		enum Flag : uint32_t
		{
			Flag0 = 1 << 0,
			Flag1 = 1 << 1,
			ShowCursor = 1 << 3,
			Flag4 = 1 << 4,
			Flag6 = 1 << 6,
			Flag8 = 1 << 8,
			Flag9 = 1 << 9,
			Flag10 = 1 << 10,
			Flag18 = 1 << 18,
			Flag25 = 1 << 25,
			Flag27 = 1 << 27,
		};

		virtual ~IMenu() // 00
		{
			using func_t = void(*)(IMenu*);
			REL::Relocation<func_t> func(REL::ID(187216));
			func(this);
		}

		void* operator new(std::size_t count) { return Scaleform::MemoryHeapPT::GetSingleton()->Allocate(count, 0); }
		void* operator new(std::size_t count, std::align_val_t) { return Scaleform::MemoryHeapPT::GetSingleton()->Allocate(count, 0); }

		void operator delete(void* a_ptr) { Scaleform::MemoryHeapPT::GetSingleton()->Free(a_ptr); }
		void operator delete(void* a_ptr, std::align_val_t) { Scaleform::MemoryHeapPT::GetSingleton()->Free(a_ptr); }
		void operator delete(void* a_ptr, std::size_t) { Scaleform::MemoryHeapPT::GetSingleton()->Free(a_ptr); }
		void operator delete(void* a_ptr, std::size_t, std::align_val_t) { Scaleform::MemoryHeapPT::GetSingleton()->Free(a_ptr); }

		// override
		virtual bool ShouldHandleEvent(const InputEvent* a_event) override
		{
			using func_t = bool (*)(BSInputEventUser*, const InputEvent*);
			REL::Relocation<func_t> func(REL::ID(187262));
			return func(this, a_event);
		}

		virtual void HandleEvent(const ThumbstickEvent* a_event) override
		{
			using func_t = void (*)(BSInputEventUser*, const ThumbstickEvent*);
			REL::Relocation<func_t> func(REL::ID(187235));
			return func(this, a_event);
		}

		virtual void HandleEvent(const ButtonEvent* a_event) override
		{
			using func_t = void (*)(BSInputEventUser*, const ButtonEvent*);
			REL::Relocation<func_t> func(REL::ID(187234));
			return func(this, a_event);
		}

		// add
		virtual const char* GetName() const = 0;                                // 03
		virtual const char* GetRootPath() const = 0;                            // 04
		virtual uint64_t    GetUnk05() = 0;                                     // 05

		virtual bool LoadMovie(bool a_addEventDispatcher, bool a_arg2)			// 06
		{
			using func_t = decltype(&IMenu::LoadMovie);
			REL::Relocation<func_t> func(REL::ID(187240));
			return func(this, a_addEventDispatcher, a_arg2);
		} 

		virtual void Unk07() {}													// 07

		virtual UI_MESSAGE_RESULT ProcessMessage(UIMessageData& a_message)		// 08
		{
			using func_t = decltype(&IMenu::ProcessMessage);
			REL::Relocation<func_t> func(REL::ID(187247));
			return func(this, a_message);
		}
		
		virtual bool Unk09()													// 09
		{
			using func_t = decltype(&IMenu::Unk09);
			REL::Relocation<func_t> func(REL::ID(80440));
			return func(this); 
		}

		virtual bool Unk0A()													// 0A
		{
			using func_t = decltype(&IMenu::Unk0A);
			REL::Relocation<func_t> func(REL::ID(187238));
			return func(this);
		}

		virtual void        Unk_0B(void) {}                                     // 0B
		virtual void        Unk_0C(void) {}                                     // 0C
		virtual void        Unk_0D(void) {}                                     // 0D

		virtual bool Unk0E(void* a, bool b)										// 0E
		{
			using func_t = decltype(&IMenu::Unk0E);
			REL::Relocation<func_t> func(REL::ID(187242));
			return func(this, a, b);
		}

		virtual void Unk0F() {};												// 0F

		virtual uint64_t Unk10()												// 10
		{												
			using func_t = decltype(&IMenu::Unk10);
			REL::Relocation<uint64_t(IMenu*)> func(REL::ID(187241));
			return func(this);
		};

		virtual uint64_t Unk11()												// 11
		{ 
			using func_t = decltype(&IMenu::Unk11);
			REL::Relocation<func_t> func(REL::ID(187243));
			return func(this);
		};

		virtual uint64_t Unk12()												// 12
		{
			using func_t = decltype(&IMenu::Unk12);
			REL::Relocation<func_t> func(REL::ID(80451));
			return func(this); 
		};

		virtual BSFixedString* Unk13()											// 13
		{
			using func_t = decltype(&IMenu::Unk13);
			REL::Relocation<func_t> func(REL::ID(76183));
			return func(this);
		};

		virtual bool Unk14()													// 14
		{ 
			return true; 
		};

		virtual bool Unk15(void* a)												// 15
		{
			using func_t = decltype(&IMenu::Unk15);
			REL::Relocation<func_t> func(REL::ID(187225));
			return func(this, a); 
		};

		virtual bool Unk16()													// 16
		{ 
			return false;
		
		};

		virtual bool ProcessInputUserEvent()									// 17
		{
			return false;
		};

		virtual uint64_t Unk18(void* a, uint64_t b)								// 18
		{
			using func_t = decltype(&IMenu::Unk18);
			REL::Relocation<func_t> func(REL::ID(1275268));
			return func(this, a, b);
		}

		virtual uint64_t Unk19(void* a, int b, int c) {							// 19
			using func_t = decltype(&IMenu::Unk19);
			REL::Relocation<func_t> func(REL::ID(187245));
			return func(this, a, b, c); 
		}

		virtual float Unk1A()													// 1A
		{ 
			using func_t = decltype(&IMenu::Unk1A);
			REL::Relocation<func_t> func(REL::ID(187232));
			return func(this); 
		};

		void SetFlags(uint32_t _flags)
		{
			flags |= _flags;
			flagsUpdated = true;
		}

		void RemoveFlags(uint32_t _flags)
		{
			flags &= ~_flags;
			flagsUpdated = true;
		}

		Scaleform::GFx::Value                 menuObj;		 // 058
		Scaleform::Ptr<Scaleform::GFx::Movie> uiMovie;		 // 088
		std::uint64_t                         unk090;		 // 090
		std::uint64_t                         unk098;		 // 098
		std::uint64_t                         unk0A0;		 // 0A0
		std::uint32_t                         unk0A8;		 // 0A8
		std::uint32_t                         unk0AC;		 // 0AC
		BSFixedString                         menuName;		 // 0B0
		BSFixedString                         unk0B8;		 // 0B8
		std::uint32_t                         flags;		 // 0C0
		std::uint32_t						  unk0C4;		 // 0C4
		std::uint32_t                         unk0C8;        // 0C8
		std::uint32_t                         unk0CC;        // 0CC
		std::uint16_t                         unk0D0;        // 0D0
		bool                                  flagsUpdated;  // 0D2
		std::uint8_t                          unk0D3;        // 0D3
		std::uint32_t                         unk0D4;		 // 0D4
		std::uint64_t                         unk0D8;		 // 0D8
		std::uint64_t                         unk0E0;		 // 0E0
		std::uint64_t                         unk0E8;		 // 0E8
		std::uint64_t                         unk0F0;		 // 0F0
		std::uint64_t                         unk0F8;		 // 0F8
		std::uint64_t                         unk100;		 // 100
		std::uint32_t                         unk108;		 // 108
		std::uint32_t                         unk10C;		 // 10C
		std::uint64_t                         unk110;		 // 110
		std::uint64_t                         unk118;		 // 118
		std::uint64_t                         unk120;		 // 120
		std::uint64_t                         unk128;		 // 128
	};
	static_assert(offsetof(IMenu, uiMovie) == 0x088);
	static_assert(offsetof(IMenu, menuName) == 0x0B0);
}
