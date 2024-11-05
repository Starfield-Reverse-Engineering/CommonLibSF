#pragma once

#include "RE/A/AVMData.h"
#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSNativeTerminalForm.h"
#include "RE/B/BGSOverridePackCollection.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTScatterTable.h"
#include "RE/N/NiPoint.h"
#include "RE/T/TESActorBase.h"
#include "RE/T/TESRace.h"
#include "RE/T/TESRaceForm.h"

namespace RE
{
	class BGSHeadPart;
	class BGSListForm;
	class BGSOutfit;
	class BGSRelationship;
	class TESClass;
	class TESCombatStyle;
	class TESFaction;
	class TESFurniture;

	struct MenuOpenCloseEvent;

	class __declspec(novtable) TESNPC :
		public TESActorBase,                     // 000
		public TESRaceForm,                      // 278
		public BGSOverridePackCollection,        // 288
		public BGSForcedLocRefType,              // 2D0
		public BGSNativeTerminalForm,            // 2E8
		public BSTEventSink<MenuOpenCloseEvent>  // 2F8
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

		struct MorphWeight
		{
			float thin;
			float muscular;
			float fat;
		};

		~TESNPC() override;  // 00

		[[nodiscard]] bool ContainsKeyword(std::string_view a_editorID)
		{
			if (ContainsKeywordString(a_editorID))
				return true;

			if (const auto race = GetRace(); race && race->ContainsKeywordString(a_editorID))
				return true;

			return false;
		}

		void CopyAppearance(TESNPC* a_source)
		{
			using func_t = decltype(&TESNPC::CopyAppearance);
			static REL::Relocation<func_t> func{ ID::TESNPC::CopyAppearance };
			return func(this, a_source);
		}

		void DeriveGeneticParentAppearance(TESNPC* a_source)
		{
			using func_t = decltype(&TESNPC::DeriveGeneticParentAppearance);
			static REL::Relocation<func_t> func{ ID::TESNPC::DeriveGeneticParentAppearance };
			return func(this, a_source);
		}

		[[nodiscard]] TESClass* GetClass() const
		{
			return npcClass;
		}

		[[nodiscard]] TESRace* GetRace() const
		{
			return formRace;
		}

		[[nodiscard]] TESNPC* GetRootFaceNPC() noexcept
		{
			return const_cast<TESNPC*>(static_cast<const TESNPC*>(this)->GetRootFaceNPC());
		}

		[[nodiscard]] const TESNPC* GetRootFaceNPC() const noexcept
		{
			auto root = this;
			while (root->faceNPC)
				root = root->faceNPC;

			return root;
		}

		[[nodiscard]] TESObjectARMO* GetSkin() const
		{
			if (formSkin)
				return formSkin;

			return formRace ? formRace->formSkin : nullptr;
		}

		[[nodiscard]] bool HasKeyword(std::string_view a_editorID)
		{
			if (HasKeywordString(a_editorID))
				return true;

			if (const auto race = GetRace(); race && race->HasKeywordString(a_editorID))
				return true;

			return false;
		}

		[[nodiscard]] bool IsInFaction(TESFaction* a_faction) const
		{
			return std::ranges::any_of(factions, [&](const auto& faction) {
				return faction.faction == a_faction && faction.rank > -1;
			});
		}

		// members
		BGSAttachParentArray                                            attachParents;    // 2F8
		std::uint32_t                                                   unk318;           // 318
		std::uint32_t                                                   unk31C;           // 31C
		TESClass*                                                       npcClass;         // 320
		BGSListForm*                                                    giftFilter;       // 328
		TESCombatStyle*                                                 combatStyle;      // 330
		std::uint32_t                                                   fileOffset;       // 338
		std::uint32_t                                                   unk33C;           // 33C
		TESRace*                                                        originalRace;     // 340
		TESNPC*                                                         faceNPC;          // 348
		MorphWeight                                                     morphWeight;      // 350
		float                                                           height;           // 35C
		float                                                           heightMax;        // 360
		std::uint32_t                                                   unk364;           // 364
		TESNPC*                                                         unk368;           // 368
		std::uint64_t                                                   unk370;           // 370
		std::uint64_t                                                   unk378;           // 378
		BGSLocalizedString                                              shortName;        // 380
		TESObjectARMO*                                                  farSkin;          // 388
		TESFurniture*                                                   powerArmorFurn;   // 390
		BGSOutfit*                                                      defaultOutfit;    // 398
		BGSOutfit*                                                      sleepOutfit;      // 3A0
		BGSListForm*                                                    defaultPackList;  // 3A8
		TESFaction*                                                     crimeFaction;     // 3B0
		TESFaction*                                                     unk3B8;           // 3B8
		BSGuarded<BSTArray<BGSHeadPart*>, BSNonReentrantSpinLock>       headParts;        // 3C0
		BSTArray<float>*                                                unk3D8;           // 3D8
		BSTHashMap2<std::uint32_t, float>*                              unk3E0;           // 3E0
		BSTHashMap<std::uint32_t, BSTHashMap<BSFixedStringCS, float>*>* unk3E8;           // 3E8
		BSTArray<AVMData>                                               tintAVMData;      // 3F0
		std::uint32_t                                                   skinToneIndex;    // 400
		std::uint32_t                                                   unk404;           // 404
		BSFixedString                                                   teeth;            // 408
		BSFixedString                                                   jewelryColor;     // 410
		BSFixedString                                                   eyeColor;         // 418
		BSFixedString                                                   hairColor;        // 420
		BSFixedString                                                   facialColor;      // 428
		BSFixedString                                                   eyebrowColor;     // 430
		BSTArray<BGSRelationship*>*                                     relationships;    // 438
		BGSLocalizedString                                              organization;     // 440 - faction?
		BSTHashMap<BSFixedStringCS, float>*                             shapeBlendData;   // 448
		REX::Enum<PRONOUN_TYPE, std::uint8_t>                           pronoun;          // 450
	};
	static_assert(sizeof(TESNPC) == 0x458);
}
