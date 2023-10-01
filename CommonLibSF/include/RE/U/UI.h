#pragma once

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

		template <class T>
		[[nodiscard]] auto GetEventSource()
		{
			return static_cast<BSTEventSource<T>*>(this);
		}

		inline static UI* GetSingleton()
		{
			static REL::Relocation<UI**> singleton{ REL::ID(878339) };
			return *singleton;
		}

		bool IsMenuOpen(const BSFixedString& a_name)
		{
			using func_t = decltype(&UI::IsMenuOpen);
			REL::Relocation<func_t> func{ REL::ID(187049) };
			return func(this, a_name);
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

		std::uint8_t                    pad178[0x278];  // 178
		BSTArray<Scaleform::Ptr<IMenu>> menuStack;      // 3F0
	};
	static_assert(offsetof(UI, menuStack) == 0x3F0);
}
