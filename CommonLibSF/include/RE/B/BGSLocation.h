#pragma once

#include "RE/A/ActorValueOwner.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSLocation :
		public TESForm,           // 00
		public TESFullName,       // 38
		public BGSKeywordForm,    // 48
		public BGSPropertySheet,  // 78
		public ActorValueOwner    // 88
	{
	public:
		SF_RTTI_VTABLE(BGSLocation);
		SF_FORMTYPE(LCTN);

		std::int8_t  pad90[25];            // 90
		std::uint8_t minLevel;             // A9
		std::int8_t  padAA;                // AA
		std::uint8_t maxLevel;             // AB
		std::int8_t  padAC[20];            // AC
		BGSLocation* parentLocation;       // C0
		std::int8_t  padC8[276];           // C8
		bool         isExplored;           // 1DC
		bool         hasBeenEverExplored;  // 1DD
										   //
	};
}
