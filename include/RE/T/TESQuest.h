#pragma once

namespace RE
{
	class TESQuest : public BGSStoryManagerTreeForm  // 000
	{
	public:
		SF_RTTI_VTABLE(TESQuest);
		SF_FORMTYPE(QUST);

		struct QUEST_DATA  // DNAM
		{
		public:
			
			// members
			float                                      questDelayTime;  // 0
			std::uint16_t							   flags;           // 4
			std::int8_t                                priority;        // 6
			std::uint8_t							   questType;       // 7
		};
		static_assert(sizeof(QUEST_DATA) == 0x8);

		uint8_t    unk00_D6[0xD6];
		QUEST_DATA data;

	};
	static_assert(offsetof(TESQuest, data) == 0x108);
}
