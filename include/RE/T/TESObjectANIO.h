#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class TESObjectANIO :
		public TESForm,              // 00
		public BGSModelMaterialSwap  // 30
	{
	public:
		SF_RTTI_VTABLE(TESObjectANIO);
		SF_FORMTYPE(ANIO);

		~TESObjectANIO() override;  // 00

		// members
		BGSEditorID formEditorID;  // 58
	};
	static_assert(sizeof(TESObjectANIO) == 0x70);
}
