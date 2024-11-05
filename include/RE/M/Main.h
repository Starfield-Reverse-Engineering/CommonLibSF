#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/S/SceneGraph.h"

namespace RE
{
	struct PositionPlayerEvent;

	class Main :
		public BSTEventSink<PositionPlayerEvent>
	{
	public:
		SF_RTTI_VTABLE(Main);

		virtual ~Main();  // 00

		// override
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent& a_event, BSTEventSource<PositionPlayerEvent>* a_source) override;  // 01

		[[nodiscard]] static Main* GetSingleton()
		{
			static REL::Relocation<Main**> singleton{ ID::Main::Singleton };
			return *singleton;
		}

		[[nodiscard]] static SceneGraph* GetWorldRoot()
		{
			static REL::Relocation<SceneGraph**> ptr{ ID::Main::WorldRoot };
			return *ptr;
		}

		[[nodiscard]] static NiPointer<NiCamera> GetWorldRootCamera()
		{
			return GetWorldRoot()->camera;
		}

		// members
		std::byte pad008[0x020];     // 008
		bool      quitGame;          // 028
		std::byte pad029[0x005];     // 029
		bool      resetGame;         // 02E
		std::byte pad02F[0x419];     // 02F
		bool      isGameMenuPaused;  // 448
	};
	static_assert(offsetof(Main, quitGame) == 0x028);
	static_assert(offsetof(Main, resetGame) == 0x02E);
	static_assert(offsetof(Main, isGameMenuPaused) == 0x448);
}
