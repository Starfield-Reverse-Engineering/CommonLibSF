#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESBoundObject;

	class BGSMenuDisplayObject : public BaseFormComponent
	{
	public:
		SF_RTTI(BGSMenuDisplayObject);

		virtual ~BGSMenuDisplayObject() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSMenuDisplayObject_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		TESBoundObject* menuObject;  // 08
	};
	static_assert(sizeof(BGSMenuDisplayObject) == 0x10);
}
