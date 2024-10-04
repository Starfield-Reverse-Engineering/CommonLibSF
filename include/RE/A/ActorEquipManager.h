#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class Actor;
	class BGSEquipSlot;
	class BGSObjectInstance;
	class TESBoundObject;

	namespace ActorEquipManagerEvent
	{
		struct Event;
		struct SpellEvent;
	}

	class ActorEquipManager :
		public BSTSingletonSDM<ActorEquipManager>,                 // 00
		public BSTEventSource<ActorEquipManagerEvent::Event>,      // 08
		public BSTEventSource<ActorEquipManagerEvent::SpellEvent>  // 30
	{
	public:
		[[nodiscard]] static ActorEquipManager* GetSingleton()
		{
			static REL::Relocation<ActorEquipManager**> singleton{ ID::ActorEquipManager::Singleton };
			return *singleton;
		}

		bool EquipObject(Actor* a_actor, const BGSObjectInstance& a_object, const BGSEquipSlot* a_slot, bool a_queueEquip, bool a_forceEquip, bool a_playSounds, bool a_applyNow, bool a_locked)
		{
			using func_t = decltype(&ActorEquipManager::EquipObject);
			static REL::Relocation<func_t> func{ ID::ActorEquipManager::EquipObject };
			return func(this, a_actor, a_object, a_slot, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow, a_locked);
		}

		bool UnequipObject(Actor* a_actor, const BGSObjectInstance& a_object, const BGSEquipSlot* a_slot, bool a_queueUnequip, bool a_forceUnequip, bool a_playSounds, bool a_applyNow, const BGSEquipSlot* a_slotBeingReplaced)
		{
			using func_t = decltype(&ActorEquipManager::UnequipObject);
			static REL::Relocation<func_t> func{ ID::ActorEquipManager::UnequipObject };
			return func(this, a_actor, a_object, a_slot, a_queueUnequip, a_forceUnequip, a_playSounds, a_applyNow, a_slotBeingReplaced);
		}
	};
	static_assert(sizeof(ActorEquipManager) == 0x58);
}
