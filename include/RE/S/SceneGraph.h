#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiAVObject;
	class NiCamera;

	class SceneGraph
	{
	public:
		// members
		std::byte             pad00[0x78];  // 00
		NiPointer<NiAVObject> cameraRoot;   // 78 - NiNode
		NiPointer<NiCamera>   camera;       // 80
	};
	static_assert(offsetof(SceneGraph, camera) == 0x80);
}
