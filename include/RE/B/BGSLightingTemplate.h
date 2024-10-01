#pragma once

#include "RE/B/BGSDirectionalAmbientLightingColors.h"
#include "RE/I/InteriorData.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSLightingTemplate : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSLightingTemplate);
		SF_FORMTYPE(LGTM);

		~BGSLightingTemplate() override;  // 00

		// members
		INTERIOR_DATA                       data;                              // 30
		BGSDirectionalAmbientLightingColors directionalAmbientLightingColors;  // A8
	};
	static_assert(sizeof(BGSLightingTemplate) == 0xC8);
}
