#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSForcedLocRefType : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSForcedLocRefType);

		~BGSForcedLocRefType() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSForcedLocRefType_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BSTArray<void*> unk08;  // 08
	};
	static_assert(sizeof(BGSForcedLocRefType) == 0x18);
}
