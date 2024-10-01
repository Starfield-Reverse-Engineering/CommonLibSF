#pragma once

#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class TESResponse;

	class TESTopicInfo :
		public TESForm  // 00
	{
	public:
		SF_RTTI_VTABLE(TESTopicInfo);
		SF_FORMTYPE(INFO);

		~TESTopicInfo() override;  // 00

		TESTopicInfo* unk30;      // 30
		std::uint64_t unk38;      // 38
		std::uint64_t unk40;      // 40
		TESTopicInfo* unk48;      // 48 - Left/right (in the info list)
		TESCondition  condition;  // 50
		std::uint32_t unk60;      // 60 - BSPointerHandleRef?
		std::uint32_t flags;      // 64
		TESResponse*  responses;  // 68
	};
	static_assert(sizeof(TESTopicInfo) == 0x78);
}
