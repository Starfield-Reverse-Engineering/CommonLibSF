#pragma once

#include "RE/B/BGSPreviewTransform.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSSnapBehavior;

	class BGSSnapTemplate :
		public TESForm,             // 00
		public BGSPreviewTransform  // 30
	{
	public:
		SF_RTTI_VTABLE(BGSSnapTemplate);
		SF_FORMTYPE(STMP);

		~BGSSnapTemplate() override;  // 00

		// members
		std::uint64_t    unk078;        // 078
		std::uint64_t    unk080;        // 080
		std::uint64_t    unk088;        // 088
		std::uint64_t    unk090;        // 090
		std::uint64_t    unk098;        // 098
		std::uint64_t    unk0A0;        // 0A0
		std::uint64_t    unk0A8;        // 0A8
		std::uint64_t    unk0B0;        // 0A8
		std::uint64_t    unk0B8;        // 0B8
		std::uint64_t    unk0C0;        // 0C0
		std::uint64_t    unk0C8;        // 0C8
		std::uint64_t    unk0D0;        // 0D0
		std::uint64_t    unk0D8;        // 0D8
		std::uint64_t    unk0E0;        // 0E0
		BSTArray<void*>  unk0E8;        // 0E8
		BGSSnapTemplate* parent;        // 0F8
		BGSSnapBehavior* snapBehavior;  // 100
		std::uint64_t    unk108;        // 108
		std::uint64_t    unk110;        // 110
		std::uint32_t    unk118;        // 118
	};
	static_assert(sizeof(BGSSnapTemplate) == 0x128);
}
