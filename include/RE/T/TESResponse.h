#pragma once

#include "RE/B/BGSLocalizedString.h"

namespace RE
{
	// 28
	class TESResponse
	{
	public:
		BGSLocalizedString responseText;  // 00
		TESResponse*       next;          // 08
		std::uint32_t      unk10;         // 10 - BSPointerHandleRef?
		float              unk14;         // 14 - Init to -1
		std::uint64_t      unk18;         // 18
		std::uint32_t      unk20;         // 20
		std::uint32_t      unk24;         // 24
	};
	static_assert(sizeof(TESResponse) == 0x28);
}
