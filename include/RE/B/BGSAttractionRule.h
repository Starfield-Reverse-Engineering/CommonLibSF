#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSAttractionRule : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSAttractionRule);
		SF_FORMTYPE(AORU);

		class Rule
		{
		public:
			// members
			float radius;        // 00
			float minDelay;      // 04
			float maxDelay;      // 08
			bool  requiresLOS;   // 0C
			bool  combatTarget;  // 0D
		};
		static_assert(sizeof(Rule) == 0x10);

		~BGSAttractionRule() override;  // 00

		// members
		BGSEditorID formEditorID;    // 30
		Rule        attractionRule;  // 40
	};
	static_assert(sizeof(BGSAttractionRule) == 0x58);
}
