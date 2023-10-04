#pragma once

#include "RE/B/BGSKeyword.h"

namespace RE
{
	class BGSLocationRefType : public BGSKeyword
	{
	public:
		SF_RTTI_VTABLE(BGSLocationRefType);
		SF_FORMTYPE(LCRT);

		~BGSLocationRefType() override;  // 00
	};
	static_assert(sizeof(BGSLocationRefType) == 0x80);
}
