#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class TESTopicInfo : public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESTopicInfo);
		SF_FORMTYPE(INFO);

		// members
		std::uint64_t unk38;  // 38
	};
}
