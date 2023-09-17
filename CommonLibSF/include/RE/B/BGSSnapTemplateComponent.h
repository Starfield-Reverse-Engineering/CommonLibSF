#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSSnapTemplateComponent : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSSnapTemplateComponent);

		virtual ~BGSSnapTemplateComponent();

		// members
		std::uint64_t unk08;  // 08
		std::uint64_t unk10;  // 10
	};
	static_assert(sizeof(BGSSnapTemplateComponent) == 0x18);
}
