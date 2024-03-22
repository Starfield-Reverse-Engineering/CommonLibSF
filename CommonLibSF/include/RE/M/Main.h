#pragma once

namespace RE
{
	class NiAVObject;
	class NiCamera;

	class Main
	{
	public:
		struct SceneGraphRoot
		{
			std::byte unk[120];
			NiAVObject* worldCameraRoot; //NiNode
			NiCamera* worldCamera;
		};
		static_assert(offsetof(SceneGraphRoot, SceneGraphRoot::worldCamera) == 0x80);

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
