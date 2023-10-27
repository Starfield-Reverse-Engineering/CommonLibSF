#pragma once

namespace RE::BSScript::Internal
{
	class __declspec(novtable) IVMFunctionMessageDispatch
	{
	public:
		static constexpr auto RTTI{ RTTI::BSScript__Internal__IVMFunctionMessageDispatch };
		// VTable got optimized out?

		virtual void Unk00();                   // 00
		virtual ~IVMFunctionMessageDispatch();  // 01 -- destructor is BELOW the first function.
	};
	static_assert(sizeof(IVMFunctionMessageDispatch) == 0x8);
}
