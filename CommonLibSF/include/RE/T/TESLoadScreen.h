#pragma once

#include "RE/B/BGSLocalizedString.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class BGSTransform;
	class TESBoundObject;

	class TESLoadScreen : public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESLoadScreen);
		SF_FORMTYPE(LSCR);

		struct LoadNIFData
		{
			TESModel        model;      // 00
			TESBoundObject* loadNif;    // 20
			BGSTransform*   transform;  // 28
			std::uint64_t   unk30;      // 30
			std::uint64_t   unk38;      // 38
		};
		static_assert(sizeof(LoadNIFData) == 0x40);

		~TESLoadScreen() override;  // 00

		// members
		TESCondition       conditions;   // 30
		TESTexture         loadscreen;   // 40 - ICON
		LoadNIFData*       loadNIFData;  // 50
		BGSLocalizedString loadingText;  // 58
	};
	static_assert(sizeof(TESLoadScreen) == 0x60);
}
