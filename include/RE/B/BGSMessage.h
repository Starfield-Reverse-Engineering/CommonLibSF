#pragma once

#include "RE/B/BSTArray.h"
#include "RE/M/MemoryManager.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class TESObjectREFR;
	class TESQuest;

	class BGSMessage :
		public TESForm,        // 00
		public TESFullName,    // 38
		public TESDescription  // 48
	{
	public:
		SF_RTTI_VTABLE(BGSMessage);
		SF_FORMTYPE(MESG);

		enum class MessageFlag
		{
			kNone = 0,
			kMessageBox = 1 << 0,
			kInitialDelay = 1 << 1
		};

		struct MESSAGEBOX_BUTTON
		{
		public:
			SF_HEAP_REDEFINE_NEW(MESSAGEBOX_BUTTON);

			// members
			BSFixedString  text;        // 00
			BSFixedString  unk08;       // 08
			TESObjectREFR* reference;   // 10
			TESCondition   conditions;  // 18
		};
		static_assert(sizeof(MESSAGEBOX_BUTTON) == 0x28);

		~BGSMessage() override;  // 00

		// members
		TESQuest*                                    ownerQuest;   // 58
		BSTArray<MESSAGEBOX_BUTTON*>                 menuButtons;  // 60
		BSFixedStringCS                              unk70;        // 70
		BGSLocalizedString                           shortName;    // 78
		stl::enumeration<MessageFlag, std::uint32_t> flags;        // 80
		std::uint32_t                                displayTime;  // 84
		std::int32_t                                 unk88;        // 88
		BSFixedStringCS                              unk90;        // 90
	};
	static_assert(sizeof(BGSMessage) == 0x98);
}
