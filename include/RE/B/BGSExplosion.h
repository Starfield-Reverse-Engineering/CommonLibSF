#pragma once

#include "RE/B/BGSPreloadable.h"
#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple3.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESImageSpaceModifiableForm.h"
#include "RE/T/TESModel.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class BGSConditionForm;
	class BGSImpactDataSet;
	class BGSProjectile;
	class TESObjectLIGH;

	struct BGSExplosionData  // DATA
	{
		float                                                                      unk00;               // 00
		std::uint32_t                                                              unk04;               // 04
		std::uint32_t                                                              unk08;               // 08
		std::uint32_t                                                              unk0C;               // 0C
		BGSImpactDataSet*                                                          impactDataSet;       // 10
		BGSProjectile*                                                             spawnProjectile;     // 18
		TESBoundObject*                                                            impactPlacedObject;  // 20
		TESObjectLIGH*                                                             light;               // 28
		BGSConditionForm*                                                          conditions;          // 30
		BGSAudio::WwiseSoundHook                                                   sound;               // 38
		BSTArray<BSTTuple3<TESForm*, TESForm*, BGSTypedFormValuePair::SharedVal>>* damageTypes;         // 68
		std::uint32_t                                                              unk70;               // 70
		std::uint32_t                                                              unk74;               // 74
		std::uint32_t                                                              unk78;               // 78
		std::uint32_t                                                              unk7C;               // 7C
		std::uint32_t                                                              unk80;               // 80
		std::uint32_t                                                              unk84;               // 84
		std::uint32_t                                                              unk88;               // 88
		float                                                                      unk8C;               // 8C
		std::uint32_t                                                              unk90;               // 90
		std::uint32_t                                                              unk94;               // 94
		std::uint32_t                                                              unk98;               // 98
		std::uint32_t                                                              unk9C;               // 9C
		std::uint32_t                                                              unkA0;               // A0
	};
	static_assert(sizeof(BGSExplosionData) == 0xA8);

	class BGSExplosion :
		public TESBoundObject,              // 000
		public TESFullName,                 // 0E0
		public TESModel,                    // 0F0
		public TESEnchantableForm,          // 110
		public BGSPreloadable,              // 128
		public TESImageSpaceModifiableForm  // 130
	{
	public:
		SF_RTTI_VTABLE(BGSExplosion);
		SF_FORMTYPE(EXPL);

		~BGSExplosion() override;  // 00

		// members
		BGSExplosionData data;  // 140
	};
	static_assert(sizeof(BGSExplosion) == 0x1F0);
}
