#pragma once

#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSColorForm :
		public TESForm,     // 00
		public TESFullName  // 30
	{
	public:
		SF_RTTI_VTABLE(BGSColorForm);
		SF_FORMTYPE(CLFM);

		enum class Flag  // FNAM
		{
			kNone = 0,
			kPlayable = 1 << 0,
			kRemappingIndex = 1 << 1,
			kExtendedLUT = 1 << 2
		};

		~BGSColorForm() override;  // 00

		// memebrs
		union
		{
			std::uint32_t color;
			float         remappingIndex;
		};                                                 // 40
		TESCondition                          conditions;  // 48
		stl::enumeration<Flag, std::uint32_t> flags;       // 58
	};
	static_assert(sizeof(BGSColorForm) == 0x60);
}
