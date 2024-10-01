#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class TESEyes :
		public TESForm,      // 00
		public TESFullName,  // 30
		public TESTexture    // 40
	{
	public:
		SF_RTTI_VTABLE(TESEyes);
		SF_FORMTYPE(EYES);

		~TESEyes() override;  // 00

		// members
		std::uint8_t unk50;  // 50
	};
	static_assert(sizeof(TESEyes) == 0x60);
}
