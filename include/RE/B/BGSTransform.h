#pragma once

#include "RE/N/NiPoint3.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSTransform : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSTransform);
		SF_FORMTYPE(TRNS);

		struct TransformData
		{
		public:
			// members
			NiPoint3 position;  // 00
			NiPoint3 rotation;  // 0C
			float    scale;     // 18
			float    minZoom;   // 1C
			float    maxZoom;   // 20
		};
		static_assert(sizeof(TransformData) == 0x24);

		~BGSTransform() override;  // 00

		// members
		TransformData data;   // 30
		std::uint8_t  unk54;  // 54
	};
	static_assert(sizeof(BGSTransform) == 0x58);
}
