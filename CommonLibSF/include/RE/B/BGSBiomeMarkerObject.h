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
		public TESModel,        // 118
		public BGSKeywordForm   // 138
	{
	public:
		SF_RTTI_VTABLE(BGSBiomeMarkerObject);
		SF_FORMTYPE(BMMO);

		~BGSBiomeMarkerObject() override;  // 00

		// members
		TESCondition conditions;  // 168
		BGSKeyword*  type;        // 178
		TESLevItem*  floraList;   // 180
	};
	static_assert(sizeof(BGSBiomeMarkerObject) == 0x188);
}
