#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSGenericBaseFormTemplate : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSGenericBaseFormTemplate);
		SF_FORMTYPE(GBFT);

		// members
		BGSEditorID             formEditorID;  // 30
		BSTArray<BSFixedString> components;    // 40
	};
	static_assert(sizeof(BGSGenericBaseFormTemplate) == 0x50);
}
