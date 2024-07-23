#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE::BGSSurface
{
	class Tree : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSSurface__Tree);
		SF_FORMTYPE(SFTR);

		~Tree() override;  // 00

		// members
		std::uint64_t           unk30;  // 30
		std::uint64_t           unk38;  // 38
		std::uint64_t           unk40;  // 40
		std::uint64_t           unk48;  // 48
		std::uint64_t           unk50;  // 50
		BSTArray<std::uint32_t> unk58;  // 58
	};
	static_assert(sizeof(Tree) == 0x68);
}
