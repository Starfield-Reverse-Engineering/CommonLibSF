#pragma once

#include "RE/B/BGSStoryManagerTreeForm.h"

namespace RE
{
	class BGSStoryEvent;

	struct QUEST_DATA
	{
		// members
		float         questDelayTime;  // 0
		std::uint16_t flags;           // 4
		std::int8_t   priority;        // 6
		std::uint8_t  questType;       // 7
	};
	static_assert(sizeof(QUEST_DATA) == 0x8);

	class __declspec(novtable) TESQuest :
		public BGSStoryManagerTreeForm
	{
	public:
		SF_RTTI_VTABLE(TESQuest);
		SF_FORMTYPE(QUST);

		~TESQuest() override;  // 00

		[[nodiscard]] bool IsStageDone(std::uint16_t a_stage) const
		{
			using func_t = decltype(&TESQuest::IsStageDone);
			static REL::Relocation<func_t> func{ ID::TESQuest::IsStageDone };
			return func(this, a_stage);
		}

		// members
		std::byte      pad038[0xD0];    // 038
		QUEST_DATA     data;            // 108
		std::byte      pad110[0x220];   // 110
		BGSStoryEvent* startEventData;  // 330
	};
	static_assert(offsetof(TESQuest, startEventData) == 0x330);
}
