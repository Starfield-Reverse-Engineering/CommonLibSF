#pragma once

#include "RE/B/BGSReflectedForm.h"
#include "RE/B/BSFloatCurve.h"

namespace RE
{
	class BGSCurveForm : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSCurveForm);
		SF_FORMTYPE(CURV);

		~BGSCurveForm() override;  // 00

		// members
		BSFloatCurve curve;  // 30
	};
	static_assert(sizeof(BGSCurveForm) == 0x78);
}
