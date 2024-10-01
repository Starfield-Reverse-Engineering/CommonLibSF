#pragma once

#include "RE/T/TESBoundObject.h"

namespace RE
{
	class BGSAudioOcclusionPrimitive : public TESBoundObject
	{
	public:
		SF_RTTI_VTABLE(BGSAudioOcclusionPrimitive);
		SF_FORMTYPE(AOPF);

		~BGSAudioOcclusionPrimitive() override;  // 00

		// members
		float unkE0;  // E0
		float unkE4;  // E4
	};
	static_assert(sizeof(BGSAudioOcclusionPrimitive) == 0xF0);
}
