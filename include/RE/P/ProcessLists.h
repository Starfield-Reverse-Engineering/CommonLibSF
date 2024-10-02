#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	struct PositionPlayerEvent;

	class __declspec(novtable) ProcessLists :
		public BSTEventSink<PositionPlayerEvent>,  // 000
		public BSTSingletonSDM<ProcessLists>       // 008
	{
	public:
		SF_RTTI_VTABLE(ProcessLists);

		virtual ~ProcessLists();  // 00

		// override
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent&, BSTEventSource<PositionPlayerEvent>*) override;  // 01

		[[nodiscard]] static ProcessLists* GetSingleton()
		{
			static REL::Relocation<ProcessLists**> singleton{ REL::ID(878338) };
			return *singleton;
		}

		// members
		std::byte               pad10[0x3B];             // 010
		bool                    runDetection;            // 044
		std::byte               pad45[0x13];             // 045
		BSTArray<std::uint32_t> highActorHandles;        // 058
		BSTArray<std::uint32_t> lowActorHandles;         // 068
		BSTArray<std::uint32_t> middleHighActorHandles;  // 078
		BSTArray<std::uint32_t> middleLowActorHandles;   // 088
	};
	static_assert(offsetof(ProcessLists, runDetection) == 0x44);
	static_assert(offsetof(ProcessLists, highActorHandles) == 0x58);
	static_assert(offsetof(ProcessLists, lowActorHandles) == 0x68);
	static_assert(offsetof(ProcessLists, middleHighActorHandles) == 0x78);
	static_assert(offsetof(ProcessLists, middleLowActorHandles) == 0x88);
}
