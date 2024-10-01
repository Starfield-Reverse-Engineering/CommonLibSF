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
#include "RE/W/WwiseSoundHook.h"

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

	struct MorphWeight
	{
		float thin;
		float muscular;
		float fat;
	};

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
		MorphWeight       weight[SEXES::kTotal];  // 68
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
		std::int32_t      unkC4;                  // C4
		std::uint32_t     unkC8;                  // C8
		std::uint32_t     unkCC;                  // CC
		BGSExplosion*     explosion;              // D0
		BGSDebris*        debris;                 // D8
		BGSImpactDataSet* impactDataSet;          // E0
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
		public TESFullName,         // 30
		public TESDescription,      // 40
		public TESSpellList,        // 58
		public BGSSkinForm,         // 70
		public BGSBipedObjectForm,  // 80
		public BGSKeywordForm,      // 90
		public BGSAttackDataForm,   // C0
		public BGSPropertySheet,    // D0
		public BGSPreloadable       // E0
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
		BGSEditorID                formEditorID;                     // 0E8
		BGSMaterialType*           bloodImpactMaterial;              // 0F8
		BGSAudio::WwiseSoundHook   corpseOpenSound;                  // 100
		BGSAudio::WwiseSoundHook   corpseCloseSound;                 // 130
		BSFixedString              bipedObjectNames[64];             // 160
		ActorValueInfo*            bipedObjectConditions[64];        // 360
		std::uint64_t              unk560;                           // 560
		std::uint64_t              unk568;                           // 568
		std::uint64_t              unk570;                           // 570
		std::uint64_t              unk578;                           // 578
		std::uint64_t              unk580;                           // 580
		std::uint64_t              unk588;                           // 588
		std::uint64_t              unk590;                           // 590
		BSTArray<EquipSlotData>    equipSlotArray;                   // 598
		std::uint64_t              unk5A8;                           // 5A8
		TESRace*                   morphRace;                        // 5B0
		TESRace*                   armorParentRace;                  // 5B8
		BSTArray<BGSBoneModifier*> unk5C0[SEXES::kTotal];            // 5C0
		TESQuest*                  dialogueQuest;                    // 5E0
		TESModel                   unk5E8[4];                        // 5E8
		TESModel                   faceBones[SEXES::kTotal];         // 668
		RACE_DATA                  data;                             // 6A8
		std::uint64_t              unk7A8;                           // 7A8
		BGSTextureModel            unk7B0[SEXES::kTotal];            // 7B0
		BGSAnimationGraphComponent unk7F0[4];                        // 7F0
		BGSVoiceType*              defaultVoiceType[SEXES::kTotal];  // 8F0
		BGSBodyPartInfo            bodyPartInfo;                     // 900
		BGSAttachParentArray       attachParents;                    // 928
		BSTArray<void*>            unk948;                           // 948
		BGSMovementType*           baseMoveTypes[4];                 // 958
		std::uint64_t              unk978;                           // 978
		std::uint64_t              unk980;                           // 980
		void*                      chargenData[SEXES::kTotal];       // 988
		std::uint64_t              unk998;                           // 998
		BSFixedString              handMaterials[SEXES::kTotal];     // 9A0
		BSFixedString              skinMaterials[SEXES::kTotal];     // 9B0
		BSFixedString              unk9C0[SEXES::kTotal];            // 9C0
		BSTArray<BGSHeadPart*>     headparts[SEXES::kTotal];         // 9D0
		Unk9F8                     unk9F0[SEXES::kTotal];            // 9F0
		BGSLocalizedString         unkA10;                           // A10
	};
	static_assert(sizeof(TESRace) == 0xA20);
}
