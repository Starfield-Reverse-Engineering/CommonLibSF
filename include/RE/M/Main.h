#pragma once

namespace RE
{
	class NiAVObject;
	class NiCamera;

	class Main
	{
	public:

		[[nodiscard]] static Main* GetSingleton()
		{
			REL::Relocation<Main**> singleton{ REL::ID(881027) };
			return *singleton;
		}

		struct SceneGraphRoot
		{
			std::byte   unk[120];
			NiAVObject* worldCameraRoot;  //NiNode
			NiCamera*   worldCamera;
		};
		// static_assert(offsetof(SceneGraphRoot, SceneGraphRoot::worldCamera) == 0x80); // FIXME: clang-cl chokes on this assertion

		static SceneGraphRoot* WorldRoot()
		{
			static REL::Relocation<SceneGraphRoot**> singleton{ REL::ID(887308) };
			return *singleton;
		}

		static NiCamera* WorldCamera()
		{
			return WorldRoot()->worldCamera;
		}
	};
}
