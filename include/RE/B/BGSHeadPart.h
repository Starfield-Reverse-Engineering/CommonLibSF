#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESModelTri.h"

namespace RE
{
	class BGSMorphableObject;
	class BGSListForm;
	class BGSTextureSet;

	class BGSHeadPart :
		public TESForm,              // 000
		public TESFullName,          // 030
		public BGSModelMaterialSwap  // 040
	{
	public:
		SF_RTTI_VTABLE(BGSHeadPart);
		SF_FORMTYPE(HDPT);

		enum class HeadPartType
		{
			kMisc,
			kFace,
			kEyeRight,
			kHair,
			kFacialHair,
			kScar,
			kEyebrows,
			kJewelry,
			kMeatcaps,
			kTeeth,
			kHeadRear,
			kExtraHair,
			kEyeLeft,
			kEyelashes,
			kCreatureHead,
			kCreatureTorso,
			kCreatureArms,
			kCreatureLegs,
			kCreatureTail,
			kCreatureWings
		};

		// members
		BGSEditorID                            formEditorID;       // 068
		TESModel                               chargenModel;       // 078
		TESModelTri                            morphs[3];          // 098
		TESCondition                           chargenConditions;  // 0F8
		BSTArray<BGSHeadPart*>                 extraParts;         // 108
		BGSMorphableObject*                    morphableObject;    // 118
		BGSTextureSet*                         textureSet;         // 120
		BGSListForm*                           validRaces;         // 128
		BSFixedString                          colorMapping;       // 130
		BSFixedString                          mask;               // 138
		REX::Enum<HeadPartType, std::uint32_t> type;               // 140
		std::uint32_t                          unk144;             // 144
	};
	static_assert(sizeof(BGSHeadPart) == 0x150);
}
