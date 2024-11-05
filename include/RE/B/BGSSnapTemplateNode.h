#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/N/NiPoint.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	class BGSArtObject;

	class BGSSnapTemplateNode :
		public TESBoundObject,        // 000
		public BGSModelMaterialSwap,  // 0E0
		public BGSKeywordForm         // 108
	{
	public:
		SF_RTTI_VTABLE(BGSSnapTemplateNode);
		SF_FORMTYPE(STND);

		~BGSSnapTemplateNode() override;  // 00

		// members
		NiPoint3      snapAngles;  // 138
		std::uint32_t unk144;      // 144
		std::uint32_t unk148;      // 148
		std::uint32_t unk14C;      // 14C
		std::uint64_t unk150;      // 150
		std::uint64_t unk158;      // 158
		std::uint64_t unk160;      // 160
		std::uint64_t unk168;      // 168
		std::uint64_t unk170;      // 170
		BGSArtObject* artObject;   // 178
	};
	static_assert(sizeof(BGSSnapTemplateNode) == 0x188);
}
