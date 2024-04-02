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
			BGSSurface::Tree* surfaceTree;            // 30
			float             unk38;                  // 38
			float             temperatureCelcius;     // 3C
			float             density;                // 40
			float             periAngleInDegrees;     // 44
			std::uint32_t     resourceCreationSpeed;  // 48
		};
		static_assert(sizeof(PlanetData) == 0x50);
	}
}
