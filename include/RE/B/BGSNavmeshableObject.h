#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NavMesh;

	class BGSNavmeshableObject
	{
	public:
		SF_RTTI(BGSNavmeshableObject);

		// members
		NiPointer<NavMesh> embeddableNavmesh;  // 00 - BSTSmartPointer in FO4
	};
	static_assert(sizeof(BGSNavmeshableObject) == 0x8);
}
