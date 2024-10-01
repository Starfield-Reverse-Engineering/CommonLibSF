#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/M/MagicSystem.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	enum class CHUNK_ID;

	class ActorValueInfo;
	class EffectItem;
	class EffectSetting;
	class QueuedFile;

	class MagicItem :
		public TESBoundObject,  // 000
		public TESFullName,     // 0E0
		public BGSKeywordForm   // 0F0
	{
	public:
		SF_RTTI_VTABLE(MagicItem);

		struct SkillUsageData
		{
		public:
			// members
			EffectItem*     effect;     // 00
			ActorValueInfo* skill;      // 08
			float           magnitude;  // 10
			bool            custom;     // 14
		};
		static_assert(sizeof(SkillUsageData) == 0x18);

		class Data
		{
		public:
			// members
			std::int32_t  costOverride;  // 0
			std::uint32_t flags;         // 4
		};
		static_assert(sizeof(Data) == 0x8);

		~MagicItem() override;  // 00

		// add
		virtual MagicSystem::SpellType   GetSpellType() const;                                     // 82
		virtual void                     SetCastingType(MagicSystem::CastingType a_castingType);   // 83
		virtual MagicSystem::CastingType GetCastingType() const;                                   // 84
		virtual void                     SetDelivery(MagicSystem::Delivery a_delivery);            // 85
		virtual MagicSystem::Delivery    GetDelivery() const;                                      // 86
		virtual bool                     IsValidDelivery(MagicSystem::Delivery);                   // 87
		virtual float                    GetFixedCastDuration() const;                             // 88
		virtual float                    GetRange() const;                                         // 89
		virtual bool                     IgnoreResistance() const;                                 // 8A
		virtual bool                     IgnoreLOS() const;                                        // 8B
		virtual bool                     IsFood() const;                                           // 8C
		virtual bool                     GetNoAbsorb() const;                                      // 8D
		virtual bool                     GetNoDualCastModifications() const;                       // 8E
		virtual bool                     GetSkillUsageData(SkillUsageData& a_data) const;          // 8F
		virtual bool                     IsPoison() const;                                         // 90
		virtual bool                     IsMedicine() const;                                       // 91
		virtual void                     AdjustCost(float& a_cost, Actor* a_actor) const;          // 92
		virtual float                    GetChargeTime() const;                                    // 93
		virtual std::uint32_t            GetMaxEffectCount() const;                                // 94
		virtual ActorValueInfo*          GetAssociatedSkill() const;                               // 95
		virtual CHUNK_ID                 GetChunkID();                                             // 96
		virtual void                     CopyMagicItemData(MagicItem* a_copy);                     // 97
		virtual void                     LoadMagicItemChunk(TESFile* a_file, CHUNK_ID a_chunkID);  // 98
		virtual void                     LoadChunkDataPostProcess(TESFile* a_file);                // 99
		virtual Data*                    GetData1();                                               // 9A
		virtual const Data*              GetData2() const;                                         // 9B
		virtual std::size_t              GetDataSize() const;                                      // 9C
		virtual void                     InitFromChunk(TESFile* a_file);                           // 9D

		// members
		BSTArray<EffectItem*>                                        listOfEffects;    // 120
		std::int32_t                                                 hostileCount;     // 130
		EffectSetting*                                               avEffectSetting;  // 138
		std::uint32_t                                                preloadCount;     // 13C
		BSTSmartPointer<QueuedFile, BSTSmartPointerGamebryoRefCount> preloadedItem;    // 148
	};
	static_assert(sizeof(MagicItem) == 0x158);
}
