#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	struct alignas(0x4) ACTOR_BASE_DATA
	{
		enum class Flag
		{
			kNone = 0,
		};

		enum class TEMPLATE_USE_FLAG
		{
			kNone = 0,
		};

		// members
		stl::enumeration<Flag, std::uint32_t>              actorBaseFlags;    // 00
		std::int16_t                                       xpValueOffset;     // 04
		std::uint16_t                                      level;             // 06
		std::uint16_t                                      calcLevelMin;      // 08
		std::uint16_t                                      calcLevelMax;      // 0A
		std::uint16_t                                      baseDisposition;   // 0C
		stl::enumeration<TEMPLATE_USE_FLAG, std::uint16_t> templateUseFlags;  // 0E
		std::int16_t                                       bleedoutOverride;  // 10
	};
	static_assert(sizeof(ACTOR_BASE_DATA) == 0x14);

	class TESActorBaseData :
		public BaseFormComponent  // ACBS
	{
	public:
		SF_RTTI_VTABLE(TESActorBaseData);

		// add
		virtual void Unk_10();  // 10
		virtual void Unk_11();  // 11
		virtual void Unk_12();  // 12
		virtual void Unk_13();  // 13

		// members
		ACTOR_BASE_DATA actorData;    // 18
		std::int32_t    changeFlags;  // 1C
		std::uint64_t   unk20;        // 20
		std::uint64_t   unk28;        // 28
		std::uint64_t   unk30;        // 30
		std::uint64_t   unk38;        // 38
		std::uint64_t   unk40;        // 40
		std::uint64_t   unk48;        // 48
		std::uint64_t   unk50;        // 50
		std::uint64_t   unk58;        // 58
		std::uint64_t   unk60;        // 60
		std::uint64_t   unk68;        // 68
	};
	static_assert(sizeof(TESActorBaseData) == 0x70);
}
