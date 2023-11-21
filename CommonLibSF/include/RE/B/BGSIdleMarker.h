#pragma once

#include "RE/B/BGSIdleCollection.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class BGSAction;

	class BGSIdleMarker :
		public TESBoundObject,    // 000
		public BGSKeywordForm,    // 118
		public TESModel,          // 148
		public BGSIdleCollection  // 168
	{
	public:
		SF_RTTI_VTABLE(BGSIdleMarker);
		SF_FORMTYPE(IDLM);

		~BGSIdleMarker() override;  // 00

		// members
		BGSKeyword* animArchType;  // 188
		BGSKeyword* flavorAnim;    // 190
		BGSAction*  action;        // 198
	};
	static_assert(sizeof(BGSIdleMarker) == 0x1A0);
}
