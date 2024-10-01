#pragma once

#include "RE/B/BGSReflectedForm.h"

namespace RE
{
	class BGSMaterialPathForm : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSMaterialPathForm);
		SF_FORMTYPE(MTPT);

		~BGSMaterialPathForm() override;  // 00

		// members
		BSFixedString material;  // 30 - Part of or full relative path to a material
	};
	static_assert(sizeof(BGSMaterialPathForm) == 0x40);
}
