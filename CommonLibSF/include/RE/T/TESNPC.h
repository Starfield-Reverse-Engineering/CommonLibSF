#pragma once

#include "RE/A/AVMData.h"
#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSNativeTerminalForm.h"
#include "RE/B/BGSOverridePackCollection.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/N/NiPoint3.h"
#include "RE/S/Sexes.h"
#include "RE/T/TESActorBase.h"
#include "RE/T/TESRaceForm.h"

namespace RE
{
	class BGSHeadPart;
	class BGSListForm;
	class BGSOutfit;
	class BGSRelationship;
	class MenuOpenCloseEvent;
	class TESClass;
	class TESCombatStyle;
	class TESFaction;
	class TESFurniture;

	class TESNPC :
		public TESActorBase,                     // 000
		public TESRaceForm,                      // 260
		public BGSOverridePackCollection,        // 270
		public BGSForcedLocRefType,              // 2B8
		public BGSNativeTerminalForm,            // 2D0
		public BSTEventSink<MenuOpenCloseEvent>  // 2E0
	{
	public:
		SF_RTTI_VTABLE(TESNPC);
		SF_FORMTYPE(NPC_);

		enum class PRONOUN_TYPE
		{
			kUnselected,
			kHeHim,
			kSheHer,
			kTheyThem
		};

		~TESNPC() override;  // 00

		[[nodiscard]] TESRace* GetRace() const { return formRace; }

		[[nodiscard]] SEX  GetSex() const;
		[[nodiscard]] bool ContainsKeyword(std::string_view a_editorID);
		[[nodiscard]] bool HasKeyword(std::string_view a_editorID);
		[[nodiscard]] bool IsInFaction(TESFaction* a_faction) const;

		struct MorphWeight
		{
			float thin;
			float muscular;
			float fat;
		};

		// members
		BGSAttachParentArray                                      attachParents;    // 2E8
		std::uint32_t                                             unk308;           // 308
		std::uint32_t                                             unk30C;           // 30C
		TESClass*                                                 npcClass;         // 310
		std::uint64_t                                             unk318;           // 318
		BGSListForm*                                              giftFilter;       // 320
		TESCombatStyle*                                           combatStyle;      // 328
		std::uint32_t                                             fileOffset;       // 330
		std::uint32_t                                             unk334;           // 334
		TESRace*                                                  originalRace;     // 338
		TESNPC*                                                   faceNPC;          // 340
		MorphWeight                                               morphWeight;      // 348
		float                                                     height;           // 354
		float                                                     heightMax;        // 358
		std::uint32_t                                             unk35C;           // 35C
		TESNPC*                                                   unk360;           // 360
		std::uint64_t                                             unk368;           // 368
		std::uint64_t                                             unk370;           // 370
		BGSLocalizedString                                        shortName;        // 378
		TESObjectARMO*                                            farSkin;          // 380
		TESFurniture*                                             powerArmorFurn;   // 388
		BGSOutfit*                                                defaultOutfit;    // 390
		BGSOutfit*                                                sleepOutfit;      // 398
		BGSListForm*                                              defaultPackList;  // 3A0
		TESFaction*                                               crimeFaction;     // 3A8
		TESFaction*                                               unk3B0;           // 3B0
		BSGuarded<BSTArray<BGSHeadPart*>, BSNonReentrantSpinLock> headparts;        // 3B8
		BSTArray<float>*                                          unk3D0;           // 3D0
		std::uint64_t                                             unk3D8;           // 3D8
		std::uint64_t                                             unk3E0;           // 3E0
		BSTArray<AVMData>                                         tintAVMData;      // 3E8
		std::uint32_t                                             skinToneIndex;    // 3F8
		std::uint32_t                                             unk3FC;           // 3FC
		BSFixedString                                             teeth;            // 400
		BSFixedString                                             jewelryColor;     // 408
		BSFixedString                                             eyeColor;         // 410
		BSFixedString                                             hairColor;        // 418
		BSFixedString                                             facialColor;      // 420
		BSFixedString                                             eyebrowColor;     // 428
		BSTArray<BGSRelationship*>*                               relationships;    // 430
		BGSLocalizedString                                        organization;     // 438 - faction?
		std::uint64_t                                             unk440;           // 440
		stl::enumeration<PRONOUN_TYPE, std::uint8_t>              pronoun;          // 448
	};
	static_assert(sizeof(TESNPC) == 0x450);
}
