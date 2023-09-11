#pragma once

#include "RE/B/BGSListForm.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSOverridePackCollection : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSOverridePackCollection);

		// members
		BGSListForm* unk08;
		BGSListForm* unk10;
		BGSListForm* unk18;
		BGSListForm* unk20;
		BGSListForm* unk28;
		BGSListForm* unk30;
		BGSListForm* unk38;
		BGSListForm* unk40;
	};
	static_assert(sizeof(BGSOverridePackCollection) == 0x48);
}
