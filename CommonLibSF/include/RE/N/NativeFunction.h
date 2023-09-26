#pragma once

#include "RE/N/NativeFunctionBase.h"

namespace RE
{
	namespace BSScript
	{
		class NativeFunction : public NF_util::NativeFunctionBase
		{
		public:
			NativeFunction() = delete;
			NativeFunction(const char* a_name, const char* a_className, bool a_isStatic, std::uint32_t a_numParams)
			{
				using func_t = std::add_pointer_t<NativeFunction*(NativeFunction*, const char*, const char*, bool, std::uint32_t)>;
				REL::Relocation<func_t> func{ REL::ID(196396) };
				func(this, a_name, a_className, a_isStatic, a_numParams);
			}

			virtual ~NativeFunction()
			{
				using func_t = std::add_pointer_t<void(NativeFunction*)>;
				REL::Relocation<func_t> func{ REL::ID(196398) };
				func(this);
			}

			virtual bool HasCallback(void) override { return _callback != 0; }
			virtual bool Run(VMValue* a_baseValue, VMClassRegistry* a_registry, std::uint32_t a_arg2, VMValue* a_resultValue, VMState* a_state) = 0;

		protected:
			void* _callback;  // 50
		};
		static_assert(sizeof(NativeFunction) == 0x60);
	}
}
