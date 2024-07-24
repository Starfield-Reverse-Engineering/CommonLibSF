#pragma once

#include "RE/B/BSStringT.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSReferenceGroup : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSReferenceGroup);
		SF_FORMTYPE(RFGP);

		~BGSReferenceGroup() override;  // 00

		// memebrs
		BSStringT<char> unk30;  // 30
		float           unk40;  // 40
		std::uint32_t   unk48;  // 48
		std::uint32_t   unk4C;  // 4C
		std::uint32_t   unk50;  // 50 - TESPointerHandle
		std::uint32_t   unk54;  // 54 - TESPointerHandle
		std::uint64_t   unk58;  // 58
		std::uint32_t   unk60;  // 60
	};
	static_assert(sizeof(BGSReferenceGroup) == 0x68);
}
