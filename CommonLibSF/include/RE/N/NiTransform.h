#pragma once

#include "RE/N/NiMatrix3.h"
#include "RE/N/NiPoint3.h"

namespace RE
{
	class NiTransform
	{
	public:
		void MakeIdentity() noexcept
		{
			rotate.MakeIdentity();
			translate = NiPoint3{};
			scale = 1.0F;
		}

		// members
		NiMatrix3 rotate;         // 00
		NiPoint3  translate;      // 30
		float     scale{ 1.0F };  // 3C
	};
	static_assert(sizeof(NiTransform) == 0x40);
}
