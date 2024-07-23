#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class BGSAmbienceSet;
	class BGSGroundCover;
	class BGSLayeredMaterialSwap;
	class BGSMusicType;
	class BGSResourceGenerationData;
	class BGSTimeOfDayData;
	class TESClimate;
	class TESGlobal;
	class TESLandTexture;
	class TESWaterForm;

	namespace BGSSurface
	{
		class PatternStyle;
	}

	class BGSBiome :
		public TESForm,        // 00
		public TESFullName,    // 30
		public BGSKeywordForm  // 40
	{
	public:
		SF_RTTI_VTABLE(BGSBiome);
		SF_FORMTYPE(BIOM);

		struct LandData
		{
			TESLandTexture* landTexture;  // 00
			BGSGroundCover* groundCover;  // 08
		};
		static_assert(sizeof(LandData) == 0x10);

		struct BTPSData
		{
			float      unk00;    // 00
			float      unk04;    // 04
			float      unk08;    // 08
			float      unk0C;    // 0C
			float      unk10;    // 10
			float      unk14;    // 14
			float      unk18;    // 18
			float      unk1C;    // 1C
			TESTexture texture;  // 20
		};
		static_assert(sizeof(BTPSData) == 0x30);

		~BGSBiome() override;  // 00

		// members
		BGSEditorID                          formEditorID;            // 070
		LandData                             unk80[7];                // 080 - LNAM
		LandData                             unkF0[7];                // 0F0 - ANAM
		BTPSData                             unk160[7];               // 160 - BTPS
		std::uint64_t                        unk2B0;                  // 2B0
		float                                unk2B8;                  // 2B8
		float                                unk2BC;                  // 2BC
		std::uint32_t                        unk2C0;                  // 2C0
		float                                unk2C4;                  // 2C4
		std::uint32_t                        unk2C8;                  // 2C8
		float                                unk2CC;                  // 2CC
		TESTexture                           groundLayerNormal;       // 2D0
		std::uint64_t                        unk2E0;                  // 2E0
		std::uint32_t                        unk2E8;                  // 2E8
		std::uint32_t                        unk2EC;                  // 2EC
		BSTArray<void*>                      unk2F0;                  // 2F0
		BSTArray<BGSResourceGenerationData*> resourceGenerationData;  // 300
		BSTArray<void*>                      unk310;                  // 310
		BSTArray<BGSLayeredMaterialSwap*>    materialSwaps;           // 320
		std::uint64_t                        unk330;                  // 330
		std::uint64_t                        unk338;                  // 338
		std::uint64_t                        unk340;                  // 340
		std::uint64_t                        unk348;                  // 348
		std::uint64_t                        unk350;                  // 350
		std::uint64_t                        unk358;                  // 358
		std::uint64_t                        unk360;                  // 360
		std::uint64_t                        unk368;                  // 368
		std::uint64_t                        unk370;                  // 370
		std::uint64_t                        unk378;                  // 378
		std::uint64_t                        unk380;                  // 380
		std::uint64_t                        unk388;                  // 388
		TESClimate*                          climate;                 // 290
		TESWaterForm*                        water;                   // 398
		std::uint32_t                        unk3A0;                  // 3A0
		std::uint32_t                        unk3A4;                  // 3A4
		BGSBiome*                            unk3A8;                  // 3A8
		BGSAmbienceSet*                      ambienceSet;             // 3B0
		BGSMusicType*                        musicType;               // 3B8
		BGSTimeOfDayData*                    timeOfDayData;           // 3C0
		TESGlobal*                           unk3C8;                  // 3C8
		TESGlobal*                           unk3D0;                  // 3D0
		TESGlobal*                           unk3D8;                  // 3D8
		std::uint32_t                        color;                   // 3E0
		std::uint32_t                        biomeColor3;             // 3E4
		std::uint32_t                        biomeColor1;             // 3E8
		std::uint32_t                        biomeColor2;             // 3EC
		std::uint8_t                         unk3F0;                  // 3F0
		float                                unk3F4;                  // 3F4
		float                                unk3F8;                  // 3F8
		float                                unk3FC;                  // 3FC
		std::uint64_t                        unk400;                  // 400
		std::uint64_t                        unk408;                  // 408
		std::uint64_t                        unk410;                  // 410
		std::uint64_t                        unk418;                  // 418
		std::uint64_t                        unk420;                  // 420
		std::uint64_t                        unk428;                  // 428
		std::uint64_t                        unk430;                  // 430
		BSFixedString                        unk438;                  // 438
		std::uint8_t                         unk440;                  // 440
		BGSSurface::PatternStyle*            patternStyle;            // 448
		std::uint32_t                        unk450;                  // 450
		std::uint8_t                         unk454;                  // 454
	};
	static_assert(sizeof(BGSBiome) == 0x458);
}
