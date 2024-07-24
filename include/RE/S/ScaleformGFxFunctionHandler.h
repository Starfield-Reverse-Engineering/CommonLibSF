#pragma once

#include "RE/S/ScaleformRefCount.h"

namespace RE::Scaleform::GFx
{
	class Value;
	class Movie;

	class FunctionHandler :
		public RefCountBase<FunctionHandler, 2>  // 00
	{
	public:
		SF_RTTI_VTABLE(Scaleform__GFx__FunctionHandler);

		struct Params
		{
			// members
			Value*        ret;              // 00
			Movie*        movie;            // 08
			Value*        self;             // 10
			Value*        argsWithThisRef;  // 18
			Value*        args;             // 20
			std::uint32_t argCount;         // 28
			void*         userData;         // 30
		};
		static_assert(sizeof(Params) == 0x38);

		virtual ~FunctionHandler() = default;  // 00

		// add
		virtual void Call(const Params& a_params) = 0;
	};
	static_assert(sizeof(FunctionHandler) == 0x10);
}
