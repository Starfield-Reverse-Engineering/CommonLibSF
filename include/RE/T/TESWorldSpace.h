#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class BGSAmbienceSet;
	class BGSBiome;
	class BGSLightingTemplate;
	class BGSLocation;
	class BGSMusicType;
	class BGSTerrainManager;
	class TESObjectCELL;
	class TESWaterForm;

	struct WorldSpaceReleasedEvent;

	class TESWorldSpace :
		public TESForm,                                 // 00
		public TESFullName,                             // 30
		public TESTexture,                              // 38
		public BSTEventSource<WorldSpaceReleasedEvent>  // 50
	{
	public:
		SF_RTTI_VTABLE(TESWorldSpace);
		SF_FORMTYPE(WRLD);

		~TESWorldSpace() override;  // 00

		[[nodiscard]] BGSLocation* GetLocationFromCoordinates(const NiPoint3A& a_coordinates)
		{
			using func_t = decltype(&TESWorldSpace::GetLocationFromCoordinates);
			static REL::Relocation<func_t> func{ ID::TESWorldSpace::GetLocationFromCoordinates };
			return func(this, a_coordinates);
		}

		// members
		BGSEditorID                                           formEditorID;        // 078
		std::uint64_t                                         unk088;              // 088
		std::uint64_t                                         unk090;              // 090
		std::uint64_t                                         unk098;              // 098
		std::uint64_t                                         unk0A0;              // 0A0
		std::uint64_t                                         unk0A8;              // 0A8
		std::uint64_t                                         unk0B0;              // 0B0
		std::uint64_t                                         unk0B8;              // 0B8
		BSTArray<void*>                                       unk0C0;              // 0C0
		NiPointer<TESObjectCELL>                              unk0D0;              // 0D0 - persistent cell?
		BSTSmartPointer<BGSTerrainManager>                    terrainManager;      // 0D8
		std::uint64_t                                         unk0E0;              // 0E0
		std::uint64_t                                         unk0E8;              // 0E8
		std::uint64_t                                         unk0F0;              // 0F0
		std::uint64_t                                         unk0F8;              // 0F8
		std::uint64_t                                         unk100;              // 100
		std::uint64_t                                         unk108;              // 108
		std::uint64_t                                         unk110;              // 110
		std::uint64_t                                         unk118;              // 118
		std::uint64_t                                         unk120;              // 120
		std::uint64_t                                         unk128;              // 128
		std::uint64_t                                         unk130;              // 130
		std::uint64_t                                         unk138;              // 138
		std::uint64_t                                         unk140;              // 140
		std::uint64_t                                         unk148;              // 148
		std::uint64_t                                         unk150;              // 150
		std::uint64_t                                         unk158;              // 158
		std::uint64_t                                         unk160;              // 160
		std::uint64_t                                         unk168;              // 168
		std::uint64_t                                         unk170;              // 170
		std::uint64_t                                         unk178;              // 178
		std::uint64_t                                         unk180;              // 180
		std::uint64_t                                         unk188;              // 188
		std::uint64_t                                         unk190;              // 190
		std::uint64_t                                         unk198;              // 198
		std::uint64_t                                         unk1A0;              // 1A0
		std::uint64_t                                         unk1A8;              // 1A8
		std::uint64_t                                         unk1B0;              // 1B0
		std::uint64_t                                         unk1B8;              // 1B8
		std::uint64_t                                         unk1C0;              // 1C0
		std::uint64_t                                         unk1C8;              // 1C8
		NiPointer<TESObjectCELL>                              unk1D0;              // 1D0 - persistent cell?
		BSTArray<NiPointer<TESForm>>                          unk1D8;              // 1D8
		BSTSmartPointer<TESWorldSpace, TESFormExternalPolicy> parentWorld;         // 1E8
		BGSLightingTemplate*                                  lightingTemplate;    // 1F0
		TESWaterForm*                                         worldWater;          // 1F8
		TESWaterForm*                                         lodWater;            // 200
		std::uint64_t                                         unk208;              // 208
		BSFixedString                                         unk210;              // 210
		std::uint64_t                                         unk218;              // 218
		std::uint64_t                                         unk220;              // 220
		std::uint64_t                                         unk228;              // 228
		std::uint64_t                                         unk230;              // 230
		std::uint64_t                                         unk238;              // 238
		BGSMusicType*                                         musicType;           // 240
		BGSAmbienceSet*                                       ambienceSet;         // 248
		std::uint64_t                                         unk250;              // 250
		std::uint64_t                                         unk258;              // 258
		std::uint64_t                                         unk260;              // 260
		std::uint64_t                                         unk268;              // 268
		std::uint64_t                                         unk270;              // 270
		std::uint64_t                                         unk278;              // 278
		std::uint64_t                                         unk280;              // 280
		std::uint64_t                                         unk288;              // 288
		std::uint64_t                                         unk290;              // 290
		float                                                 defaultLandHeight;   // 298
		float                                                 defaultWaterHeight;  // 29C
		float                                                 unk2A0;              // 2A0
		std::uint32_t                                         unk2A4;              // 2A4
		BSTSmartPointer<BGSLocation, TESFormExternalPolicy>   location;            // 2A8
		BGSBiome*                                             biome;               // 2B0
		TESTexture                                            unk2B8;              // 2B8
		TESTexture                                            unk2C8;              // 2C8
		std::uint64_t                                         unk2D8;              // 2D8
		std::uint64_t                                         unk2E0;              // 2E0
		std::uint64_t                                         unk2E8;              // 2E8
		std::uint64_t                                         unk2F0;              // 2F0
		std::uint64_t                                         unk2F8;              // 2F8
		std::uint64_t                                         unk300;              // 300
		std::uint64_t                                         unk308;              // 308
		std::uint64_t                                         unk310;              // 310
		std::uint64_t                                         unk318;              // 318
		std::uint64_t                                         unk320;              // 320
		std::uint64_t                                         unk328;              // 328
		std::uint64_t                                         unk330;              // 330
		std::uint64_t                                         unk338;              // 338
		std::uint64_t                                         unk340;              // 340
		std::uint64_t                                         unk348;              // 348
		std::uint64_t                                         unk350;              // 350
		std::uint64_t                                         unk358;              // 358
		std::uint64_t                                         unk360;              // 360
		std::uint64_t                                         unk368;              // 368
		std::uint64_t                                         unk370;              // 370
		std::uint64_t                                         unk378;              // 378
		TESWorldSpace*                                        unk380;              // 380
		std::uint64_t                                         unk388;              // 388
	};
	static_assert(sizeof(TESWorldSpace) == 0x398);
}
