#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/F/FactionRank.h"

namespace RE
{
	class BGSVoiceType;
	class TESActorBase;
	class TESGlobal;
	class TESLevItem;

	struct alignas(0x4) ACTOR_BASE_DATA
	{
		enum class Flag
		{
			kNone = 0,
			kFemale = 1 << 0,
			kEssential = 1 << 1,
			kIsChargenFacePreset = 1 << 2,
			kRespawn = 1 << 3,
			kAutoCalcStats = 1 << 4,
			kUnique = 1 << 5,
			kDoesntAffectStealthMeter = 1 << 6,
			kPCLevelMult = 1 << 7,
			kUsesTemplate = 1 << 8,
			kProtected = 1 << 11,
			kSummonable = 1 << 14,
			kDoesntBleed = 1 << 16,
			kBleedoutOverride = 1 << 18,
			kOppositeGenderanims = 1 << 19,
			kSimpleActor = 1 << 20,
			kLoopedScript = 1 << 21,  // ?
			kWalkStyle = 1 << 23,
			kEditorDead = 1 << 25,
			kLoopedAudio = 1 << 28,  // ?
			kIsGhost = 1 << 29,
			kUnk30 = 1 << 30,
			kInvulnerable = 1 << 31
		};

		enum class TEMPLATE_USE_FLAG
		{
			kNone = 0,
			kTraits = 1 << 0,
			kStats = 1 << 1,
			kFactions = 1 << 2,
			kSpells = 1 << 3,
			kAIData = 1 << 4,
			kAIPackages = 1 << 5,
			kUnused = 1 << 6,
			kBaseData = 1 << 7,
			kInventory = 1 << 8,
			kScript = 1 << 9,
			kAIDefPackList = 1 << 10,
			kAttackData = 1 << 11,
			kKeywords = 1 << 12,
			kCopiedTemplate = 1 << 15
		};

		// members
		REX::EnumSet<Flag, std::uint32_t>              actorBaseFlags;    // 00
		std::int16_t                                   xpValueOffset;     // 04
		std::uint16_t                                  level;             // 06
		std::uint16_t                                  calcLevelMin;      // 08
		std::uint16_t                                  calcLevelMax;      // 0A
		std::uint16_t                                  baseDisposition;   // 0C
		REX::EnumSet<TEMPLATE_USE_FLAG, std::uint16_t> templateUseFlags;  // 0E
		std::int16_t                                   bleedoutOverride;  // 10
	};
	static_assert(sizeof(ACTOR_BASE_DATA) == 0x14);

	class TESActorBaseData : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESActorBaseData);

		~TESActorBaseData() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - return { "TESActorBaseData_Component" }
		void                 InitializeDataComponent() override;     // 02

		// add
		virtual void               CopyFromTemplateForms(TESActorBase** a_forceTemplates);  // 0B
		[[nodiscard]] virtual bool GetIsGhost() const;                                      // 0C
		[[nodiscard]] virtual bool GetEditorDead() const;                                   // 0D
		virtual void               Unk_0E();                                                // 0E

		[[nodiscard]] constexpr bool IsEssential() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kEssential); }
		[[nodiscard]] constexpr bool IsFemale() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kFemale); }
		[[nodiscard]] bool           IsGhost() const { return GetIsGhost(); }
		[[nodiscard]] constexpr bool IsProtected() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kProtected); }
		[[nodiscard]] constexpr bool IsUnique() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kUnique); }

		[[nodiscard]] std::uint16_t GetLevel() const
		{
			using func_t = decltype(&TESActorBaseData::GetLevel);
			static REL::Relocation<func_t> func{ ID::TESActorBaseData::GetLevel };
			return func(this);
		}

		[[nodiscard]] bool GetUsesLeveledTemplate(std::uint32_t a_templateUseFlag = 0xFFFFFFFF)
		{
			using func_t = decltype(&TESActorBaseData::GetUsesLeveledTemplate);
			static REL::Relocation<func_t> func{ ID::TESActorBaseData::GetUsesLeveledTemplate };
			return func(this, a_templateUseFlag);
		}

		// members
		ACTOR_BASE_DATA        actorData;         // 08
		std::int32_t           changeFlags;       // 1C
		BSTArray<FACTION_RANK> factions;          // 20
		std::uint64_t          pad30;             // 30
		TESForm**              templateForms;     // 38
		TESForm**              unk40;             // 40
		TESForm*               baseTemplateForm;  // 48
		TESLevItem*            deathItem;         // 50
		TESGlobal*             legendChance;      // 58
		TESForm*               legendTemplate;    // 60
		BGSVoiceType*          voiceType;         // 68
		std::uint32_t          unk70;             // 70
		std::uint32_t          unk74;             // 74
	};
	static_assert(sizeof(TESActorBaseData) == 0x78);
}
