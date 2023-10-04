#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESSpellList : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESSpellList);

		~TESSpellList() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESSpellList_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		std::uint32_t unk08;  // 08
		std::uint32_t unk0C;  // 0C
		std::uint64_t unk10;  // 10
	};
	static_assert(sizeof(TESSpellList) == 0x18);
}
