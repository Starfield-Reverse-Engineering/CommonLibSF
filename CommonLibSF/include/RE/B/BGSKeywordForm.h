#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/I/IKeywordFormBase.h"

namespace RE
{
	class BGSKeywordForm :
		public BaseFormComponent,  // 00
		public IKeywordFormBase    // 08
	{
	public:
		SF_RTTI_VTABLE(BGSKeywordForm);

		// members
		std::uint32_t unk10;
		std::uint32_t unk14;
		std::uint64_t unk18;
		std::uint32_t unk20;
		std::uint32_t unk24;
		std::uint64_t unk28;
	};
	static_assert(sizeof(BGSKeywordForm) == 0x30);
}
