#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class ContainerObject;

	class TESContainer : public BaseFormComponent
	{
	public:
		TES_RTTI_VTABLE(TESContainer);

		// add
		virtual void Unk_08();  // 08
		virtual void Unk_09();  // 09
		virtual void Unk_0A();  // 0A

		// members
		ContainerObject** containerObjects; // 08
		std::uint32_t     numContainerObjects; // 10
	};
	static_assert(sizeof(TESContainer) == 0x18);
}

