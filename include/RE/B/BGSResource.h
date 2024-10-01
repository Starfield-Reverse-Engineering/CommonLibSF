#pragma once

#include "RE/B/BGSCraftingUseSound.h"
#include "RE/B/BGSEditorID.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSLocalizedString.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiColor.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class ActorValueInfo;
	class BGSConstructibleObject;
	class TESBoundObject;
	class TESGlobal;

	class BGSResource :
		public TESForm,             // 00
		public TESFullName,         // 30
		public BGSKeywordForm,      // 40
		public BGSCraftingUseSound  // 70
	{
	public:
		SF_RTTI_VTABLE(BGSResource);
		SF_FORMTYPE(IRES);

		~BGSResource() override;  // 00

		// members
		BGSEditorID             formEditorID;  // 0A8
		BSTArray<BGSResource*>  nextRarities;  // 0B8
		BGSLocalizedString      shortName;     // 0C8
		BSFixedString           unkD0;         // 0D0
		NiColor                 surfaceColor;  // 0D8
		std::uint32_t           unkE4;         // 0E4
		TESBoundObject*         itemList;      // 0E8
		ActorValueInfo*         actorValue;    // 0F0
		TESGlobal*              interval;      // 0F8
		BGSConstructibleObject* produce;       // 100
		std::uint8_t            unk108;        // 108
	};
	static_assert(sizeof(BGSResource) == 0x118);
}
