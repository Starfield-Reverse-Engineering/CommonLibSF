#pragma once

namespace RE::Scaleform
{
	class RefCountImplCore
	{
	public:
		SF_RTTI_VTABLE(Scaleform__RefCountImplCore);

		RefCountImplCore() = default;

		virtual ~RefCountImplCore() = default;  // 00

	protected:
		// members
		volatile std::int32_t refCount{ 1 };  // 08
	};
	static_assert(sizeof(RefCountImplCore) == 0x10);

	class RefCountImpl :
		public RefCountImplCore  // 00
	{
	public:
		SF_RTTI(Scaleform__RefCountImpl);

		virtual ~RefCountImpl() override = default;  // 00

		void AddRef()
		{
			stl::atomic_ref myRefCount{ refCount };
			++refCount;
		}

		void Release()
		{
			stl::atomic_ref myRefCount{ refCount };
			if (--myRefCount == 0) {
				delete this;
			}
		}
	};
	static_assert(sizeof(RefCountImpl) == 0x10);

	template <class Base, std::int32_t>
	class RefCountBaseStatImpl :
		public Base  // 00
	{
	public:
		RefCountBaseStatImpl() = default;

		virtual ~RefCountBaseStatImpl() = default;  // 00
	};

	template <class T, std::int32_t STAT>
	class RefCountBase :
		public RefCountBaseStatImpl<RefCountImpl, STAT>  // 00
	{
	public:
		RefCountBase() = default;

		virtual ~RefCountBase() = default;  // 00
	};
}
