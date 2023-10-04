#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSObjectPlacementDefaults : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSObjectPlacementDefaults);

		~BGSObjectPlacementDefaults() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSObjectPaletteDefaults_Component"; } ???
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		std::uint64_t unk08;  // 08
		std::uint32_t unk10;  // 10
		std::uint32_t unk14;  // 14
		std::uint32_t unk18;  // 18
	};
	static_assert(sizeof(BGSObjectPlacementDefaults) == 0x20);
}
