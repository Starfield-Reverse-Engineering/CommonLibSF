#pragma once
#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
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
	struct MenuModeChangeEvent;
	struct MenuOpenCloseEvent;
	struct MenuPauseChangeEvent;
	struct MenuPauseCounterChangeEvent;
	struct TutorialEvent;

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
			uint64_t              unk20 = 1;
			uint64_t              unk28 = 0;
		};

		template <class T>
		[[nodiscard]] auto GetEventSource()
		{
			return static_cast<BSTEventSource<T>*>(this);
		}

		inline static UI* GetSingleton()
		{
			static REL::Relocation<UI**> singleton{ ID::UI::Singleton };
			return *singleton;
		}

		Scaleform::Ptr<IMenu> GetMenu(const BSFixedString& a_menuName) const
		{
			auto it = menuMap.find(a_menuName);
			return it != menuMap.end() ? it->value.menu : nullptr;
		}

		Scaleform::Ptr<Scaleform::GFx::Movie> GetMenuMovie(const BSFixedString& a_menuName) const
		{
			auto menu = GetMenu(a_menuName);
			return menu ? menu->uiMovie : nullptr;
		}

		bool IsMenuOpen(const BSFixedString& a_name) const
		{
			using func_t = decltype(&UI::IsMenuOpen);
			static REL::Relocation<func_t> func{ ID::UI::IsMenuOpen };
			return func(this, a_name);
		}

		bool IsMenuRegistered(const BSFixedString& a_name) const
		{
			return menuMap.contains(a_name);
		}

		bool IsMenusVisible() const
		{
			return menusVisible;
		}

		template <class T>
			requires(std::derived_from<T, IMenu>)
		bool RegisterMenu(const BSFixedString& a_name)
		{
			if (menuMap.contains(a_name))
				return false;

			menuMap[a_name].initFunc = [](Scaleform::Ptr<IMenu>* a_menu) {
				using func_t = Scaleform::Ptr<IMenu>*(Scaleform::Ptr<IMenu>*, T*);
				static REL::Relocation<func_t> copyRef{ REL::ID(80375) };
				copyRef(a_menu, new T());
				return a_menu;
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
		std::uint8_t                           pad02[0x18];    // 400
		uint64_t                               unk418;         // 418
		uint64_t                               unk420;         // 420
		uint64_t                               unk428;         // 428
		BSTHashMap<BSFixedString, UIMenuEntry> menuMap;        // 430
		void*                                  unk468[18];     // 468
		uint16_t                               unk4F8;         // 4F8
		bool                                   menusVisible;   // 4FA
	};
	static_assert(offsetof(UI, menuStack) == 0x3F0);
	static_assert(offsetof(UI, menuMap) == 0x430);
	static_assert(offsetof(UI, menusVisible) == 0x4FA);
}
