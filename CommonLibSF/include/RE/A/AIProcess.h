#pragma once

#include "ActorPackage.h"

namespace RE
{
	struct MiddleLowProcessData;
	struct MiddleHighProcessData;
	struct HighProcessData;

	// F8
	class AIProcess
	{
		MiddleLowProcessData*  middleLow;          // 00
		MiddleHighProcessData* middleHigh;         // 08
		HighProcessData*       high;               // 10
		ActorPackage           currentPackage;     // 18
		float                  hourLastProcessed;  // 48
		std::uint32_t          unk4C;
		std::uint64_t          unk50;
		std::uint64_t          unk58;
		std::uint64_t          unk60;
		std::uint64_t          unk68;
		std::uint64_t          unk70;
		std::uint64_t          unk78;
		std::uint64_t          unk80;
		std::uint64_t          unk88;
		std::uint64_t          unk90;
		std::uint64_t          unk98;
		std::uint64_t          unkA0;
		std::uint64_t          unkA8;
		std::uint64_t          unkB0;
		std::uint64_t          unkB8;
		std::uint64_t          unkC0;
		std::uint64_t          unkC8;
		std::uint64_t          unkD0;
		std::uint64_t          unkD8;
		std::uint64_t          unkE0;
		std::uint64_t          unkE8;
		std::uint64_t          unkF0;
	};
	static_assert(sizeof(AIProcess) == 0xF8);
}
