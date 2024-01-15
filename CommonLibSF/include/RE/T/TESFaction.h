#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class TESFaction :
		public TESForm,     // 000
		public TESFullName  // 030
	{
	public:
		SF_RTTI_VTABLE(TESFaction);
		SF_FORMTYPE(FACT);

		~TESFaction() override;  // 00
	};
	//static_assert(sizeof(TESFaction) == 0x158);
}
