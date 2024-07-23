#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class TESGrass;

	class BGSGroundCover : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSGroundCover);
		SF_FORMTYPE(GCVR);

		~BGSGroundCover() override;  // 00

		// members
		std::uint64_t unk30;  // 30
		std::uint64_t unk38;  // 38
		std::uint64_t unk40;  // 40
		std::uint64_t unk48;  // 48
		std::uint64_t unk50;  // 50
		std::uint64_t unk58;  // 58
		std::uint64_t unk60;  // 60
		std::uint64_t unk68;  // 68
		std::uint64_t unk70;  // 70
		std::uint64_t unk78;  // 78
		std::uint32_t unk80;  // 80
	};
	static_assert(sizeof(BGSGroundCover) == 0x88);
}
