#pragma once

#include "RE/B/BGSStoryManagerTreeForm.h"

namespace RE
{
	class __declspec(novtable) TESQuest :
		public BGSStoryManagerTreeForm
	{
	public:
		SF_RTTI_VTABLE(TESQuest);
		SF_FORMTYPE(QUST);

		// DNAM
		struct QUEST_DATA
		{
			// members
			float         questDelayTime;  // 0
			std::uint16_t flags;           // 4
			std::int8_t   priority;        // 6
			std::uint8_t  questType;       // 7
		};
		static_assert(sizeof(QUEST_DATA) == 0x8);

		~TESQuest() override;  // 00

		// members
		std::byte  pad38[0xD6];  // 038
		QUEST_DATA data;         // 108
	};
}
