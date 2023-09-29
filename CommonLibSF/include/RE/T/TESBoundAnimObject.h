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

		// members
		std::uint64_t unkF0;   // F0
		std::uint64_t unkF8;   // F8
		std::uint64_t unk100;  // 100
		std::uint64_t unk108;  // 108
		std::uint64_t unk110;  // 110
	};
	static_assert(sizeof(TESBoundAnimObject) == 0x118);
}
