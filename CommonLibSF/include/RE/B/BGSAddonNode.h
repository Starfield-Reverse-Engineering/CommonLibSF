#pragma once

#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/T/TESBoundObject.h"
#include "RE/W/WWiseSoundHook.h"

namespace RE
{
	class TESObjectLIGH;

	struct ADDON_DATA
	{
	public:
		// members
		std::uint16_t masterParticleCap;  // 0
		std::int8_t   flags;              // 2
	};
	static_assert(sizeof(ADDON_DATA) == 0x4);

	class BGSAddonNode :
		public TESBoundObject,       // 00
		public BGSModelMaterialSwap  // E0
	{
	public:
		SF_RTTI_VTABLE(BGSAddonNode);
		SF_FORMTYPE(ADDN);

		~BGSAddonNode() override;  // 00

		// members
		std::uint32_t            index;        // 108
		BGSAudio::WwiseSoundHook sound;        // 110
		TESObjectLIGH*           light;        // 140
		std::uint8_t             unk148[776];  // 148 - reflection data
		ADDON_DATA               data;         // 450
	};
	static_assert(sizeof(BGSAddonNode) == 0x458);
}
