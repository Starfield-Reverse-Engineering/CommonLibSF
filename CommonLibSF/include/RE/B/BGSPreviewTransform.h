#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSPreviewTransform : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSPreviewTransform);

		virtual ~BGSPreviewTransform() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSPreviewTransform_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

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
