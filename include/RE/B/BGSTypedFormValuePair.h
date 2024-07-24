#pragma once

namespace RE::BGSTypedFormValuePair
{
	union SharedVal
	{
		std::uint32_t i;
		float         f;
	};
	static_assert(sizeof(SharedVal) == 0x4);
}
