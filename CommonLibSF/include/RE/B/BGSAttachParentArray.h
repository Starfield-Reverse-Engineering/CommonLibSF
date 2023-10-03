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
	};
	static_assert(sizeof(BGSAttachParentArray) == 0x18);
}
