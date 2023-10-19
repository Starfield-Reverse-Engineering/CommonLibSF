#pragma once

namespace RE
{
	class BSNonReentrantSpinLock
	{
	public:
		void               lock();
		[[nodiscard]] bool try_lock();
		void               unlock();

	private:
		// members
		volatile std::uint32_t _lock{ 0 };  // 0
	};
	static_assert(sizeof(BSNonReentrantSpinLock) == 0x4);

	class BSReadWriteLock
	{
	public:
		void lock_read();
		void lock_write();
		void unlock_read();
		void unlock_write();

	private:
		// members
		std::uint32_t          _writerThread{ 0 };  // 0
		volatile std::uint32_t _lock{ 0 };          // 4
	};
	static_assert(sizeof(BSReadWriteLock) == 0x8);

	class BSSpinLock
	{
	public:
		void               lock();
		[[nodiscard]] bool try_lock();
		void               unlock();

	private:
		// members
		std::uint32_t          _owningThread{ 0 };  // 0
		volatile std::uint32_t _lock{ 0 };          // 4
	};
	static_assert(sizeof(BSSpinLock) == 0x8);

	template <class Mutex>
	struct BSAutoLockDefaultPolicy
	{
	public:
		static void lock(Mutex& a_mutex) { a_mutex.lock(); }
		static void unlock(Mutex& a_mutex) { a_mutex.unlock(); }
	};
	static_assert(std::is_empty_v<BSAutoLockDefaultPolicy<BSSpinLock>>);

	template <class Mutex>
	struct BSAutoLockReadLockPolicy
	{
	public:
		static void lock(Mutex& a_mutex) { a_mutex.lock_read(); }
		static void unlock(Mutex& a_mutex) { a_mutex.unlock_read(); }
	};
	static_assert(std::is_empty_v<BSAutoLockReadLockPolicy<BSReadWriteLock>>);

	template <class Mutex>
	struct BSAutoLockWriteLockPolicy
	{
	public:
		static void lock(Mutex& a_mutex) { a_mutex.lock_write(); }
		static void unlock(Mutex& a_mutex) { a_mutex.unlock_write(); }
	};
	static_assert(std::is_empty_v<BSAutoLockWriteLockPolicy<BSReadWriteLock>>);

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
	static_assert(sizeof(BSAutoLock<void*>) == 0x8);

	template <class Mutex>
	BSAutoLock(Mutex&) -> BSAutoLock<Mutex>;

	template <class Mutex>
	BSAutoLock(Mutex*) -> BSAutoLock<Mutex>;

	using BSAutoReadLock = BSAutoLock<BSReadWriteLock, BSAutoLockReadLockPolicy>;
	static_assert(sizeof(BSAutoReadLock) == 0x8);

	using BSAutoWriteLock = BSAutoLock<BSReadWriteLock, BSAutoLockWriteLockPolicy>;
	static_assert(sizeof(BSAutoWriteLock) == 0x8);
}
