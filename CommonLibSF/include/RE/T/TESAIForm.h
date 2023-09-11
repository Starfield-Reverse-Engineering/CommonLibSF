#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class PackageList
	{
	public:
		SF_RTTI_VTABLE(PackageList);

		virtual void Unk_00();

		// members
		std::uint64_t unk08;  // 08
		std::uint64_t unk10;  // 10
		std::uint64_t unk18;  // 18
		std::uint64_t unk20;  // 20
	};
	static_assert(sizeof(PackageList) == 0x28);

	struct alignas(0x4) AIDATA_GAME
	{
		// members
		std::uint16_t unk00;           // 00
		std::uint8_t  unk02;           // 02
		std::uint8_t  pad03;           // 03
		std::uint16_t aggroRadius[4];  // 04
		std::uint16_t pad0A;           // 0A
		std::uint8_t  unk0C;           // 0C
	};
	static_assert(sizeof(AIDATA_GAME) == 0x10);

	class TESAIForm : public BaseFormComponent
	{
	public:
		AIDATA_GAME aiData;      // 08
		PackageList aiPackList;  // 18
	};
	static_assert(sizeof(TESAIForm) == 0x40);
}
