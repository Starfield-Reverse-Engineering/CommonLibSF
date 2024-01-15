#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE::BGSSurface
{
	class PatternStyle;

	class Pattern : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSSurface__Pattern);
		SF_FORMTYPE(SFPT);

		~Pattern() override;  // 00

		// members
		std::uint32_t unk30[256];    // 030
		std::uint64_t unk430;        // 430
		std::uint64_t unk438;        // 438
		PatternStyle* patternStyle;  // 440
		std::uint32_t unk448[256];   // 448
		std::uint64_t unk848;        // 848
	};
	static_assert(sizeof(Pattern) == 0x850);
}
