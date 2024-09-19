#include "RE/E/ExtraLock.h"

namespace RE
{
	LOCK_LEVEL REFR_LOCK::GetLockLevel(const TESObjectREFR* a_owner) const
	{
		if (IsLocked()) {
			using func_t = decltype(&REFR_LOCK::GetLockLevel);
			static REL::Relocation<func_t> func{ ID::REFR_LOCK::GetLockLevel };
			return func(this, a_owner);
		} else {
			return LOCK_LEVEL::kUnlocked;
		}
	}

	void REFR_LOCK::SetLocked(bool a_locked)
	{
		if (a_locked) {
			flags.set(Flag::kLocked);
		} else {
			flags.reset(Flag::kLocked);
			numTries = 0;
		}
	}
}
