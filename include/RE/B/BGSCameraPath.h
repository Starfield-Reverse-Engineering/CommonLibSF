#pragma once

#include "RE/B/BSTArray.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSCameraPath : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSCameraPath);
		SF_FORMTYPE(CPTH);

		~BGSCameraPath() override;  // 00

		// members
		TESCondition    conditions;  // 30
		std::uint8_t    unk40;       // 40
		BSTArray<void*> unk48;       // 48
		BSTArray<void*> unk58;       // 58
		BGSCameraPath*  parentPath;  // 68
		BGSCameraPath*  prevPath;    // 70
	};
	static_assert(sizeof(BGSCameraPath) == 0x80);
}
