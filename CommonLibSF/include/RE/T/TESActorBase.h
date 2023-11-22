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
	class TESCombatStyle;

	class TESActorBase :
		public TESBoundAnimObject,         // 000
		public TESActorBaseData,           // 0E0
		public TESContainer,               // 150
		public TESSpellList,               // 168
		public TESAIForm,                  // 180
		public TESFullName,                // 1C0
		public ActorValueOwner,            // 1D0
		public BGSDestructibleObjectForm,  // 1D8
		public BGSSkinForm,                // 1E8
		public BGSKeywordForm,             // 1F8
		public BGSAttackDataForm,          // 228
		public BGSPerkRankArray,           // 238
		public BGSPropertySheet            // 250
	{
	public:
		SF_RTTI_VTABLE(TESActorBase);

		~TESActorBase() override;  // 00

		// add
		virtual bool            GetHasPLSpecTex() const;          // 82
		virtual TESCombatStyle* GetCombatStyle();                 // 83
		virtual void            SetCombatStyle(TESCombatStyle*);  // 84
		virtual TESForm*        GetAsForm();                      // 85
	};
	static_assert(sizeof(TESActorBase) == 0x260);
}
