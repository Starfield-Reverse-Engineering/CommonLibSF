#pragma once

#include "RE/T/TESModel.h"

namespace RE
{
	class BGSModelMaterialSwap : public TESModel
	{
	public:
		SF_RTTI_VTABLE(BGSModelMaterialSwap);

		~BGSModelMaterialSwap() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString&  GetFormComponentType() const override;  // 01 - { return "BGSModelMaterialSwap_Component"; }
		void                  InitializeDataComponent() override;     // 02
		BGSModelMaterialSwap* GetAsModelMaterialSwap() override;      // 0E - { return this; }

		// members
		float         colorRemappingIndex;  // 20
		std::uint32_t pad24;                // 24
	};
	static_assert(sizeof(BGSModelMaterialSwap) == 0x28);
}
