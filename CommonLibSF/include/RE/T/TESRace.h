#pragma once

#include "RE/B/BGSAnimationGraphComponent.h"
#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSAttackDataForm.h"
#include "RE/B/BGSBipedObjectForm.h"
#include "RE/B/BGSBodyPartInfo.h"
#include "RE/B/BGSEditorID.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/B/BGSSkinForm.h"
#include "RE/B/BGSTextureModel.h"
#include "RE/S/Sexes.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESSpellList.h"

namespace RE
{
	class ActorValueInfo;
	class BGSBoneModifier;
	class BGSDebris;
	class BGSEquipSlot;
	class BGSExplosion;
	class BGSHeadPart;
	class BGSImpactDataSet;
	class BGSMaterialType;
	class BGSMovementType;
	class TESObjectWEAP;
	class TESQuest;

	struct RACE_DATA
	{
		std::uint32_t     unk00;                  // 00
		float             unk04;                  // 04
		float             unk08;                  // 08
		float             unk0C;                  // 0C
		float             angleTolerance;         // 10
		std::uint32_t     unk14;                  // 14
		TESObjectWEAP*    unk18;                  // 18
		std::uint32_t     unk20;                  // 20
		std::uint32_t     unk24;                  // 24
		std::uint32_t     unk28;                  // 28
		std::uint32_t     unk2C;                  // 2C
		std::uint32_t     unk30;                  // 30
		std::uint32_t     unk34;                  // 34
		std::uint32_t     unk38;                  // 38
		std::uint32_t     unk3C;                  // 3C
		std::uint32_t     unk40;                  // 40
		std::uint32_t     unk44;                  // 44
		std::uint32_t     unk48;                  // 48
		std::uint32_t     unk4C;                  // 4C
		std::uint32_t     unk50;                  // 50
		std::uint32_t     unk54;                  // 54
		std::uint32_t     unk58;                  // 58
		std::uint32_t     unk5C;                  // 5C
		float             height[SEXES::kTotal];  // 60
		NiPoint3          weight[SEXES::kTotal];  // 68
		std::uint64_t     unk80;                  // 80
		std::int32_t      unk88;                  // 88
		std::int32_t      unk8C;                  // 8C
		std::int32_t      unk90;                  // 90
		std::int32_t      unk94;                  // 94
		std::int32_t      unk98;                  // 98
		std::int32_t      unk9C;                  // 9C
		float             unkA0;                  // A0
		float             unkA4;                  // A4
		float             unkA8;                  // A8
		float             unkAC;                  // AC
		float             unkB0;                  // B0
		float             unkB4;                  // B4
		float             unkB8;                  // B8
		float             unkBC;                  // BC
		std::uint32_t     unkC0;                  // C0
		std::uint32_t     unkC4;                  // C4
		std::uint32_t     unkC8;                  // C8
		std::uint32_t     unkCC;                  // CC
		BGSExplosion*     unkD0;                  // D0
		BGSDebris*        unkD8;                  // D8
		BGSImpactDataSet* unkE0;                  // E0
		std::uint32_t     unkE8;                  // E8
		std::uint32_t     unkEC;                  // EC
		float             unkF0;                  // F0
		float             unkF4;                  // F4
		std::uint32_t     unkF8;                  // F8
		std::uint32_t     unkFC;                  // FC
	};
	static_assert(sizeof(RACE_DATA) == 0x100);

	struct EquipSlotData
	{
	public:
		// members
		BGSEquipSlot* equipSlot;      // 00
		BSFixedString equipSlotNode;  // 08
	};
	static_assert(sizeof(EquipSlotData) == 0x10);

	class TESRace :
		public TESForm,             // 00
		public TESFullName,         // 38
		public TESDescription,      // 48
		public TESSpellList,        // 60
		public BGSSkinForm,         // 78
		public BGSBipedObjectForm,  // 88
		public BGSKeywordForm,      // 98
		public BGSAttackDataForm,   // C8
		public BGSPropertySheet,    // D8
		public BGSPreloadable       // E8
	{
	public:
		SF_RTTI_VTABLE(TESRace);
		SF_FORMTYPE(RACE);

		struct Unk9F8
		{
			void* unk00[2];  // 00 - BGSLayeredMaterialSwap?
		};
		static_assert(sizeof(Unk9F8) == 0x10);

		~TESRace() override;  // 00

		// members
		BGSEditorID                formEditorID;                     // 0F0
		BGSMaterialType*           bloodImpactMaterial;              // 100
		std::uint64_t              unk108;                           // 108 - sound related?
		std::uint64_t              unk110;                           // 110
		std::uint64_t              unk118;                           // 118
		std::uint64_t              unk120;                           // 120
		std::uint64_t              unk128;                           // 128
		std::uint64_t              unk130;                           // 130
		std::uint64_t              unk138;                           // 138 - sound related?
		std::uint64_t              unk140;                           // 140
		std::uint64_t              unk148;                           // 148
		std::uint64_t              unk150;                           // 150
		std::uint64_t              unk158;                           // 158
		std::uint64_t              unk160;                           // 160
		BSFixedString              bipedObjectNames[64];             // 168
		ActorValueInfo*            bipedObjectConditions[64];        // 368
		std::uint64_t              unk568;                           // 568
		std::uint64_t              unk570;                           // 570
		std::uint64_t              unk578;                           // 578
		std::uint64_t              unk580;                           // 580
		std::uint64_t              unk588;                           // 588
		std::uint64_t              unk590;                           // 590
		std::uint64_t              unk598;                           // 598
		BSTArray<EquipSlotData>    equipSlotArray;                   // 5A0
		std::uint64_t              unk5B0;                           // 5B0
		TESRace*                   morphRace;                        // 5B8
		TESRace*                   armorParentRace;                  // 5C0
		BSTArray<BGSBoneModifier*> unk5C8[SEXES::kTotal];            // 5C8
		TESQuest*                  dialogueQuest;                    // 5E8
		TESModel                   unk5F0[4];                        // 5F0
		TESModel                   faceBones[SEXES::kTotal];         // 670
		RACE_DATA                  data;                             // 6B0
		std::uint64_t              unk7B0;                           // 7B0
		BGSTextureModel            unk7B8[SEXES::kTotal];            // 7B8
		BGSAnimationGraphComponent unk7F8[4];                        // 7F8
		BGSVoiceType*              defaultVoiceType[SEXES::kTotal];  // 8F8
		BGSBodyPartInfo            bodyPartInfo;                     // 908
		BGSAttachParentArray       attachParents;                    // 930
		std::uint64_t              unk948;                           // 948
		BSTArray<void*>            unk950;                           // 950
		BGSMovementType*           baseMoveTypes[4];                 // 960
		std::uint64_t              unk980;                           // 980
		std::uint64_t              unk988;                           // 988
		void*                      chargenData[SEXES::kTotal];       // 990
		std::uint64_t              unk9A0;                           // 9A0
		BSFixedString              handMaterials[SEXES::kTotal];     // 9A8
		BSFixedString              skinMaterials[SEXES::kTotal];     // 9B8
		BSFixedString              unk9C8[SEXES::kTotal];            // 9C8
		BSTArray<BGSHeadPart*>     headparts[SEXES::kTotal];         // 9D8
		Unk9F8                     unk9F8[SEXES::kTotal];            // 9F8
		BGSLocalizedString         unkA18;                           // A18
	};
	static_assert(sizeof(TESRace) == 0xA20);
}
