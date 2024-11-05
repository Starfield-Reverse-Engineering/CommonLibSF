#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	class TESForm;

	struct Location
	{
	public:
		// members
		NiPoint3                                        position;     // 00
		std::int32_t                                    unk0C;        // 0C
		BSTSmartPointer<TESForm, TESFormExternalPolicy> worldOrCell;  // 10
	};
	static_assert(sizeof(Location) == 0x18);
}
