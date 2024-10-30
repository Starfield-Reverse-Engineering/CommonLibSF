#include "RE/T/TESObjectREFR.h"

#include "RE/B/BGSInventoryItem.h"
#include "RE/E/ExtraLock.h"

namespace RE
{
	void TESObjectREFR::ForEachEquippedItem(std::function<BSContainer::ForEachResult(const BGSInventoryItem&)> a_callback) const
	{
		ForEachInventoryItem([&](const BGSInventoryItem& a_invItem) {
			return a_invItem.IsEquipped() ? a_callback(a_invItem) : BSContainer::ForEachResult::kContinue;
		});
	}

	void TESObjectREFR::ForEachInventoryItem(std::function<BSContainer::ForEachResult(const BGSInventoryItem&)> a_callback) const
	{
		if (const auto invList = inventoryList.lock_read(); *invList) {
			for (const auto& invItem : invList->data) {
				if (invItem.object && a_callback(invItem) == BSContainer::ForEachResult::kStop) {
					break;
				}
			}
		}
	}

	BGSLocation* TESObjectREFR::GetCurrentLocation()
	{
		using func_t = decltype(&TESObjectREFR::GetCurrentLocation);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetCurrentLocation };
		return func(this);
	}

	float TESObjectREFR::GetDistance(NiPointer<TESObjectREFR> a_other, bool a_disabledRefs, bool a_ignoreWorldspace) const
	{
		using func_t = decltype(&TESObjectREFR::GetDistance);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetDistance };
		return func(this, a_other, a_disabledRefs, a_ignoreWorldspace);
	}

	TESObjectREFR* TESObjectREFR::GetLinkedRef(BGSKeyword* a_keyword)
	{
		using func_t = decltype(&TESObjectREFR::GetLinkedRef);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetLinkedRef };
		return func(this, a_keyword);
	}

	REFR_LOCK* TESObjectREFR::GetLock() const
	{
		using func_t = decltype(&TESObjectREFR::GetLock);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetLock };
		return func(this);
	}

	LOCK_LEVEL TESObjectREFR::GetLockLevel() const
	{
		const auto state = GetLock();
		return state ? state->GetLockLevel(this) : LOCK_LEVEL::kUnlocked;
	}

	TESWorldSpace* TESObjectREFR::GetParentWorldSpace()
	{
		using func_t = decltype(&TESObjectREFR::GetParentWorldSpace);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetParentWorldSpace };
		return func(this);
	}

	float TESObjectREFR::GetScale() const
	{
		using func_t = decltype(&TESObjectREFR::GetScale);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetScale };
		return func(this);
	}

	TESObjectREFR* TESObjectREFR::GetSpaceship(bool a_arg1)
	{
		using func_t = decltype(&TESObjectREFR::GetSpaceship);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetSpaceship };
		return func(this, a_arg1);
	}

	TESObjectREFR* TESObjectREFR::GetSpaceshipParentDock()
	{
		using func_t = decltype(&TESObjectREFR::GetSpaceshipParentDock);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetSpaceshipParentDock };
		return func(this);
	}

	Actor* TESObjectREFR::GetSpaceshipPilot()
	{
		using func_t = decltype(&TESObjectREFR::GetSpaceshipPilot);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetSpaceshipPilot };
		return func(this);
	}

	std::int32_t TESObjectREFR::GetValue()
	{
		using func_t = decltype(&TESObjectREFR::GetValue);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::GetValue };
		return func(this);
	}

	bool TESObjectREFR::HasKeyword(BGSKeyword* a_keyword)
	{
		using func_t = decltype(&TESObjectREFR::HasKeyword);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::HasKeyword };
		return func(this, a_keyword);
	}

	bool TESObjectREFR::IsCrimeToActivate()
	{
		using func_t = decltype(&TESObjectREFR::IsCrimeToActivate);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::IsCrimeToActivate };
		return func(this);
	}

	bool TESObjectREFR::IsInSpace(bool a_arg1)
	{
		using func_t = decltype(&TESObjectREFR::IsInSpace);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::IsInSpace };
		return func(this, a_arg1);
	}

	bool TESObjectREFR::IsLocked() const
	{
		return GetLockLevel() != LOCK_LEVEL::kUnlocked;
	}

	bool TESObjectREFR::IsObjectEquipped(TESBoundObject* a_object)
	{
		using func_t = decltype(&TESObjectREFR::IsObjectEquipped);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::IsObjectEquipped };
		return func(this, a_object);
	}

	bool TESObjectREFR::IsSpaceshipDocked()
	{
		using func_t = decltype(&TESObjectREFR::IsSpaceshipDocked);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::IsSpaceshipDocked };
		return func(this);
	}

	bool TESObjectREFR::IsSpaceshipLanded()
	{
		using func_t = decltype(&TESObjectREFR::IsSpaceshipLanded);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::IsSpaceshipLanded };
		return func(this);
	}

	bool TESObjectREFR::WornHasKeyword(BGSKeyword* a_keyword)
	{
		using func_t = decltype(&TESObjectREFR::WornHasKeyword);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::WornHasKeyword };
		return func(this, a_keyword);
	}

	void TESObjectREFR::Lock()
	{
		if (const auto lock = GetLock()) {
			lock->SetLocked(true);
			AddLockChange();
		}
	}

	void TESObjectREFR::Unlock()
	{
		if (const auto lock = GetLock()) {
			lock->SetLocked(false);
			AddLockChange();
		}
	}

	void TESObjectREFR::AddLockChange()
	{
		using func_t = decltype(&TESObjectREFR::AddLockChange);
		static REL::Relocation<func_t> func{ ID::TESObjectREFR::AddLockChange };
		return func(this);
	}
}
