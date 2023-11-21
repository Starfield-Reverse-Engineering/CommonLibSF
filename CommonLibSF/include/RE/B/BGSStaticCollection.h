#pragma once

#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	class Navmesh;

	class BGSStaticCollection :
		public TESBoundObject,       // 000
		public BGSModelMaterialSwap  // 118
	{
	public:
		SF_RTTI_VTABLE(BGSStaticCollection);
		SF_FORMTYPE(SCOL);

		~BGSStaticCollection() override;  // 00

		// members
		NiPointer<Navmesh> navmesh;  // 140
		std::uint64_t      unk148;   // 148 - BSTHashMap*
	};
	static_assert(sizeof(BGSStaticCollection) == 0x150);
}
