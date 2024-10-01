#pragma once

#include "RE/B/BGSReflectedForm.h"
#include "RE/B/BSFloat3DCurve.h"

namespace RE
{
	class BGSCurve3DForm : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSCurve3DForm);
		SF_FORMTYPE(CUR3);

		~BGSCurve3DForm() override;  // 00

		// members
		BSFloat3DCurve curve;  // 30
	};
	static_assert(sizeof(BGSCurve3DForm) == 0xF8);
}
