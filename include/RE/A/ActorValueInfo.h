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
		public TESFullName  // 30
	{
	public:
		SF_RTTI_VTABLE(ActorValueInfo);
		SF_FORMTYPE(AVIF);

		~ActorValueInfo() override;  // 00

		// members
		BGSEditorID      editorID;             // 040
		std::uint64_t    unk050;               // 050
		std::uint64_t    unk058;               // 058
		std::uint64_t    unk060;               // 060
		std::uint64_t    unk068;               // 068
		std::uint64_t    unk070;               // 070
		std::uint64_t    unk078;               // 078
		std::uint64_t    unk080;               // 080
		std::uint64_t    unk088;               // 088
		std::uint64_t    unk090;               // 090
		std::uint64_t    unk098;               // 098
		std::uint64_t    unk0A0;               // 0A0
		std::uint64_t    unk0A8;               // 0A8
		std::uint64_t    unk0B0;               // 0B0
		std::uint64_t    unk0B8;               // 0B8
		std::uint64_t    unk0C0;               // 0C0
		std::uint64_t    unk0C8;               // 0C8
		std::uint64_t    unk0D0;               // 0D0
		std::uint64_t    unk0D8;               // 0D8
		std::uint64_t    unk0E0;               // 0E0
		std::uint64_t    unk0E8;               // 0E8
		std::uint64_t    unk0F0;               // 0F0
		std::uint64_t    unk0F8;               // 0F8
		std::uint64_t    unk100;               // 100
		std::uint64_t    unk108;               // 108
		std::uint64_t    unk110;               // 110
		std::uint64_t    unk118;               // 118
		std::uint64_t    unk120;               // 120
		std::uint64_t    unk128;               // 128
		std::uint64_t    unk130;               // 130
		std::uint64_t    unk138;               // 138
		BGSResource*     resource;             // 140
		BSFixedString    abbreviation;         // 148
		std::uint32_t    index;                // 150
		std::uint32_t    flags;                // 154
		ActorValue::Type avType;               // 158
		std::uint32_t    unk15C;               // 15C
		std::uint32_t    fullCacheIndex;       // 160
		std::uint32_t    permanentCacheIndex;  // 164
		std::uint64_t    unk168;               // 168
		std::uint32_t    unk170;               // 170
		std::uint32_t    sortIndex;            // 174
	};
	static_assert(sizeof(ActorValueInfo) == 0x180);
}
