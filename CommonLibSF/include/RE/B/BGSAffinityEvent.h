#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class ActorValueInfo;
	class TESFaction;
	class TESGlobal;
	class TESNPC;

	class BGSAffinityEvent : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSAffinityEvent);
		SF_FORMTYPE(AFFE);

		struct ReactionData
		{
		public:
			// members
			TESNPC*    npc;       // 00
			TESGlobal* reaction;  // 08
		};
		static_assert(sizeof(ReactionData) == 0x10);

		~BGSAffinityEvent() override;  // 00

		// members
		ActorValueInfo*            actorValue;     // 30
		TESGlobal*                 eventSize;      // 38
		TESGlobal*                 eventDistance;  // 40
		TESGlobal*                 eventCooldown;  // 48
		TESFaction*                faction;        // 50
		std::uint32_t              flags;          // 58
		std::uint32_t              unk5C;          // 5C
		std::vector<ReactionData*> reactionData;   // 60
		std::uint32_t              unk78;          // 78
	};
	static_assert(sizeof(BGSAffinityEvent) == 0x80);
}
