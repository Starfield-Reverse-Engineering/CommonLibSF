#pragma once

#include "RE/A/ActorValues.h"
#include "RE/B/BGSEditorID.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSResource;

	class ActorValueInfo :
		public TESForm,     // 00
		public TESFullName  // 38
	{
	public:
		SF_RTTI_VTABLE(ActorValueInfo);

		~ActorValueInfo() override;  // 00

		// members
		BGSEditorID                                         editorID;             // 048
		std::uint64_t                                       unk058;               // 058
		std::uint64_t                                       unk060;               // 060
		std::uint64_t                                       unk068;               // 068
		std::uint64_t                                       unk070;               // 070
		std::uint64_t                                       unk078;               // 078
		std::uint64_t                                       unk080;               // 080
		std::uint64_t                                       unk088;               // 088
		std::uint64_t                                       unk090;               // 090
		std::uint64_t                                       unk098;               // 098
		std::uint64_t                                       unk0A0;               // 0A0
		std::uint64_t                                       unk0A8;               // 0A8
		std::uint64_t                                       unk0B0;               // 0B0
		std::uint64_t                                       unk0B8;               // 0B8
		std::uint64_t                                       unk0C0;               // 0C0
		std::uint64_t                                       unk0C8;               // 0C8
		std::uint64_t                                       unk0D0;               // 0D0
		std::uint64_t                                       unk0D8;               // 0D8
		std::uint64_t                                       unk0E0;               // 0E0
		std::uint64_t                                       unk0E8;               // 0E8
		std::uint64_t                                       unk0F0;               // 0F0
		std::uint64_t                                       unk0F8;               // 0F8
		std::uint64_t                                       unk100;               // 100
		std::uint64_t                                       unk108;               // 108
		std::uint64_t                                       unk110;               // 110
		std::uint64_t                                       unk118;               // 118
		std::uint64_t                                       unk120;               // 120
		std::uint64_t                                       unk128;               // 128
		std::uint64_t                                       unk130;               // 130
		std::uint64_t                                       unk138;               // 138
		std::uint64_t                                       unk140;               // 140
		BGSResource*                                        resource;             // 148
		BSFixedString                                       abbreviation;         // 150
		std::uint32_t                                       index;                // 158
		std::uint32_t                                       flags;                // 15C
		stl::enumeration<ActorValue::AVType, std::uint32_t> avType;               // 160
		std::uint32_t                                       unk164;               // 164
		std::uint32_t                                       fullCacheIndex;       // 168
		std::uint32_t                                       permanentCacheIndex;  // 16C
		std::uint64_t                                       unk170;               // 170
		std::uint32_t                                       unk178;               // 178
		std::uint32_t                                       sortIndex;            // 17C
	};
	static_assert(sizeof(ActorValueInfo) == 0x180);
}
