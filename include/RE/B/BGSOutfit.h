#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSOutfit : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSOutfit);
		SF_FORMTYPE(OTFT);

		~BGSOutfit() override;  // 00

		// members
		BSTArray<TESForm*> outfitItems;  // 30
	};
	static_assert(sizeof(BGSOutfit) == 0x48);
}
