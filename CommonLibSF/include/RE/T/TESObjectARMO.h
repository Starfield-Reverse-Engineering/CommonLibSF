#pragma once

#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSBipedObjectForm.h"
#include "RE/B/BGSBlockBashData.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEditorID.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSInstanceNamingRulesForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/B/BSTOptional.h"
#include "RE/B/BSTTuple3.h"
#include "RE/T/TBO_InstanceData.h"
#include "RE/T/TESBipedModelForm.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESRaceForm.h"

namespace RE
{
	class TESObjectARMA;

	struct TESObjectARMOInstanceData : public TBO_InstanceData
	{
	public:
		SF_RTTI_VTABLE(TESObjectARMOInstanceData);

		~TESObjectARMOInstanceData() override;

		// members
		BGSBlockBashData*                                                          blockBashData;        // 18
		BGSKeywordForm*                                                            keywords;             // 20
		BSTArray<BSTTuple3<TESForm*, TESForm*, BGSTypedFormValuePair::SharedVal>>* damageTypes;          // 28
		BSTArray<BSTTuple3<TESForm*, TESForm*, BGSTypedFormValuePair::SharedVal>>* actorValues;          // 30
		float                                                                      weight;               // 38
		float                                                                      colorRemappingIndex;  // 3C
		std::int32_t                                                               value;                // 40
		std::uint32_t                                                              health;               // 44
		std::uint32_t                                                              unk48;                // 48
		std::uint32_t                                                              unk4C;                // 4C
		std::uint16_t                                                              unk50;                // 50
		std::uint16_t                                                              unk52;                // 52
		BSTArray<void*>                                                            unk58;                // 58
		BSTArray<void*>                                                            unk68;                // 68
	};
	static_assert(sizeof(TESObjectARMOInstanceData) == 0x78);

	class TESObjectARMO :
		public TESBoundObject,             // 000
		public TESFullName,                // 118
		public TESRaceForm,                // 128
		public TESEnchantableForm,         // 138
		public BGSDestructibleObjectForm,  // 150
		public BGSPickupPutdownSounds,     // 160
		public TESBipedModelForm,          // 1C8
		public BGSEquipType,               // 220
		public BGSBipedObjectForm,         // 230
		public BGSBlockBashData,           // 240
		public BGSKeywordForm,             // 258
		public TESDescription,             // 288
		public BGSInstanceNamingRulesForm  // 2A0
	{
	public:
		SF_RTTI_VTABLE(TESObjectARMO);
		SF_FORMTYPE(ARMO);

		class ArmorAddon
		{
		public:
			// members
			std::uint16_t  index;       // 00
			TESObjectARMA* armorAddon;  // 08
		};
		static_assert(sizeof(ArmorAddon) == 0x10);

		~TESObjectARMO() override;  // 00

		bool CanUseArmor(TESRace* a_race) const
		{
			using func_t = decltype(&TESObjectARMO::CanUseArmor);
			REL::Relocation<func_t> func{ ID::TESObjectARMO::CanUseArmor };
			return func(this, a_race);
		}

		// members
		BGSEditorID                            formEditorID;   // 2B0
		BSTOptional<TESObjectARMOInstanceData> instanceData;   // 2C0
		BSTArray<ArmorAddon>                   modelArray;     // 340
		BGSAttachParentArray                   attachParents;  // 350
		std::uint64_t                          unk370;         // 370
		std::uint64_t                          unk378;         // 378
		std::uint64_t                          unk380;         // 380
		std::uint64_t                          unk388;         // 388
		std::uint64_t                          unk390;         // 390
		std::uint64_t                          unk398;         // 398
		std::uint64_t                          unk3A0;         // 3A0
		std::uint64_t                          unk3A8;         // 3A8
	};
	static_assert(sizeof(TESObjectARMO) == 0x3B0);
}
