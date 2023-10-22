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
		SF_FORMTYPE(FFKW);

		~BGSFormFolderKeywordList() override;  // 00

		// members
		BSTArray<BGSKeyword*> keywords;    // 38
		BSFixedString         formFolder;  // 50
	};
	static_assert(sizeof(BGSFormFolderKeywordList) == 0x50);
}
