#pragma once

#include "RE/B/BGSPreloadable.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSImpactDataSet :
		public TESForm,        // 00
		public BGSPreloadable  // 30
	{
	public:
		SF_RTTI_VTABLE(BGSImpactDataSet);
		SF_FORMTYPE(IPDS);

		~BGSImpactDataSet() override;  // 00

		// members
		std::uint8_t impactMap[0x28];  // 38
	};
	static_assert(sizeof(BGSImpactDataSet) == 0x60);
}
