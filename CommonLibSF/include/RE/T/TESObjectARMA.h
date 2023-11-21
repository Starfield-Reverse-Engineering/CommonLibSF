#pragma once

#include "RE/A/AVMData.h"
#include "RE/B/BGSBipedObjectForm.h"
#include "RE/B/BGSEditorID.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSSnapTemplateComponent.h"
#include "RE/B/BSTArray.h"
#include "RE/S/Sexes.h"
#include "RE/T/TESObject.h"
#include "RE/T/TESRaceForm.h"

namespace RE
{
	class BGSArtObject;
	class BGSBodyPartData;
	class BGSFootstepSet;
	class BGSListForm;
	class BGSMorphableObject;
	class BGSTextureSet;

	struct OBJ_ARMA  // DNAM
	{
		std::int8_t priorities[SEXES::kTotal];  // 0
		std::int8_t modelRange[SEXES::kTotal];  // 2
		std::int8_t unused[SEXES::kTotal];      // 4
		std::int8_t detectionSoundValue;        // 6
		float       weaponAdjust;               // 8
	};
	static_assert(sizeof(OBJ_ARMA) == 0xC);

	class TESObjectARMA :
		public TESObject,                 // 00
		public BGSSnapTemplateComponent,  // 38
		public TESRaceForm,               // 50
		public BGSBipedObjectForm         // 60
	{
	public:
		SF_RTTI_VTABLE(TESObjectARMA);
		SF_FORMTYPE(ARMA);

		~TESObjectARMA() override;  // 00

		// members
		BGSEditorID          formEditorID;                         // 070
		OBJ_ARMA             data;                                 // 080
		BGSModelMaterialSwap bipedModel[SEXES::kTotal];            // 090
		BGSModelMaterialSwap bipedModelFacebones[SEXES::kTotal];   // 0E0
		BGSModelMaterialSwap unk130[SEXES::kTotal];                // 130
		TESModel             unk180[SEXES::kTotal];                // 180
		BGSMorphableObject*  unk1C0[SEXES::kTotal];                // 1C0
		BGSMorphableObject*  unk1D0[SEXES::kTotal];                // 1D0
		BGSTextureSet*       skinTextures[SEXES::kTotal];          // 1E0
		BGSListForm*         skinTextureSwapLists[SEXES::kTotal];  // 1F0
		BSTArray<void*>      unk200[SEXES::kTotal];                // 200
		std::uint64_t        unk220;                               // 220
		std::uint64_t        unk228;                               // 228
		BSTArray<TESRace*>   additionalRaces;                      // 230
		BGSBodyPartData*     bodyPartData;                         // 240
		BGSFootstepSet*      footstepSet;                          // 248
		BGSArtObject*        artObject;                            // 250
		AVMData              avmData;                              // 258
	};
	static_assert(sizeof(TESObjectARMA) == 0x280);
}
