#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class SpellItem;

	class TESSpellList : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESSpellList);

		~TESSpellList() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESSpellList_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BSTArray<SpellItem*> spells;  // 08
	};
	static_assert(sizeof(TESSpellList) == 0x18);
}
