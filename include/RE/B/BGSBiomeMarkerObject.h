#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class TESLevItem;

	class BGSBiomeMarkerObject :
		public TESBoundObject,  // 000
		public TESModel,        // 0E0
		public BGSKeywordForm   // 100
	{
	public:
		SF_RTTI_VTABLE(BGSBiomeMarkerObject);
		SF_FORMTYPE(BMMO);

		~BGSBiomeMarkerObject() override;  // 00

		// members
		TESCondition conditions;  // 130
		BGSKeyword*  type;        // 140
		TESLevItem*  floraList;   // 148
	};
	static_assert(sizeof(BGSBiomeMarkerObject) == 0x158);
}
