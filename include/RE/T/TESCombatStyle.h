#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class TESCombatStyle : public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESCombatStyle);
		SF_FORMTYPE(CSTY);

		~TESCombatStyle() override;  // 00
	};
	//static_assert(sizeof(TESCombatStyle) == 0x328);
}
