#pragma once

#include "RE/A/ActorValueOwner.h"
#include "RE/B/BGSAttackDataForm.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSPerkRankArray.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/B/BGSSkinForm.h"
#include "RE/T/TESAIForm.h"
#include "RE/T/TESActorBaseData.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESContainer.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESSpellList.h"

namespace RE
{
	class TESActorBase :
		public TESBoundAnimObject,         // 000
		public TESActorBaseData,           // 118
		public TESContainer,               // 188
		public TESSpellList,               // 1A0
		public TESAIForm,                  // 1B8
		public TESFullName,                // 1F8
		public ActorValueOwner,            // 208
		public BGSDestructibleObjectForm,  // 210
		public BGSSkinForm,                // 220
		public BGSKeywordForm,             // 230
		public BGSAttackDataForm,          // 260
		public BGSPerkRankArray,           // 270
		public BGSPropertySheet            // 288
	{
	public:
		SF_RTTI_VTABLE(TESActorBase);

		~TESActorBase() override;

		// add
		virtual void Unk_82();  // 82
		virtual void Unk_83();  // 83
		virtual void Unk_84();  // 84
		virtual void Unk_85();  // 85
	};
	static_assert(sizeof(TESActorBase) == 0x298);
}
