#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSPreviewTransform : public BaseFormComponent
	{
	public:
		virtual ~BGSPreviewTransform();

		// members
		std::uint64_t unk08;  // 08
		std::uint64_t unk10;  // 10
		std::uint64_t unk18;  // 18
		std::uint64_t unk20;  // 20
		std::uint64_t unk28;  // 28
		std::uint64_t unk30;  // 30
		std::uint64_t unk38;  // 38
		std::uint64_t unk40;  // 40
	};
	static_assert(sizeof(BGSPreviewTransform) == 0x48);
}
