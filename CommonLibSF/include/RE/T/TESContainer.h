#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class ContainerObject;

	class TESContainer : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESContainer);

		~TESContainer() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESContainer_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// members
		ContainerObject** containerObjects;     // 08
		std::uint32_t     numContainerObjects;  // 10
	};
	static_assert(sizeof(TESContainer) == 0x18);
}
