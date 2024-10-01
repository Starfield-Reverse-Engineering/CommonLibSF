#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/T/TESForm.h"

namespace RE
{
	namespace BSLensFlareRender
	{
		class BSLensFlareSpriteRenderData;

		class BSLensFlareRenderData
		{
		public:
			// members
			float                                                  unk00;        // 00
			float                                                  unk04;        // 04
			float                                                  unk08;        // 08
			float                                                  unk0C;        // 0C
			float                                                  unk10;        // 10
			std::uint8_t                                           unk14;        // 14
			BSTArray<BSTSmartPointer<BSLensFlareSpriteRenderData>> lensSprites;  // 18
			std::uint64_t                                          unk28;        // 28
			float                                                  unk30;        // 30
		};
		static_assert(sizeof(BSLensFlareRenderData) == 0x38);
	}

	class BGSLensFlare :
		public TESForm,                                  // 00
		public BSLensFlareRender::BSLensFlareRenderData  // 30
	{
	public:
		SF_RTTI_VTABLE(BGSLensFlare);
		SF_FORMTYPE(LENS);

		~BGSLensFlare() override;  // 00
	};
	static_assert(sizeof(BGSLensFlare) == 0x70);
}
