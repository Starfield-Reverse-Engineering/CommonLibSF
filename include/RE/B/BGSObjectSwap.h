#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class BGSObjectSwap : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSObjectSwap);
		SF_FORMTYPE(OSWP);

		~BGSObjectSwap() override;  // 00

		// members
		std::uint64_t unk30;  // 30
		std::uint64_t unk38;  // 38
		std::uint64_t unk40;  // 40
		std::uint64_t unk48;  // 48
		std::uint64_t unk50;  // 50
	};
	static_assert(sizeof(BGSObjectSwap) == 0x58);
}
