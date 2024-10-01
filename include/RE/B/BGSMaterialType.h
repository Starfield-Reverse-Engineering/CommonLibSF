#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/N/NiColor.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class BGSImpactDataSet;

	class BGSMaterialType : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSMaterialType);
		SF_FORMTYPE(MATT);

		enum class FLAG
		{
			kNone = 0,
			kStairs = 1 << 0,
			kArrowsStick = 1 << 1,
			kCanTunnel = 1 << 2
		};

		~BGSMaterialType() override;  // 00

		// members
		TESModel                          breakableFXModel;    // 30
		BGSMaterialType*                  parentType;          // 50
		BGSImpactDataSet*                 havokImpactDataSet;  // 58
		BSFixedString                     materialName;        // 60
		std::uint32_t                     materialID;          // 68
		NiColor                           materialColor;       // 6C
		float                             buoyancy;            // 78
		REX::EnumSet<FLAG, std::uint32_t> flags;               // 7C
	};
	static_assert(sizeof(BGSMaterialType) == 0x88);
}
