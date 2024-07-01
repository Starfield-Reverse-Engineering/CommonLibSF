#pragma once

namespace RE::BSScript::Internal
{
	struct __declspec(novtable) IVMFunctionMessageDispatch
	{
	public:
		SF_RTTI(BSScript__Internal__IVMFunctionMessageDispatch);
		// VTable got optimized out?

		virtual void Unk00() = 0;               // 00
		virtual ~IVMFunctionMessageDispatch();  // 01 -- destructor is BELOW the first function.
	};
	static_assert(sizeof(IVMFunctionMessageDispatch) == 0x8);
}
