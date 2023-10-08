#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESBoundObject;
	struct ContainerItemExtra;

	struct ContainerObject
	{
	public:
		// members
		std::int32_t        count;      // 00
		TESBoundObject*     obj;        // 08
		ContainerItemExtra* itemExtra;  // 10 - COED
	};
	static_assert(sizeof(ContainerObject) == 0x18);

	class TESContainer : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESContainer);

		~TESContainer() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESContainer_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		BSTArray<ContainerObject> containerObjects;  // 08
	};
	static_assert(sizeof(TESContainer) == 0x18);
}
