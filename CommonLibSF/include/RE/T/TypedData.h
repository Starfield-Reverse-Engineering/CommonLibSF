#pragma once

#include "RE/I/IType.h"

namespace RE
{
	namespace BSReflection
	{
		struct TypedData
		{
			// members
			IType* type;  // 00
			void*  data;  // 08
		};
		static_assert(sizeof(TypedData) == 0x10);
	}
}
