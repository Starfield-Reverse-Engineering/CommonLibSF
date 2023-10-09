#pragma once

#include "RE/T/TESBoundObject.h"

namespace RE
{
	class TESBoundAnimObject : public TESBoundObject
	{
	public:
		SF_RTTI_VTABLE(TESBoundAnimObject);

		virtual ~TESBoundAnimObject();

		// add
		virtual void Unk_80();  // 80
		virtual void Unk_81();  // 81
	};
	static_assert(sizeof(TESBoundAnimObject) == 0x118);
}
