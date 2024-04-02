#pragma once

namespace RE
{
	class TESFile
	{
	public:
		SF_RTTI_VTABLE(TESFile);

		std::uint8_t pad0[0x38];     //0
		char         fileName[260];  //38
	};
}
