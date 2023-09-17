#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class ContainerObject;

	class TESContainer : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESContainer);

		// members
		ContainerObject** containerObjects;     // 08
		std::uint32_t     numContainerObjects;  // 10
	};
	static_assert(sizeof(TESContainer) == 0x18);
}
