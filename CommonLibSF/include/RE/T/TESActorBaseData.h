#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/F/FactionRank.h"

namespace RE
{
	class BGSVoiceType;
	class TESActorBase;

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
			kLoopedAudio = 1 << 28,   // ?
			kIsGhost = 1 << 29,
			kInvulnerable = 1 << 31
		};

		enum class TEMPLATE_USE_FLAG
		{
			kNone = 0,
		};

		// members
		stl::enumeration<Flag, std::uint32_t>              actorBaseFlags;    // 00
		std::int16_t                                       xpValueOffset;     // 04
		std::uint16_t                                      level;             // 06
		std::uint16_t                                      calcLevelMin;      // 08
		std::uint16_t                                      calcLevelMax;      // 0A
		std::uint16_t                                      baseDisposition;   // 0C
		stl::enumeration<TEMPLATE_USE_FLAG, std::uint16_t> templateUseFlags;  // 0E
		std::int16_t                                       bleedoutOverride;  // 10
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
		virtual void CopyFromTemplateForms(TESActorBase** a_forceTemplates);  // 0B
		virtual void Unk_0C();                                                // 0C
		virtual void Unk_0D();                                                // 0D
		virtual void Unk_0E();                                                // 0E

		// members
		ACTOR_BASE_DATA        actorData;         // 08
		std::int32_t           changeFlags;       // 1C
		BSTArray<FACTION_RANK> factions;          // 20
		TESForm**              templateForms;     // 30
		std::uint64_t          unk38;             // 38
		TESForm*               baseTemplateForm;  // 40
		std::uint64_t          unk48;             // 48
		std::uint64_t          unk50;             // 50
		TESForm*               legendTemplate;    // 58
		BGSVoiceType*          voiceType;         // 60
		std::uint32_t          unk68;             // 68
		std::uint32_t          unk6C;             // 6C
	};
	static_assert(sizeof(TESActorBaseData) == 0x70);
}
