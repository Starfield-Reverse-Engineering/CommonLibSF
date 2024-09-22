#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/C/Color.h"
#include "RE/M/MemoryManager.h"

namespace RE
{
	struct AVMData
	{
	public:
		enum class Type : std::uint32_t
		{
			kNone,
			kSimpleGroup,
			kComplexGroup,
			kModulation
		};

		struct Entry
		{
			SF_HEAP_REDEFINE_NEW(AVMData::Entry);

			BSFixedString name;         // 00
			BSFixedString texturePath;  // 08
			Color         color;        // 10
			std::uint32_t intensity;    // 14 In existing game entries is set to 64 for AVMD(confirmed for BGSAVMData(form) )
		};

		// members
		Type          type;      // 00
		BSFixedString category;  // 08
		Entry         unk10;     // 10
	};
	static_assert(sizeof(AVMData) == 0x28);
}
