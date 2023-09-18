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

		// members
		/*38*/ TESTopicInfo* unk38;
		/*40*/ std::uint64_t unk40;
		/*48*/ std::uint64_t unk48;
		/*50*/ TESTopicInfo* unk50;  // Left/right (in the info list)
		/*58*/ std::uint8_t  unk58;
		/*59*/ std::uint8_t  pad59[3];
		/*5C*/ std::uint32_t unk5C;
		/*60*/ std::uint64_t unk60;
		/*68*/ std::uint32_t unk68;  // Initialized to 0x1FFFFi64, pointer handle?
		/*6C*/ std::uint32_t unk6C;  // Flags of some kind
		/*70*/ TESResponse*  responses;
	};
	static_assert(sizeof(TESTopicInfo) == 0x78);
}
