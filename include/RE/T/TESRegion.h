#pragma once

#include "RE/B/BSTList.h"
#include "RE/N/NiPoint.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSLocation;
	class TESRegionData;
	class TESWorldSpace;

	struct TESRegionDataList
	{
	public:
		// members
		BSSimpleList<TESRegionData*> regionDataList;  // 00
		bool                         unk10;           // 10
	};
	static_assert(sizeof(TESRegionDataList) == 0x18);

	class TESRegionPoint
	{
	public:
		NiPoint2 point;  // 00
	};
	static_assert(sizeof(TESRegionPoint) == 0x8);

	class TESRegionPointList : public BSSimpleList<TESRegionPoint*>  // RPLD
	{
	public:
		struct ScaleResult
		{
		public:
			TESRegionPoint point;  // 00
			float          dist;   // 08
			float          scale;  // 0C
		};
		static_assert(sizeof(ScaleResult) == 0x10);

		ScaleResult*  lastScaleResult;      // 10
		bool          ownsPointMemory;      // 18
		NiPoint2      minimums;             // 1C
		NiPoint2      maximums;             // 24
		std::uint32_t distanceInsideAtMax;  // 2C - RPLI
		std::uint32_t count;                // 30
	};
	static_assert(sizeof(TESRegionPointList) == 0x38);

	class TESRegion : public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESRegion);
		SF_FORMTYPE(REGN);

		~TESRegion() override;  // 00

		// add
		virtual bool Validate();  // 62

		// members
		TESRegionDataList*                 dataList;    // 30
		BSSimpleList<TESRegionPointList*>* pointLists;  // 38
		TESWorldSpace*                     worldSpace;  // 40
		std::uint64_t                      unk48;       // 48
		BGSLocation*                       location;    // 50
		std::uint64_t                      unk58;       // 58
		std::uint32_t                      unk60;       // 60
		std::uint32_t                      unk64;       // 64
	};
	static_assert(sizeof(TESRegion) == 0x70);
}
