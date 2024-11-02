#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class NiAVObject;
	class NiCamera;

	struct PositionPlayerEvent;

	class Main :
		public BSTEventSink<PositionPlayerEvent>
	{
	public:
		SF_RTTI_VTABLE(Main);

		struct SceneGraphRoot
		{
			// members
			std::byte   pad00[0x78];      // 00
			NiAVObject* worldCameraRoot;  // 78 - NiNode
			NiCamera*   worldCamera;      // 80
		};
		// static_assert(offsetof(SceneGraphRoot, SceneGraphRoot::worldCamera) == 0x80); // FIXME: clang-cl chokes on this assertion

		virtual ~Main();  // 00

		// override
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent& a_event, BSTEventSource<PositionPlayerEvent>* a_source) override;  // 01

		[[nodiscard]] static Main* GetSingleton()
		{
			static REL::Relocation<Main**> singleton{ ID::Main::Singleton };
			return *singleton;
		}

		[[nodiscard]] static SceneGraphRoot* GetWorldRoot()
		{
			static REL::Relocation<SceneGraphRoot**> worldRoot{ ID::Main::WorldRoot };
			return *worldRoot;
		}

		[[nodiscard]] static NiCamera* GetWorldRootCamera()
		{
			return GetWorldRoot()->worldCamera;
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
