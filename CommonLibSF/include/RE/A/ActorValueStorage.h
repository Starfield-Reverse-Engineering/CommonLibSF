#pragma once

#include "RE/B/BSLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"

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
		BSTArray<BSTTuple<std::uint32_t, float>>     baseValues;  // 00
		BSTArray<BSTTuple<std::uint32_t, Modifiers>> modifiers;   // 10
		BSReadWriteLock                              avLock;      // 20
	};
	static_assert(sizeof(ActorValueStorage) == 0x28);
}
