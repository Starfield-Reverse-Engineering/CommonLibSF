#pragma once

#include "RE/B/BGSReflectedForm.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSKeyword;

	class BGSFormFolderKeywordList : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSFormFolderKeywordList);

		~BGSFormFolderKeywordList() override;  // 00

		// members
		BSTArray<BGSKeyword*> keywords;        // 30
		BSFixedString         formFolderPath;  // 40
	};
	static_assert(sizeof(BGSFormFolderKeywordList) == 0x50);
}
