#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class TESQuest;

	class __declspec(novtable) BGSStoryTeller
	{
	public:
		SF_RTTI_VTABLE(BGSStoryTeller);

		[[nodiscard]] static BGSStoryTeller* GetSingleton()
		{
			static REL::Relocation<BGSStoryTeller**> singleton{ ID::BGSStoryTeller::Singleton };
			return *singleton;
		}

		// members
		std::byte           pad00[0x38];
		BSTArray<TESQuest*> queuedStartQuests;
		BSTArray<TESQuest*> runningQuests;
		BSTArray<TESQuest*> queuedStopQuests;
		std::byte           pad70[0x10];
		BSTArray<TESQuest*> unk78;
		BSTArray<TESQuest*> unk88;
	};
	static_assert(offsetof(BGSStoryTeller, queuedStartQuests) == 0x38);
	static_assert(offsetof(BGSStoryTeller, runningQuests) == 0x48);
	static_assert(offsetof(BGSStoryTeller, queuedStopQuests) == 0x58);
	static_assert(offsetof(BGSStoryTeller, unk78) == 0x78);
	static_assert(offsetof(BGSStoryTeller, unk88) == 0x88);
}
