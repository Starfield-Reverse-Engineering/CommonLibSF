#pragma once

#include "RE/B/BGSReflectedForm.h"
#include "RE/I/IAddressControllerStore.h"

namespace RE
{
	class TESImageSpace :
		public BGSReflectedForm,                // 00
		public BSBind::IAddressControllerStore  // 30
	{
	public:
		SF_RTTI_VTABLE(TESImageSpace);
		SF_FORMTYPE(IMGS);

		~TESImageSpace() override;  // 00
	};
	// static_assert(sizeof(TESImageSpace) == 0x528);
}
