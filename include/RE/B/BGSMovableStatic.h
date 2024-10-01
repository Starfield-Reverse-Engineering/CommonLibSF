#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/T/TESMagicTargetForm.h"
#include "RE/T/TESObjectSTAT.h"

namespace RE
{
	struct MOVABLE_STATIC_DATA
	{
	public:
		// members
		std::uint8_t flags;  // 0
	};
	static_assert(sizeof(MOVABLE_STATIC_DATA) == 0x1);

	class BGSMovableStatic :
		public TESObjectSTAT,              // 000
		public BGSDestructibleObjectForm,  // 170
		public TESMagicTargetForm,         // 180
		public BGSKeywordForm              // 188
	{
	public:
		SF_RTTI_VTABLE(BGSMovableStatic);
		SF_FORMTYPE(MSTT);

		~BGSMovableStatic() override;  // 00

		// members
		MOVABLE_STATIC_DATA data;    // 1B8
		float               unk1BC;  // 1BC
	};
	static_assert(sizeof(BGSMovableStatic) == 0x1C8);
}
