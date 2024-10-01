#pragma once

#include "RE/B/BGSReflectedForm.h"
#include "RE/B/BSBlendable.h"
#include "RE/B/BSTArray.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class ParticleSystemDefine;

	class BGSParticleSystemDefineCollection : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSParticleSystemDefineCollection);
		SF_FORMTYPE(PSDC);

		~BGSParticleSystemDefineCollection() override;  // 00

		// members
		std::vector<ParticleSystemDefine*> defines;  // 30
	};
	static_assert(sizeof(BGSParticleSystemDefineCollection) == 0x50);
}
