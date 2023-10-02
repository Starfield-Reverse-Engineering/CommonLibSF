#pragma once

namespace RE
{
	class BSReadWriteLock
	{
	public:
		void lock_read()
		{
			using func_t = decltype(&BSReadWriteLock::lock_read);
			REL::Relocation<func_t> func{ REL::ID(178605) };
			return func(this);
		}

		void lock_write()
		{
			using func_t = decltype(&BSReadWriteLock::lock_write);
			REL::Relocation<func_t> func{ REL::ID(34125) };
			return func(this);
		}

		void unlock_read()
		{
			using func_t = decltype(&BSReadWriteLock::unlock_read);
			REL::Relocation<func_t> func{ REL::ID(178609) };
			return func(this);
		}

		void unlock_write()
		{
			using func_t = decltype(&BSReadWriteLock::unlock_write);
			REL::Relocation<func_t> func{ REL::ID(34257) };
			return func(this);
		}

	private:
		// members
		std::uint32_t          _writerThread{ 0 };  // 0
		volatile std::uint32_t _lock{ 0 };          // 4
	};
	static_assert(sizeof(BSReadWriteLock) == 0x8);

	template <class Mutex>
	struct BSAutoLockDefaultPolicy
	{
	public:
		static void lock(Mutex& a_mutex) { a_mutex.lock(); }
		static void unlock(Mutex& a_mutex) { a_mutex.unlock(); }
	};

	template <class Mutex>
	struct BSAutoLockReadLockPolicy
	{
	public:
		static void lock(Mutex& a_mutex) { a_mutex.lock_read(); }
		static void unlock(Mutex& a_mutex) { a_mutex.unlock_read(); }
	};

	extern template struct BSAutoLockReadLockPolicy<BSReadWriteLock>;

	template <class Mutex>
	struct BSAutoLockWriteLockPolicy
	{
	public:
		static void lock(Mutex& a_mutex) { a_mutex.lock_write(); }
		static void unlock(Mutex& a_mutex) { a_mutex.unlock_write(); }
	};

	extern template struct BSAutoLockWriteLockPolicy<BSReadWriteLock>;

	template <class Mutex, template <class> class Policy = BSAutoLockDefaultPolicy>
	class BSAutoLock
	{
	public:
		using mutex_type = Mutex;
		using policy_type = Policy<mutex_type>;

		explicit BSAutoLock(mutex_type& a_mutex) :
			_lock(std::addressof(a_mutex))
		{
			policy_type::lock(*_lock);
		}

		explicit BSAutoLock(mutex_type* a_mutex) :
			_lock(a_mutex)
		{
			if (_lock) {
				policy_type::lock(*_lock);
			}
		}

		~BSAutoLock()
		{
			if (_lock) {
				policy_type::unlock(*_lock);
			}
		}

	private:
		// members
		mutex_type* _lock{ nullptr };  // 00
	};

	template <class Mutex>
	BSAutoLock(Mutex&) -> BSAutoLock<Mutex>;

	template <class Mutex>
	BSAutoLock(Mutex*) -> BSAutoLock<Mutex>;

	extern template class BSAutoLock<BSReadWriteLock, BSAutoLockReadLockPolicy>;
	extern template class BSAutoLock<BSReadWriteLock, BSAutoLockWriteLockPolicy>;

	using BSAutoReadLock = BSAutoLock<BSReadWriteLock, BSAutoLockReadLockPolicy>;
	using BSAutoWriteLock = BSAutoLock<BSReadWriteLock, BSAutoLockWriteLockPolicy>;
}
