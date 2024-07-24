#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	union SETTING_VALUE
	{
		float         f;
		std::uint32_t i;
	};
	static_assert(sizeof(SETTING_VALUE) == 0x4);

	class BGSShaderParticleGeometryData : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSShaderParticleGeometryData);
		SF_FORMTYPE(SPGD);

		~BGSShaderParticleGeometryData() override;  // 00

		// members
		BSTArray<SETTING_VALUE> data;             // 30
		BSFixedString           particleTexture;  // 40
	};
	static_assert(sizeof(BGSShaderParticleGeometryData) == 0x48);
}
