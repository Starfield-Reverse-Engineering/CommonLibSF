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
		TES_RTTI_VTABLE(BGSDestructibleObjectForm);

		// members
		DestructibleObjectData* data;  // 08
	};
	static_assert(sizeof(BGSDestructibleObjectForm) == 0x10);
}

