#pragma once

#include "RE/B/BSTArray.h"


namespace RE
{
	class ProcessLists
	{
	public:
		[[nodiscard]] static ProcessLists* GetSingleton()
		{
			REL::Relocation<ProcessLists**> singleton{ REL::ID(878338) };
			return *singleton;
		}

		std::uint8_t                unk00_44[0x44];
		bool                    bGlobalDetectionOn;
		std::uint8_t                unk45_58[0x13];
		RE::BSTArray<std::uint32_t> highActorProcessHandles;
		RE::BSTArray<std::uint32_t> actorHandles68;		// low, middleHigh, middleLow ??
		RE::BSTArray<std::uint32_t> actorHandles78;
		RE::BSTArray<std::uint32_t> actorHandles88;
	};

	static_assert(offsetof(ProcessLists, bGlobalDetectionOn) == 0x44);
	static_assert(offsetof(ProcessLists, highActorProcessHandles) == 0x58);
	static_assert(offsetof(ProcessLists, actorHandles68) == 0x68);
	static_assert(offsetof(ProcessLists, actorHandles78) == 0x78);
	static_assert(offsetof(ProcessLists, actorHandles88) == 0x88);
}
