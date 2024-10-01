#pragma once

#include "RE/N/NiColor.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	class BGSMaterialPathForm;

	class BGSBendableSpline : public TESBoundObject
	{
	public:
		SF_RTTI_VTABLE(BGSBendableSpline);
		SF_FORMTYPE(BNDS);

		struct SplineData
		{
		public:
			// members
			float         numTiles;          // 00
			std::uint16_t numSlices;         // 04
			std::uint16_t numRelativeTiles;  // 06
			NiColor       color;             // 08
			float         windSensibility;   // 14
			float         flexibility;       // 18
		};
		static_assert(sizeof(SplineData) == 0x1C);

		// members
		SplineData           data;          // 0E0
		BGSMaterialPathForm* materialPath;  // 100
	};
	static_assert(sizeof(BGSBendableSpline) == 0x110);
}
