#pragma once

#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSNativeTerminalForm.h"
#include "RE/B/BGSOverridePackCollection.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/C/Color.h"
#include "RE/N/NiPoint3.h"
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

	class TESNPC :
		public TESActorBase,                     // 000
		public TESRaceForm,                      // 298
		public BGSOverridePackCollection,        // 2A8
		public BGSForcedLocRefType,              // 2F0
		public BGSNativeTerminalForm,            // 308
		public BSTEventSink<MenuOpenCloseEvent>  // 318
	{
	public:
		SF_RTTI_VTABLE(TESNPC);
		SF_FORMTYPE(NPC_);

		enum class PRONOUN_TYPE
		{
			kNone,
			kHeHim,
			kSheHer,
			kTheyThem
		};

		struct TintData
		{
			std::uint32_t type;         // 00
			std::uint32_t unk04;        // 04
			BSFixedString category;     // 08
			BSFixedString name;         // 10
			BSFixedString texturePath;  // 18
			Color         color;        // 20
			std::uint32_t intensity;    // 24
		};
		static_assert(sizeof(TintData) == 0x28);

		~TESNPC() override;  // 00

		// members
		BGSAttachParentArray                         attachParents;    // 320
		std::uint64_t                                unk338;           // 338
		std::uint32_t                                unk340;           // 340
		std::uint32_t                                unk344;           // 344
		TESClass*                                    npcClass;         // 348
		std::uint64_t                                unk350;           // 350
		BGSListForm*                                 giftFilter;       // 358
		TESCombatStyle*                              combatStyle;      // 360
		std::uint32_t                                fileOffset;       // 368
		std::uint32_t                                unk36C;           // 36C
		TESRace*                                     originalRace;     // 370
		TESNPC*                                      faceNPC;          // 378
		NiPoint3                                     morphWeight;      // 380
		float                                        height;           // 38C
		float                                        heightMax;        // 390
		std::uint32_t                                unk394;           // 394
		std::uint64_t                                unk398;           // 398
		std::uint64_t                                unk3A0;           // 3A0
		std::uint64_t                                unk3A8;           // 3A8
		BGSLocalizedString                           shortName;        // 3B0
		std::uint64_t                                unk3B8;           // 3B8
		std::uint64_t                                unk3C0;           // 3C0
		BGSOutfit*                                   defaultOutfit;    // 3C8
		BGSOutfit*                                   sleepOutfit;      // 3D0
		BGSListForm*                                 defaultPackList;  // 3D8
		TESFaction*                                  crimeFaction;     // 3E0
		std::uint64_t                                unk3E8;           // 3E8
		BSTArray<BGSHeadPart*>                       headparts;        // 3F0
		std::uint64_t                                unk400;           // 400
		std::uint64_t                                unk408;           // 408
		std::uint64_t                                unk410;           // 410
		std::uint64_t                                unk418;           // 418
		BSTArray<TintData>                           tintData;         // 420
		std::uint32_t                                skinToneIndex;    // 430
		std::uint32_t                                unk434;           // 434
		BSFixedString                                teeth;            // 438
		BSFixedString                                jewelryColor;     // 440
		BSFixedString                                eyeColor;         // 448
		BSFixedString                                hairColor;        // 450
		BSFixedString                                facialColor;      // 458
		BSFixedString                                eyebrowColor;     // 460
		BSTArray<BGSRelationship*>*                  relationships;    // 468
		BGSLocalizedString                           organization;     // 470 - faction?
		std::uint64_t                                unk478;           // 478
		stl::enumeration<PRONOUN_TYPE, std::uint8_t> pronoun;          // 480
	};
	static_assert(sizeof(TESNPC) == 0x488);
}
