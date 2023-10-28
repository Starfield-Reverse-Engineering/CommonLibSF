#pragma once

#include "RE/B/BGSPropertySheet.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	struct CLASS_DATA
	{
	public:
		// members
		std::int32_t serviceFlags;     // 0
		float        bleedoutDefault;  // 4
	};
	static_assert(sizeof(CLASS_DATA) == 0x8);

	class TESClass :
		public TESForm,          // 00
		public TESFullName,      // 38
		public TESDescription,   // 48
		public TESTexture,       // 60
		public BGSPropertySheet  // 70
	{
	public:
		SF_RTTI_VTABLE(TESClass);
		SF_FORMTYPE(CLAS);

		~TESClass() override;  // 00

		// members
		CLASS_DATA data;  // 78 - DATA
	};
	static_assert(sizeof(TESClass) == 0x88);
}
