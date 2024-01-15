#pragma once

#include "RE/A/ActorValues.h"
#include "RE/B/BGSBodyPartDefs.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/B/BSFixedString.h"
#include "RE/N/NiPoint3.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class ActorValueInfo;
	class BGSArtObject;
	class BGSDebris;
	class BGSExplosion;
	class BGSImpactDataSet;
	class BGSMaterialType;

	class BGSBodyPart
	{
	public:
		// members
		float                                                      unk00;                   // 00
		float                                                      unk04;                   // 04
		std::uint8_t                                               flags;                   // 08
		stl::enumeration<BGSBodyPartDefs::LIMB_ENUM, std::uint8_t> limbEnum;                // 09
		std::uint8_t                                               unk0A;                   // 0A
		std::uint16_t                                              unk0C;                   // 0C
		BGSDebris*                                                 onCrippleDebris;         // 10
		BGSExplosion*                                              onCrippleExplosion;      // 18
		BGSImpactDataSet*                                          onCrippleImpactDataSet;  // 20
		ActorValueInfo*                                            actorValue;              // 28
		BGSArtObject*                                              onCrippleArt;            // 30
		BGSMaterialType*                                           goreEffectsMaterial;     // 38
		BGSMaterialType*                                           onCrippleMaterial;       // 40
		BGSBodyPartDefs::HitReactionData                           hitReactionData;         // 48
		BSFixedString                                              unk70;                   // 70
		BSFixedString                                              unk78;                   // 78
		BSFixedString                                              unk80;                   // 80
		BSFixedStringCS                                            unk88;                   // 88
		BSFixedString                                              unk90;                   // 90
	};
	static_assert(sizeof(BGSBodyPart) == 0x98);

	class BGSBodyPartData :
		public TESForm,        // 00
		public TESModel,       // 30
		public BGSPreloadable  // 50
	{
	public:
		SF_RTTI_VTABLE(BGSBodyPartData);
		SF_FORMTYPE(BPTD);

		~BGSBodyPartData() override;  // 00

		// members
		BGSBodyPart*                     parts[BGSBodyPartDefs::LIMB_ENUM::kTotal];  // 058
		BGSBodyPartDefs::HitReactionData defaultHitReactionData;                     // 128
	};
	static_assert(sizeof(BGSBodyPartData) == 0x150);
}
