#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class TESReactionForm :
		public BaseFormComponent  // 00
	{
	public:
		SF_RTTI(TESReactionForm);
	};

	class __declspec(novtable) TESFaction :
		public TESForm,         // 000
		public TESFullName,     // 038
		public TESReactionForm  // 040
	{
	public:
		SF_RTTI_VTABLE(TESFaction);
		SF_FORMTYPE(FACT);

		~TESFaction() override;  // 00
	};
	//static_assert(sizeof(TESFaction) == 0x158);
}
