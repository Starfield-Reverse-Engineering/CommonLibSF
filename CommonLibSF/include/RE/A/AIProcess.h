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
	public:
		MiddleLowProcessData*  middleLow;          // 00
		MiddleHighProcessData* middleHigh;         // 08
		HighProcessData*       high;               // 10
		ActorPackage           currentPackage;     // 18
		float                  hourLastProcessed;  // 48
		std::uint32_t          unk4C;              // 4C
		std::uint64_t          unk50;              // 50
		std::uint64_t          unk58;              // 58
		std::uint64_t          unk60;              // 60
		std::uint64_t          unk68;              // 68
		std::uint64_t          unk70;              // 70
		std::uint64_t          unk78;              // 78
		std::uint64_t          unk80;              // 80
		std::uint64_t          unk88;              // 88
		std::uint64_t          unk90;              // 90
		std::uint64_t          unk98;              // 98
		std::uint64_t          unkA0;              // A0
		std::uint64_t          unkA8;              // A8
		std::uint64_t          unkB0;              // B0
		std::uint64_t          unkB8;              // B8
		std::uint64_t          unkC0;              // C0
		std::uint64_t          unkC8;              // C8
		std::uint64_t          unkD0;              // D0
		std::uint64_t          unkD8;              // D8
		std::uint64_t          unkE0;              // E0
		std::uint64_t          unkE8;              // E8
		std::uint64_t          unkF0;              // F0
	};
	static_assert(sizeof(AIProcess) == 0xF8);
}
