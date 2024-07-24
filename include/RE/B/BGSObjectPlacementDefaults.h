#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSObjectPlacementDefaults : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSObjectPlacementDefaults);

		~BGSObjectPlacementDefaults() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSObjectPaletteDefaults_Component"; } ???
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		std::uint64_t unk08;  // 08
	};
	static_assert(sizeof(BGSObjectPlacementDefaults) == 0x10);
}
