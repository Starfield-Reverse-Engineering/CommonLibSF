#pragma once

#include "RE/T/TESModel.h"

namespace RE
{
	class TESModelTri : public TESModel
	{
	public:
		SF_RTTI_VTABLE(TESModelTri);

		~TESModelTri() override;  // 00

		// override (TESModel)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESModelTri_Component"; }
	};
	static_assert(sizeof(TESModelTri) == 0x20);
}
