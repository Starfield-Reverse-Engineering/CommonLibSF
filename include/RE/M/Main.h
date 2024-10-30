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
		std::byte pad008[0x440];     // 008
		bool      isGameMenuPaused;  // 448
	};
	static_assert(offsetof(Main, isGameMenuPaused) == 0x448);
}
