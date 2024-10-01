#pragma once

#include "RE/B/BGSConditionForm.h"
#include "RE/B/BGSEditorID.h"
#include "RE/T/TESForm.h"
#include "RE/W/WwiseGUID.h"

namespace RE
{
	class TESQuest;
	class TESPackage;

	class BGSWwiseEventForm : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSWwiseEventForm);
		SF_FORMTYPE(WWED);

		~BGSWwiseEventForm() override;  // 00

		// members
		BGSEditorID         formEditorID;  // 30
		BGSAudio::WwiseGUID start;         // 40
		BGSAudio::WwiseGUID end;           // 50
		BGSConditionForm*   conditions;    // 60
	};
	static_assert(sizeof(BGSWwiseEventForm) == 0x70);
}
