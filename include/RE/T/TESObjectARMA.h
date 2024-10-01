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
		public TESObject,          // 00
		public TESRaceForm,        // 48
		public BGSBipedObjectForm  // 58
	{
	public:
		SF_RTTI_VTABLE(TESObjectARMA);
		SF_FORMTYPE(ARMA);

		~TESObjectARMA() override;  // 00

		// members
		BGSEditorID          formEditorID;                         // 068
		OBJ_ARMA             data;                                 // 078
		BGSModelMaterialSwap bipedModel[SEXES::kTotal];            // 088
		BGSModelMaterialSwap bipedModelFacebones[SEXES::kTotal];   // 0D8
		BGSModelMaterialSwap unk128[SEXES::kTotal];                // 128
		TESModel             unk178[SEXES::kTotal];                // 178
		BGSMorphableObject*  unk1B8[SEXES::kTotal];                // 1B8
		BGSMorphableObject*  unk1C8[SEXES::kTotal];                // 1C8
		BGSTextureSet*       skinTextures[SEXES::kTotal];          // 1D8
		BGSListForm*         skinTextureSwapLists[SEXES::kTotal];  // 1E8
		BSTArray<void*>      unk1F8[SEXES::kTotal];                // 1F8
		std::uint64_t        unk218;                               // 218
		std::uint64_t        unk220;                               // 220
		BSTArray<TESRace*>   additionalRaces;                      // 228
		BGSBodyPartData*     bodyPartData;                         // 238
		BGSFootstepSet*      footstepSet;                          // 240
		BGSArtObject*        artObject;                            // 248
		AVMData              avmData;                              // 250
	};
	static_assert(sizeof(TESObjectARMA) == 0x280);
}
