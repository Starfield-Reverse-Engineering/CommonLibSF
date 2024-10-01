#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE::BGSSurface
{
	class Block : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSSurface__Block);
		SF_FORMTYPE(SFBK);

		~Block() override;  // 00

		// members
		BSFixedString           unk30;  // 30
		std::uint64_t           unk38;  // 38
		std::uint64_t           unk40;  // 40
		std::uint32_t           unk48;  // 48
		std::uint32_t           unk4C;  // 4C
		BSTArray<std::uint16_t> unk50;  // 50
		std::uint32_t           unk60;  // 60
		std::uint8_t            unk64;  // 64
		std::uint8_t            unk65;  // 65
		std::uint8_t            unk66;  // 66
		std::uint8_t            unk67;  // 67
		std::uint8_t            unk68;  // 68
		std::uint8_t            unk69;  // 69
		std::uint8_t            unk6A;  // 6A
	};
	static_assert(sizeof(Block) == 0x78);
}
