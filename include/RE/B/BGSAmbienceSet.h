#pragma once

#include "RE/T/TESForm.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class BGSAmbienceSet : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSAmbienceSet);
		SF_FORMTYPE(AMBS);

		~BGSAmbienceSet() override;  // 00

		// members
		std::uint64_t            unk30;  // 30
		std::uint64_t            unk38;  // 38
		std::uint64_t            unk40;  // 40
		bool                     unk48;  // 48
		BGSAudio::WwiseSoundHook unk50;  // 50
	};
	static_assert(sizeof(BGSAmbienceSet) == 0x88);
}
