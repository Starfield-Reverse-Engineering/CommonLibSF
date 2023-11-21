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
		float unk118;  // 118
		float unk11C;  // 11C
	};
	static_assert(sizeof(BGSAudioOcclusionPrimitive) == 0x120);
}
