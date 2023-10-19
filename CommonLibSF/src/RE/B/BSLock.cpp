#include "RE/B/BSLock.h"

namespace RE
{
	void BSNonReentrantSpinLock::lock()
	{
		using func_t = decltype(&BSNonReentrantSpinLock::lock);
		REL::Relocation<func_t> func{ ID::BSNonReentrantSpinLock::lock };
		return func(this);
	}

	bool BSNonReentrantSpinLock::try_lock()
	{
		using func_t = decltype(&BSNonReentrantSpinLock::try_lock);
		REL::Relocation<func_t> func{ ID::BSNonReentrantSpinLock::try_lock };
		return func(this);
	}

	void BSNonReentrantSpinLock::unlock()
	{
		using func_t = decltype(&BSNonReentrantSpinLock::unlock);
		REL::Relocation<func_t> func{ ID::BSNonReentrantSpinLock::unlock };
		return func(this);
	}

	void BSReadWriteLock::lock_read()
	{
		using func_t = decltype(&BSReadWriteLock::lock_read);
		REL::Relocation<func_t> func{ ID::BSReadWriteLock::lock_read };
		return func(this);
	}

	void BSReadWriteLock::lock_write()
	{
		using func_t = decltype(&BSReadWriteLock::lock_write);
		REL::Relocation<func_t> func{ ID::BSReadWriteLock::lock_write };
		return func(this);
	}

	void BSReadWriteLock::unlock_read()
	{
		using func_t = decltype(&BSReadWriteLock::unlock_read);
		REL::Relocation<func_t> func{ ID::BSReadWriteLock::unlock_read };
		return func(this);
	}

	void BSReadWriteLock::unlock_write()
	{
		using func_t = decltype(&BSReadWriteLock::unlock_write);
		REL::Relocation<func_t> func{ ID::BSReadWriteLock::unlock_write };
		return func(this);
	}

	void BSSpinLock::lock()
	{
		using func_t = decltype(&BSSpinLock::lock);
		REL::Relocation<func_t> func{ ID::BSSpinLock::lock };
		return func(this);
	}

	bool BSSpinLock::try_lock()
	{
		using func_t = decltype(&BSSpinLock::try_lock);
		REL::Relocation<func_t> func{ ID::BSSpinLock::try_lock };
		return func(this);
	}

	void BSSpinLock::unlock()
	{
		using func_t = decltype(&BSSpinLock::unlock);
		REL::Relocation<func_t> func{ ID::BSSpinLock::unlock };
		return func(this);
	}
}
