#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) TESGlobal :
		public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESGlobal);
		SF_FORMTYPE(GLOB);

		~TESGlobal() override;  // 00

		[[nodiscard]] float GetValue() const noexcept { return value; }

		// members
		BGSEditorID formEditorID;  // 30
		float       value;         // 40
	};
	static_assert(sizeof(TESGlobal) == 0x50);
}
