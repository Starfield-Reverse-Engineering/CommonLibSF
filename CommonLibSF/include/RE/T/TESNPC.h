#pragma once

#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSNativeTerminalForm.h"
#include "RE/B/BGSOverridePackCollection.h"
#include "RE/T/TESActorBase.h"
#include "RE/T/TESRaceForm.h"

namespace RE
{
	class TESNPC :
		public TESActorBase,
		public TESRaceForm,                // 298
		public BGSOverridePackCollection,  // 2A8
		public BGSForcedLocRefType,        // 2F0
		public BGSNativeTerminalForm       // 308
	{
	public:
		SF_RTTI_VTABLE(TESNPC);
		SF_FORMTYPE(NPC_);

		// members
		/*
		TESRaceForm               raceForm;                // 298
		BGSOverridePackCollection overridePackCollection;  // 2A8
		BGSForcedLocRefType       forcedLocRefType;        // 2F0
		BGSNativeTerminalForm     terminalForm;            // 308
		*/
		// More here, havent decoded this yet
	};
	/*
	static_assert(offsetof(TESNPC, raceForm) == 0x298);
	static_assert(offsetof(TESNPC, overridePackCollection) == 0x2A8);
	static_assert(offsetof(TESNPC, forcedLocRefType) == 0x2F0);
	static_assert(offsetof(TESNPC, terminalForm) == 0x308);
	*/
}
