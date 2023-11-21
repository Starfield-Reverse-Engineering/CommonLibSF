#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/C/Color.h"

namespace RE
{
	struct AVMData
	{
	public:
		enum class TYPE
		{
			kNone,
			kSimpleGroup,
			kComplexGroup,
			kModulation
		};

		struct Entry
		{
			BSFixedString name;         // 00
			BSFixedString texturePath;  // 08
			Color         color;        // 10
			std::uint32_t intensity;    // 14
		};

		// members
		stl::enumeration<TYPE, std::uint32_t> type;      // 00
		BSFixedString                         category;  // 08
		Entry                                 unk10;     // 10
	};
	static_assert(sizeof(AVMData) == 0x28);
}
