#include "RE/B/BSLock.h"

namespace RE
{
	void BSNonReentrantSpinLock::lock()
	{
		using func_t = decltype(&BSNonReentrantSpinLock::lock);
		REL::Relocation<func_t> func{ REL::ID(73879) };
		return func(this);
	}

	bool BSNonReentrantSpinLock::try_lock()
	{
		using func_t = decltype(&BSNonReentrantSpinLock::try_lock);
		REL::Relocation<func_t> func{ REL::ID(74235) };
		return func(this);
	}

	void BSNonReentrantSpinLock::unlock()
	{
		using func_t = decltype(&BSNonReentrantSpinLock::unlock);
		REL::Relocation<func_t> func{ REL::ID(73895) };
		return func(this);
	}

	void BSReadWriteLock::lock_read()
	{
		using func_t = decltype(&BSReadWriteLock::lock_read);
		REL::Relocation<func_t> func{ REL::ID(178605) };
		return func(this);
	}

	void BSReadWriteLock::lock_write()
	{
		using func_t = decltype(&BSReadWriteLock::lock_write);
		REL::Relocation<func_t> func{ REL::ID(34125) };
		return func(this);
	}

	void BSReadWriteLock::unlock_read()
	{
		using func_t = decltype(&BSReadWriteLock::unlock_read);
		REL::Relocation<func_t> func{ REL::ID(178609) };
		return func(this);
	}

	void BSReadWriteLock::unlock_write()
	{
		using func_t = decltype(&BSReadWriteLock::unlock_write);
		REL::Relocation<func_t> func{ REL::ID(34257) };
		return func(this);
	}

	void BSSpinLock::lock()
	{
		using func_t = decltype(&BSSpinLock::lock);
		REL::Relocation<func_t> func{ REL::ID(178543) };
		return func(this);
	}

	bool BSSpinLock::try_lock()
	{
		using func_t = decltype(&BSSpinLock::try_lock);
		REL::Relocation<func_t> func{ REL::ID(178545) };
		return func(this);
	}

	void BSSpinLock::unlock()
	{
		using func_t = decltype(&BSSpinLock::unlock);
		REL::Relocation<func_t> func{ REL::ID(178544) };
		return func(this);
	}
}
