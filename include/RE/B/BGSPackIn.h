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
		public BGSKeywordForm,        // 0E0
		public BGSPropertySheet,      // 110
		public BGSPreviewTransform,   // 120
		public BGSForcedLocRefType,   // 168
		public BGSNativeTerminalForm  // 180
	{
	public:
		SF_RTTI_VTABLE(BGSPackIn);
		SF_FORMTYPE(PKIN);

		~BGSPackIn() override;  // 00

		// members
		TESObjectCELL*                    cell;           // 190
		std::uint32_t                     flags;          // 198
		BSStringT<char>                   filter;         // 19C
		BSTArray<BGSLayeredMaterialSwap*> materialSwaps;  // 1B0
		std::uint32_t                     unk1C0;         // 1C0
	};
	static_assert(sizeof(BGSPackIn) == 0x1D0);
}
