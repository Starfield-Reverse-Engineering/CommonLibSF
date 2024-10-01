#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSTraversal : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSTraversal);
		SF_FORMTYPE(TRAV);

		~BGSTraversal() override;  // 00

		// members
		std::uint32_t unk30;  // 30
		std::uint32_t unk34;  // 34
		std::uint32_t unk38;  // 38
		std::uint32_t unk3C;  // 3C
		std::int32_t  unk40;  // 40
	};
	static_assert(sizeof(BGSTraversal) == 0x50);
}
