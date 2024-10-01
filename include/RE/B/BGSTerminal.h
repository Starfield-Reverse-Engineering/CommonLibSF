#pragma once

#include "RE/T/TESFurniture.h"

namespace RE
{
	class BGSTerminalMenu;

	class BGSTerminal : public TESFurniture
	{
	public:
		SF_RTTI_VTABLE(BGSTerminal);
		SF_FORMTYPE(TERM);

		~BGSTerminal() override;  // 00

		// members
		BGSTerminalMenu* menu;    // 280
		std::uint8_t     unk288;  // 288
	};
	static_assert(sizeof(BGSTerminal) == 0x298);
}
