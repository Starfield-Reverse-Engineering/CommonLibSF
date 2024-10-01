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
		public BGSKeywordForm,    // 0E0
		public TESModel,          // 110
		public BGSIdleCollection  // 130
	{
	public:
		SF_RTTI_VTABLE(BGSIdleMarker);
		SF_FORMTYPE(IDLM);

		~BGSIdleMarker() override;  // 00

		// members
		BGSKeyword* animArchType;  // 150
		BGSKeyword* flavorAnim;    // 158
		BGSAction*  action;        // 160
	};
	static_assert(sizeof(BGSIdleMarker) == 0x170);
}
