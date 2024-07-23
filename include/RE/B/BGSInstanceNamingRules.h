#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSInstanceNamingRules : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSInstanceNamingRules);
		SF_FORMTYPE(INNR);

		class RuleData
		{
		public:
			// members
			BGSLocalizedString text;                      // 00
			BGSKeywordForm     keywords;                  // 08
			float              compareVal;                // 38
			std::int8_t        propertyBridgeArrayIndex;  // 3C
			std::int8_t        operatorType;              // 3D
			std::uint16_t      index;                     // 3E
			bool               revert;                    // 40
		};
		static_assert(sizeof(RuleData) == 0x48);

		struct RuleSet :
			public BSTArray<RuleData>  // 00
		{
		public:
		};
		static_assert(sizeof(RuleSet) == 0x10);

		~BGSInstanceNamingRules() override;  // 00

		// members
		stl::enumeration<FormType, std::uint8_t> type;          // 30
		RuleSet                                  rules[10];     // 38
		BSTArray<const BGSInstanceNamingRules*>  mergeSources;  // D8
	};
	static_assert(sizeof(BGSInstanceNamingRules) == 0xE8);
}
