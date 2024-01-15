#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	class Hazard : public TESObjectREFR
	{
	public:
		SF_RTTI_VTABLE(Hazard);
		SF_FORMTYPE(PHZD);

		~Hazard() override;  // 00

		// members
		BSTArray<std::uint32_t>        unkF0;        // 0F0 - TESPointerHandles
		mutable BSNonReentrantSpinLock lock;         // 100
		void*                          unk108;       // 108 - smart pointer
		std::uint32_t                  ownerActor;   // 110 - TESPointerHandle
		std::uint32_t                  unk114;       // 114
		void*                          unk118;       // 118 - smart pointer
		float                          age;          // 120
		float                          lifetime;     // 124
		float                          targetTimer;  // 128
		float                          radius;       // 12C
		float                          magnitude;    // 130
		std::uint32_t                  flags;        // 134
	};
	static_assert(sizeof(Hazard) == 0x140);
}
