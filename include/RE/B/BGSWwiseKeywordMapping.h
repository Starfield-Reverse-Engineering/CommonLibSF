#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSKeyword;

	class BGSWwiseKeywordMapping : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSWwiseKeywordMapping);
		SF_FORMTYPE(WKMF);

		~BGSWwiseKeywordMapping() override;  // 00

		// members
		std::vector<BGSKeyword*> keywords;  // 30
		std::uint64_t            unk48;     // 48
		std::uint64_t            unk50;     // 50
		std::uint64_t            unk58;     // 58
		std::uint64_t            unk60;     // 60
		std::uint64_t            unk68;     // 68
		std::uint16_t            unk70;     // 70
	};
	static_assert(sizeof(BGSWwiseKeywordMapping) == 0x78);
}
