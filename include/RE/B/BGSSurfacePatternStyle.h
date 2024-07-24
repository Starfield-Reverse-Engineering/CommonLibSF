#pragma once

#include "RE/T/TESForm.h"

namespace RE::BGSSurface
{
	class PatternStyle : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSSurface__PatternStyle);
		SF_FORMTYPE(PTST);

		~PatternStyle() override;  // 00
	};
	static_assert(sizeof(PatternStyle) == 0x30);
}
