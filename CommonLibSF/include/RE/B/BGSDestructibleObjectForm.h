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

		// members
		DestructibleObjectData* data;  // 08
	};
	static_assert(sizeof(BGSDestructibleObjectForm) == 0x10);
}
