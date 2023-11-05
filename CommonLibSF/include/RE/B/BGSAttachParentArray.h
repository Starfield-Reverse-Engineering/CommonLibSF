#pragma once

#include "RE/B/BGSTypedKeywordValueArray.h"

namespace RE
{
	class BGSAttachParentArray :
		public BaseFormComponent,                                    // 00
		public BGSTypedKeywordValueArray<KeywordType::kAttachPoint>  // 08
	{
	public:
		SF_RTTI_VTABLE(BGSAttachParentArray);

		~BGSAttachParentArray() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSAttachParentArray_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }
	};
	static_assert(sizeof(BGSAttachParentArray) == 0x20);
}
