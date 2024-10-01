#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSAimAssistPoseData : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSAimAssistPoseData);
		SF_FORMTYPE(AAPD);

		struct AttachPoint
		{
			BSFixedString start;  // 00
			BSFixedString end;    // 08
			float         unk10;  // 10
			float         unk14;  // 14
		};
		static_assert(sizeof(AttachPoint) == 0x18);

		~BGSAimAssistPoseData() override;  // 00

		// members
		AttachPoint           attachPoint;  // 30
		BSTArray<AttachPoint> connections;  // 48
	};
	static_assert(sizeof(BGSAimAssistPoseData) == 0x60);
}
