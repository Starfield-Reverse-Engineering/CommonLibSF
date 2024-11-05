#pragma once

namespace RE
{
	class __declspec(novtable) NiRefObject
	{
	public:
		SF_RTTI_VTABLE(NiRefObject);

		virtual ~NiRefObject();

		// add
		virtual void* DeleteThis();  // 01

		void DecRefCount()
		{
			if (_InterlockedExchangeAdd(&refCount, -1) == 1)
				DeleteThis();
		}

		void IncRefCount()
		{
			_InterlockedExchangeAdd(&refCount, 1);
		}

		// members
		volatile long refCount;  // 08
	};
	static_assert(sizeof(NiRefObject) == 0x10);
}
