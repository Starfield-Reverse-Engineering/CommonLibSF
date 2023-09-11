#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSSnapTemplateComponent : public BaseFormComponent
	{
	public:
		TES_RTTI_VTABLE(BGSSnapTemplateComponent);

		virtual ~BGSSnapTemplateComponent();

		// add
		virtual void Unk_08();  // 08
		virtual void Unk_09();  // 09
		virtual void Unk_0A();  // 0A

		// members
		std::uint64_t unk08;  // 08
		std::uint64_t unk10;  // 10
	};
	static_assert(sizeof(BGSSnapTemplateComponent) == 0x18);
}
