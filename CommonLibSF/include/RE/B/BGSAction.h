#pragma once

#include "RE/B/BGSKeyword.h"

namespace RE
{
	class BGSAction : public BGSKeyword
	{
	public:
		SF_RTTI_VTABLE(BGSAction);
		SF_FORMTYPE(AACT);

		~BGSAction() override;  // 00

		// members
		std::uint32_t index;  // 80
	};
	static_assert(sizeof(BGSAction) == 0x80);
}
