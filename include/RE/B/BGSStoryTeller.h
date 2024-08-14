#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class TESQuest;


	class BGSStoryTeller
	{
	public:
		[[nodiscard]] static BGSStoryTeller* GetSingleton()
		{
			REL::Relocation<BGSStoryTeller**> singleton{ REL::ID(878850) };
			return *singleton;
		}

		std::uint8_t                unk00_38[0x38];
		RE::BSTArray<RE::TESQuest*> queuedToStart;
		RE::BSTArray<RE::TESQuest*> runningQuests;
		RE::BSTArray<RE::TESQuest*> queuedToStop;
		std::uint8_t                unk70[0x10];
		RE::BSTArray<RE::TESQuest*> unk78;
		RE::BSTArray<RE::TESQuest*> unk88;
	};

	static_assert(offsetof(BGSStoryTeller, queuedToStart) == 0x38);
	static_assert(offsetof(BGSStoryTeller, runningQuests) == 0x48);
	static_assert(offsetof(BGSStoryTeller, queuedToStop) == 0x58);
	static_assert(offsetof(BGSStoryTeller, unk78) == 0x78);
	static_assert(offsetof(BGSStoryTeller, unk88) == 0x88);
}
