#pragma once

#include "RE/T/TESForm.h"
#include "RE/W/WwiseGUID.h"

namespace RE
{
	class BGSMovementType : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSMovementType);
		SF_FORMTYPE(MOVT);

		~BGSMovementType() override;  // 00
	};
	//static_assert(sizeof(BGSMovementType) == 0x140);
}
