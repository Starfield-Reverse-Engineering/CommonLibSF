#pragma once

namespace RE
{
	class NiPoint4;

	class NiUpdateData
	{
	public:
		// members
		float         delta = 0;
		float         unk04 = 0;
		float         unk08 = 0;
		std::uint32_t unk0C = 0;
		NiPoint4*     unk10 = nullptr;
		NiPoint4*     unk18 = nullptr;
		std::uint64_t unk20 = 0;
		std::uint64_t unk28 = 0;
		std::uint64_t unk30 = 0;
		std::uint32_t flags = 0x10;
		std::uint32_t flags2 = 1;
		std::uint32_t flags3 = 1;
		std::uint32_t unk44 = 0;
		float         unk48 = 0;
		std::uint32_t unk4C = 0;
		float         unk50 = 0;
		float         unk54 = 0;
		float         unk58 = 0;
		std::uint32_t unk5C = 0;
	};
}
