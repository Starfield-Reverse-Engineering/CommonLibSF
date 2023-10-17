#include "RE/A/ActorEquipManager.h"

namespace RE
{
	ActorEquipManager* ActorEquipManager::GetSingleton()
	{
		REL::Relocation<ActorEquipManager**> singleton{ REL::ID(879425) };
		return *singleton;
	}

	bool ActorEquipManager::EquipObject(Actor* a_actor, const BGSObjectInstance& a_object, const BGSEquipSlot* a_slot, bool a_queueEquip, bool a_forceEquip, bool a_playSounds, bool a_applyNow, bool a_locked)
	{
		using func_t = decltype(&ActorEquipManager::EquipObject);
		REL::Relocation<func_t> func{ REL::ID(151991) };
		return func(this, a_actor, a_object, a_slot, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow, a_locked);
	}

	bool ActorEquipManager::UnequipObject(Actor* a_actor, const BGSObjectInstance& a_object, const BGSEquipSlot* a_slot, bool a_queueUnequip, bool a_forceUnequip, bool a_playSounds, bool a_applyNow, const BGSEquipSlot* a_slotBeingReplaced)
	{
		using func_t = decltype(&ActorEquipManager::UnequipObject);
		REL::Relocation<func_t> func{ REL::ID(152007) };
		return func(this, a_actor, a_object, a_slot, a_queueUnequip, a_forceUnequip, a_playSounds, a_applyNow, a_slotBeingReplaced);
	}
}
