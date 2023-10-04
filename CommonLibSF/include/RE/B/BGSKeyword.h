#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/B/BSTEvent.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSKeyword : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSKeyword);
		SF_FORMTYPE(KYWD);

		struct OnDestroyEvent;

		~BGSKeyword() override;  // 00

		// members
		BGSEditorID                    formEditorID;  // 38
		std::uint64_t                  unk48;         // 48
		BSFixedString                  unk50;         // 50
		BSTEventSource<OnDestroyEvent> destroyEvent;  // 58
	};
	static_assert(sizeof(BGSKeyword) == 0x80);
}
