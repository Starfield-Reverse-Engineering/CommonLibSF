#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESSpellList : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESSpellList);

		// members
		std::uint32_t unk08;  // 08
		std::uint32_t unk0C;  // 0C
		std::uint64_t unk10;  // 10
	};
	static_assert(sizeof(TESSpellList) == 0x18);
}
