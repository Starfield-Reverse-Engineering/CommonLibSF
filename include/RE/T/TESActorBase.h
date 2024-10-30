#pragma once

#include "RE/A/ActorValueOwner.h"
#include "RE/B/BGSAttackDataForm.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSPerkRankArray.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/B/BGSSkinForm.h"
#include "RE/S/Sexes.h"
#include "RE/T/TESAIForm.h"
#include "RE/T/TESActorBaseData.h"
#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESContainer.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESSpellList.h"

namespace RE
{
	class TESCombatStyle;

	class __declspec(novtable) TESActorBase :
		public TESBoundAnimObject,         // 000
		public TESActorBaseData,           // 0E0
		public TESContainer,               // 168
		public TESSpellList,               // 180
		public TESAIForm,                  // 198
		public TESFullName,                // 1D8
		public ActorValueOwner,            // 1E0
		public BGSDestructibleObjectForm,  // 1F0
		public BGSSkinForm,                // 200
		public BGSKeywordForm,             // 218
		public BGSAttackDataForm,          // 240
		public BGSPerkRankArray,           // 250
		public BGSPropertySheet            // 268
	{
	public:
		SF_RTTI_VTABLE(TESActorBase);

		~TESActorBase() override;  // 00

		// add
		virtual bool            GetHasPLSpecTex() const;          // 82
		virtual TESCombatStyle* GetCombatStyle();                 // 83
		virtual void            SetCombatStyle(TESCombatStyle*);  // 84
		virtual TESForm*        GetAsForm();                      // 85

		[[nodiscard]] SEX GetSex() const
		{
			return IsFemale() ? SEX::kFemale : SEX::kMale;
		}
	};
	static_assert(sizeof(TESActorBase) == 0x270);
}
