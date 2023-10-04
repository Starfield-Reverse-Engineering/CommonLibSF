#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	struct DestructibleObjectData
	{
	};

	class BGSDestructibleObjectForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSDestructibleObjectForm);

		~BGSDestructibleObjectForm() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSDestructibleObject_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		DestructibleObjectData* data;  // 08
	};
	static_assert(sizeof(BGSDestructibleObjectForm) == 0x10);
}
