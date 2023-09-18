#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class TESResponse;

	// 78
	class TESTopicInfo :
		public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESTopicInfo);
		SF_FORMTYPE(INFO);

		TESTopicInfo* unk38;      // 38
		std::uint64_t unk40;      // 40
		std::uint64_t unk48;      // 48
		TESTopicInfo* unk50;      // 50 - Left/right (in the info list)
		std::uint8_t  unk58;      // 58
		std::uint8_t  pad59[3];   // 59
		std::uint32_t unk5C;      // 5C
		std::uint64_t unk60;      // 60
		std::uint32_t unk68;      // 68 - BSPointerHandleRef?
		std::uint32_t unk6C;      // 6C - Flags of some kind
		TESResponse*  responses;  // 70
	};
	static_assert(sizeof(TESTopicInfo) == 0x78);
}
