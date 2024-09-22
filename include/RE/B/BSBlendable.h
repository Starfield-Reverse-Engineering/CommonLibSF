#pragma once

#include "REX/W32/D3D.h"

namespace RE::BSBlendable
{
	enum class BlendOp
	{
		kReplace = 0,
		kAdd,
		kMultiply,
		kGreater
	};

	class alignas(4) ColorValue
	{
	public:
		// members
		REX::Enum<BlendOp, std::uint32_t> op;           // 00
		REX::W32::XMFLOAT4                value;        // 04
		float                             blendAmount;  // 14
	};
	static_assert(sizeof(ColorValue) == 0x18);

	class alignas(4) FloatValue
	{
	public:
		// members
		REX::Enum<BlendOp, std::uint32_t> op;          // 0
		float                             value;       // 4
		float                             blendValue;  // 8
	};
	static_assert(sizeof(FloatValue) == 0xC);
}
