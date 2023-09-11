#pragma once

#include "RE/I/IType.h"

namespace RE
{
	namespace BSReflection
	{
		class BasicType : public IType
		{
		public:
			TES_RTTI_VTABLE(BSReflection__BasicType);

			// members
			std::uint32_t size;      // 08
			std::uint16_t size2;     // 0C - repeat of size field?
			std::uint8_t  unk0E;     // 0E - 00
			std::uint8_t  unk0F;     // 0F - FF
			const char*   name;      // 10
			std::uint8_t  id;        // 18
			std::uint8_t  isSigned;  // 19
			std::uint16_t unk1A;     // 1A
			std::uint32_t unk1C;     // 1C
		};
		static_assert(sizeof(BasicType) == 0x20);
	}
}

