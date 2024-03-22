#pragma once
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSTScatterTable.h"
#include "RE/I/IMenu.h"

namespace RE
{
	class IMenu;

	namespace Scaleform
	{
		template <class T>
		class Ptr;
	}

	struct BIUIMenuVisiblePausedBeginEvent;
	struct BIUIMenuVisiblePausedEndEvent;
	struct BSCursorRotationChange;
	struct BSCursorTypeChange;
	struct MenuPauseChangeEvent;
	struct MenuPauseCounterChangeEvent;
	struct TutorialEvent;
	struct MenuOpenCloseEvent;
	struct MenuModeChangeEvent;

	class UI :
		//public BSTSingletonSDM<UI>,
		public BSInputEventReceiver,                             // 000
		public BSTEventSource<MenuOpenCloseEvent>,               // 010
		public BSTEventSource<MenuModeChangeEvent>,              // 038
		public BSTEventSource<MenuPauseChangeEvent>,             // 060
		public BSTEventSource<MenuPauseCounterChangeEvent>,      // 088
		public BSTEventSource<TutorialEvent>,                    // 0B0
		public BSTEventSource<BSCursorTypeChange>,               // 0D8
		public BSTEventSource<BSCursorRotationChange>,           // 100
		public BSTEventSource<BIUIMenuVisiblePausedBeginEvent>,  // 128
		public BSTEventSource<BIUIMenuVisiblePausedEndEvent>     // 150
	{
	public:
		SF_RTTI_VTABLE(UI);

		struct UIMenuEntry
		{
			using Create_t = Scaleform::Ptr<IMenu>*(Scaleform::Ptr<IMenu>*);

			Scaleform::Ptr<IMenu> menu;
			Create_t*             initFunc;
			void*                 unk18 = nullptr;
			uint64_t			  unk20 = 1;
			uint64_t			  unk28 = 0;
		};

		template <class T>
		[[nodiscard]] auto GetEventSource()
		{
			return static_cast<BSTEventSource<T>*>(this);
		}

		inline static UI* GetSingleton()
		{
			static REL::Relocation<UI**> singleton{ ID::UI::singleton };
			return *singleton;
		}

		bool IsMenuOpen(const BSFixedString& a_name)
		{
			using func_t = decltype(&UI::IsMenuOpen);
			REL::Relocation<func_t> func{ ID::UI::IsMenuOpen };
			return func(this, a_name);
		}

		bool IsMenuRegistered(const BSFixedString& a_name)
		{
			return menuMap.contains(a_name);
		}

		template <class T>
			requires(std::derived_from<T, IMenu>)
		bool RegisterMenu(const BSFixedString& a_name)
		{
			if (menuMap.contains(a_name))
				return false;

			auto& entry = menuMap[a_name];
			entry.initFunc = [](Scaleform::Ptr<IMenu>* menu) {
				auto createdMenu = new T();
				REL::Relocation<Scaleform::Ptr<IMenu>*(Scaleform::Ptr<IMenu>*, T*)> CopyRef(REL::ID(80375));
				CopyRef(menu, createdMenu);
				return menu;
			};

			return true;
		}

		template <class T>
		void RegisterSink(BSTEventSink<T>* a_sink)
		{
			GetEventSource<T>()->RegisterSink(a_sink);
		}

		template <class T>
		void UnregisterSink(BSTEventSink<T>* a_sink)
		{
			GetEventSource<T>()->UnregisterSink(a_sink);
		}

		std::uint8_t                           pad178[0x278];  // 178
		BSTArray<Scaleform::Ptr<IMenu>>        menuStack;      // 3F0
		std::uint8_t                           pad02[0x18];
		uint64_t                               unk418;
		uint64_t                               unk420;
		uint64_t                               unk428;
		BSTHashMap<BSFixedString, UIMenuEntry> menuMap;  //430
		void*                                  unk460_4F8[18];
		uint16_t                               unk4F8;
		bool                                   menusVisible;  // 4FA
	};
	static_assert(offsetof(UI, menuStack) == 0x3F0);
	static_assert(offsetof(UI, menuMap) == 0x430);
	static_assert(offsetof(UI, menusVisible) == 0x4FA);
}
