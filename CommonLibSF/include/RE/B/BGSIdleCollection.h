#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESIdleForm;

	class BGSIdleCollection : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSIdleCollection);

		~BGSIdleCollection() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSIdleCollection_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BSTArray<TESIdleForm*> idles;              // 08
		float                  timerCheckForIdle;  // 18
		std::uint8_t           idleFlags;          // 1C
	};
	static_assert(sizeof(BGSIdleCollection) == 0x20);
}
