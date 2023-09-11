#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSObjectPlacementDefaults : 
		public BaseFormComponent
	{
	public:
		// add
		virtual void Unk_08();  // 08
		virtual void Unk_09();  // 09
		virtual void Unk_0A();  // 0A

		// members
		std::uint64_t unk08;  // 08
		std::uint32_t unk10;  // 10
		std::uint32_t unk14;  // 14
		std::uint32_t unk18;  // 18
	};
	static_assert(sizeof(BGSObjectPlacementDefaults) == 0x20);
}

