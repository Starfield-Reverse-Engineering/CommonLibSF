#pragma once

#include "RE/B/BSLock.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	struct Modifiers
	{
	public:
		// members
		float modifiers[3];  // 0
	};
	static_assert(sizeof(Modifiers) == 0xC);

	class ActorValueStorage
	{
	public:
		// members
		BSTArray<void*> baseValues;  // 00 - BSTTuple<std::uint32_t, float>
		BSTArray<void*> modifiers;   // 10 - BSTTuple<std::uint32_t, Modifiers>
		BSReadWriteLock avLock;      // 20
	};
	static_assert(sizeof(ActorValueStorage) == 0x28);
}
