#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class TESQuest;

	class BGSSpeechChallengeObject :
		public TESForm,        // 00
		public BGSKeywordForm  // 30
	{
	public:
		SF_RTTI_VTABLE(BGSSpeechChallengeObject);
		SF_FORMTYPE(SPCH);

		~BGSSpeechChallengeObject() override;  // 00

		// members
		BSTArray<std::uint32_t> unk60;  // 60
		TESQuest*               quest;  // 70
		std::uint32_t           unk78;  // 78
		std::uint32_t           unk7C;  // 7C
	};
	static_assert(sizeof(BGSSpeechChallengeObject) == 0x88);
}
