#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSKeyword;

	struct VOICE_TYPE_DATA
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kAllowDefaultDialogue = 1 << 0,
			kFemale = 1 << 1
		};

		// members
		REX::EnumSet<Flag, std::uint8_t> flags;  // 0
		std::uint8_t                     unk01;  // 1
	};
	static_assert(sizeof(VOICE_TYPE_DATA) == 0x2);

	class BGSVoiceType : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSVoiceType);
		SF_FORMTYPE(VTYP);

		~BGSVoiceType() override;  // 00

		// members
		BGSEditorID     formEditorID;            // 30
		BGSKeyword*     animationFaceArchetype;  // 40
		VOICE_TYPE_DATA data;                    // 48
	};
	static_assert(sizeof(BGSVoiceType) == 0x58);
}
