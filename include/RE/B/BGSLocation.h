#pragma once

#include "RE/A/ActorValueOwner.h"
#include "RE/A/ActorValueStorage.h"
#include "RE/B/BGSEditorID.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESHandleForm.h"

namespace RE
{
	class BGSMusicType;
	class TESFaction;

	class BGSLocation :
		public TESHandleForm,     // 00
		public TESFullName,       // 30
		public BGSKeywordForm,    // 38
		public BGSPropertySheet,  // 70
		public ActorValueOwner    // 80
	{
	public:
		SF_RTTI_VTABLE(BGSLocation);
		SF_FORMTYPE(LCTN);

		enum Flags
		{
			kNone,
			kNoReset = 1 << 0
		};

		struct KEYWORD_DATA
		{
		public:
			// members
			BGSKeyword* keyword;  // 00
			float       data;     // 08
		};
		static_assert(sizeof(KEYWORD_DATA) == 0x10);

		~BGSLocation() override;  // 00

		// members
		BGSEditorID                                         formEditorID;            // 088
		TESForm*                                            unk098;                  // 098
		std::uint8_t                                        unk0A0;                  // 0A0
		std::uint8_t                                        minLevel;                // 0A1
		REX::EnumSet<Flags, std::uint8_t>                   flags;                   // 0A2
		std::uint8_t                                        maxLevel;                // 0A3
		std::uint8_t                                        unk0A4;                  // 0A4
		std::uint64_t                                       unk0A8;                  // 0A8
		std::uint64_t                                       unk0B0;                  // 0B0
		BSTSmartPointer<BGSLocation, TESFormExternalPolicy> parentLocation;          // 0B8
		TESFaction*                                         unreportedCrimeFaction;  // 0C0
		BGSMusicType*                                       musicType;               // 0C8
		TESFaction*                                         ownerFaction;            // 0D0
		std::uint32_t                                       unk0D8;                  // 0D8 - TESPointerHandle
		std::uint32_t                                       unk0DC;                  // 0DC - TESPointerHandle
		std::uint64_t                                       unk0E0;                  // 0E0
		std::uint32_t                                       unk0E8;                  // 0E8 - TESPointerHandle
		BSTArray<void*>                                     unk0F0;                  // 0F0
		BSTArray<void*>                                     unk100;                  // 100
		BSTArray<void*>                                     unk110;                  // 110
		std::uint64_t                                       unk120;                  // 120
		BSTArray<std::uint32_t>                             unk128;                  // 128
		BSTArray<void*>                                     unk138;                  // 138
		std::uint64_t                                       unk148;                  // 148
		BSTArray<std::uint32_t>                             unk150;                  // 150
		std::uint32_t                                       loadedCount;             // 160
		std::uint32_t                                       unk164;                  // 164
		BSTArray<std::uint32_t>                             unk168;                  // 168
		std::uint32_t                                       unk178;                  // 178
		ActorValueStorage                                   avStorage;               // 180
		BSTArray<KEYWORD_DATA>                              keywordData;             // 1A8
		BSTArray<void*>                                     unk1B8;                  // 1B8
		std::uint64_t                                       unk1C8;                  // 1C8
		std::uint32_t                                       unk1D0;                  // 1D0
		bool                                                explored;                // 1D4
		bool                                                everExplored;            // 1D5
		bool                                                unk1D6;                  // 1D6
		std::uint64_t                                       unk1D8;                  // 1D8
		std::uint64_t                                       unk1E0;                  // 1E0
		std::uint64_t                                       unk1E8;                  // 1E8
		std::uint64_t                                       unk1F0;                  // 1F0
		std::uint64_t                                       unk1F8;                  // 1F8
		std::uint64_t                                       unk200;                  // 200
		std::uint64_t                                       unk208;                  // 208
		std::uint64_t                                       unk210;                  // 210
		mutable BSReadWriteLock                             locker;                  // 218
	};
	static_assert(sizeof(BGSLocation) == 0x228);
}
