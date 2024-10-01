#pragma once

#include "RE/T/TESBoundObject.h"

namespace RE
{
	class TESBoundAnimObject : public TESBoundObject
	{
	public:
		SF_RTTI_VTABLE(TESBoundAnimObject);

		~TESBoundAnimObject() override;  // 00
	};
	static_assert(sizeof(TESBoundAnimObject) == 0xE8);
}
