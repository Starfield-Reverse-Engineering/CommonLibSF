#pragma once

#include "RE/B/BSLock.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/S/StructTypeInfo.h"
#include "RE/V/Variable.h"

namespace RE::BSScript
{
	class StructTypeInfo;
	class Variable;

	class Struct :
		public BSIntrusiveRefCounted  // 00
	{
	public:
		~Struct();

		// members
		BSSpinLock                      structLock;           // 04
		bool                            constructed{ true };  // 0C
		bool                            valid{ false };       // 0D
		BSTSmartPointer<StructTypeInfo> type;                 // 10
		Variable                        variables[0];         // 18
	};
	static_assert(sizeof(Struct) == 0x18);
	static_assert(offsetof(Struct, Struct::type) == 0x10);
	static_assert(offsetof(Struct, Struct::variables) == 0x18);
}
