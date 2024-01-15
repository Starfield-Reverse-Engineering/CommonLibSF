#pragma once

#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class TESImageSpaceModifier;

	class BGSPhotoModeFeature :
		public TESForm,     // 000
		public TESFullName  // 030
	{
	public:
		SF_RTTI_VTABLE(BGSPhotoModeFeature);
		SF_FORMTYPE(PMFT);

		enum class TYPE
		{
			kTextureOverlay,
			kFrame,
			kFilter
		};

		struct Feature
		{
			stl::enumeration<TYPE, std::uint8_t> type;     // 00
			float                                offsetX;  // 04
			float                                offsetY;  // 08
			float                                unk0C;    // 0C
			float                                unk10;    // 10
			float                                width;    // 14
			float                                height;   // 18
			float                                unk1C;    // 1C
		};
		static_assert(sizeof(Feature) == 0x20);

		~BGSPhotoModeFeature() override;  // 00

		// members
		TESCondition           conditions;  // 40
		TESImageSpaceModifier* imageSpace;  // 50
		TESTexture             texture;     // 58
		Feature                feature;     // 68
	};
	static_assert(sizeof(BGSPhotoModeFeature) == 0x88);
}
