#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class TESWorldSpace;

	class TESObjectCELL :
		public TESForm,     // 00
		public TESFullName  // 20
	{
	public:
		SF_RTTI_VTABLE(TESObjectCELL);
		SF_FORMTYPE(CELL);

		std::uint8_t   pad[0xD8];
		TESWorldSpace* cellWorldspace;  // 120
	};
}
