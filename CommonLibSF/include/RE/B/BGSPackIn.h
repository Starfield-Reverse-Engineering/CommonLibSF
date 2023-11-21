#pragma once

#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSNativeTerminalForm.h"
#include "RE/B/BGSPreviewTransform.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/B/BSStringT.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	class BGSLayeredMaterialSwap;
	class TESObjectCELL;

	class BGSPackIn :
		public TESBoundObject,        // 000
		public BGSKeywordForm,        // 118
		public BGSPropertySheet,      // 148
		public BGSPreviewTransform,   // 158
		public BGSForcedLocRefType,   // 1A0
		public BGSNativeTerminalForm  // 1B8
	{
	public:
		SF_RTTI_VTABLE(BGSPackIn);
		SF_FORMTYPE(PKIN);

		~BGSPackIn() override;  // 00

		// members
		TESObjectCELL*                    cell;           // 1C8
		std::uint32_t                     flags;          // 1D0
		BSStringT<char>                   filter;         // 1D4
		BSTArray<BGSLayeredMaterialSwap*> materialSwaps;  // 1E8
		std::uint32_t                     unk1F8;         // 1F8
	};
	static_assert(sizeof(BGSPackIn) == 0x200);
}
