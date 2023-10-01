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
		public TESBoundAnimObject,
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

		// add
		virtual void Unk_82();  // 82
		virtual void Unk_83();  // 83
		virtual void Unk_84();  // 84
		virtual void Unk_85();  // 85

		// members
		/**
		TESActorBaseData          actorBaseData;       // 118
		TESContainer              container;           // 188
		TESSpellList              spellList;           // 1A0
		TESAIForm                 aiForm;              // 1B8
		TESFullName               fullName;            // 1F8
		ActorValueOwner           actorValue;          // 208
		BGSDestructibleObjectForm destructibleObject;  // 210
		BGSSkinForm               skinForm;            // 220
		BGSKeywordForm            keywords;            // 230
		BGSAttackDataForm         attackData;          // 260
		BGSPerkRankArray          perkRankArray;       // 270
		BGSPropertySheet          propertySheet;       // 288
		*/
	};
	/*
	static_assert(offsetof(TESActorBase, actorBaseData) == 0x118);
	static_assert(offsetof(TESActorBase, container) == 0x188);
	static_assert(offsetof(TESActorBase, spellList) == 0x1A0);
	static_assert(offsetof(TESActorBase, aiForm) == 0x1B8);
	static_assert(offsetof(TESActorBase, fullName) == 0x1F8);
	static_assert(offsetof(TESActorBase, actorValue) == 0x208);
	static_assert(offsetof(TESActorBase, destructibleObject) == 0x210);
	static_assert(offsetof(TESActorBase, skinForm) == 0x220);
	static_assert(offsetof(TESActorBase, keywords) == 0x230);
	static_assert(offsetof(TESActorBase, attackData) == 0x260);
	static_assert(offsetof(TESActorBase, perkRankArray) == 0x270);
	static_assert(offsetof(TESActorBase, propertySheet) == 0x288);
	*/
}
