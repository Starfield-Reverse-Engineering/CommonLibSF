#pragma once

namespace RE
{
	class ActiveEffect;
	class Actor;
	class EffectItem;
	class MagicItem;
	class TESBoundObject;
	class TESObjectREFR;

	struct AddTargetData;
	struct SpellDispelData;

	class MagicTarget
	{
	public:
		SF_RTTI_VTABLE(MagicTarget);

		virtual ~MagicTarget();  // 00

		// add
		virtual bool               AddTarget(AddTargetData& a_targetData);                                                     // 01
		virtual TESObjectREFR*     GetTargetStatsObject();                                                                     // 02
		[[nodiscard]] virtual bool MagicTargetIsActor() const;                                                                 // 03
		virtual bool               IsInvulnerable();                                                                           // 04
		virtual void               Unk_05();                                                                                   // 05
		virtual bool               CanAddActiveEffect() = 0;                                                                   // 06
		virtual void               Unk_07();                                                                                   // 07 - GetActiveEffectList?
		virtual void               Unk_08();                                                                                   // 08 - GetActiveEffectList const?
		virtual float              CheckResistance(MagicItem* a_spell, EffectItem* a_effect, TESBoundObject* a_source) const;  // 09
		virtual void               EffectAdded(ActiveEffect* a_effect);                                                        // 0A
		virtual void               EffectRemoved(ActiveEffect* a_effect);                                                      // 0B
		virtual void               EffectActiveStatusChanged(ActiveEffect* a_effect);                                          // 0C
		virtual bool               CheckAbsorb(Actor* a_caster, MagicItem* a_spell, const EffectItem* a_effectItem);           // 0D

		// members
		SpellDispelData* postUpdateDispelList;  // 08
		std::uint8_t     flags;                 // 10
		std::uint8_t     pad11;                 // 11
		std::uint16_t    pad12;                 // 12
		std::uint32_t    pad14;                 // 14
	};
	static_assert(sizeof(MagicTarget) == 0x18);
}
