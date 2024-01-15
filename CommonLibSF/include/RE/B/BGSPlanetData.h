#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	namespace BGSSurface
	{
		class Tree;
	}

	namespace BGSPlanet
	{
		class PlanetData : public TESForm
		{
		public:
			SF_RTTI_VTABLE(BGSPlanet__PlanetData);
			SF_FORMTYPE(PNDT);

			~PlanetData() override;  // 00

			// members
			BGSSurface::Tree* surfaceTree;  // 30
			std::uint64_t     unk38;        // 38
			std::uint32_t     unk40;        // 40
			std::uint32_t     unk44;        // 44
			std::uint32_t     unk48;        // 48
			std::uint32_t     unk4C;        // 4C
		};
		static_assert(sizeof(PlanetData) == 0x50);
	}
}
