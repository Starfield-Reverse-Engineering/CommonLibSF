#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSDefaultObject : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSDefaultObject);
		SF_FORMTYPE(DFOB);

		~BGSDefaultObject() override;  // 00

		// members
		BGSEditorID                       formEditorID;  // 30
		TESForm*                          object;        // 40
		REX::Enum<FormType, std::uint8_t> objectType;    // 48
	};
	static_assert(sizeof(BGSDefaultObject) == 0x58);
}
