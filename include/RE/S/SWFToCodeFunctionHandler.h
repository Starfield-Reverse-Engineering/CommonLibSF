#pragma once

#include "RE/S/ScaleformGFxFunctionHandler.h"

namespace RE
{
	class SWFToCodeFunctionHandler :
		public Scaleform::GFx::FunctionHandler  // 00
	{
	public:
		SF_RTTI_VTABLE(SWFToCodeFunctionHandler);

		virtual ~SWFToCodeFunctionHandler() = default;  // 00

		// override
		void Call(const Params&) override { return; }  // 01

		// add
		virtual void MapCodeObjectFunctions() { return; }  // 02

		void RegisterNativeFunction(const char* a_name, std::uint64_t a_idx)
		{
			using func_t = decltype(&SWFToCodeFunctionHandler::RegisterNativeFunction);
			static REL::Relocation<func_t> func{ ID::SWFToCodeFunctionHandler::RegisterNativeFunction };
			func(this, a_name, a_idx);
		}
	};
	static_assert(sizeof(SWFToCodeFunctionHandler) == 0x10);
}
