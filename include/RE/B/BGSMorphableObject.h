#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSMorphableObject : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSMorphableObject);
		SF_FORMTYPE(MRPH);

		~BGSMorphableObject() override;  // 00

		// members
		BGSEditorID   formEditorID;      // 30
		BSFixedString performanceMorph;  // 40
		BSFixedString chargenMorph;      // 48
		BSFixedString unk50;             // 50
		std::uint32_t unk58;             // 58
	};
	static_assert(sizeof(BGSMorphableObject) == 0x68);
}
