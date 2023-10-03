#pragma once

#include "RE/B/BaseFormComponent.h"
#include "RE/T/TESObjectARMO.h"

namespace RE
{
	class BGSSkinForm : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSSkinForm);

		~BGSSkinForm() override;

		// members
		TESObjectARMO* formSkin;  // 08
	};
	static_assert(sizeof(BGSSkinForm) == 0x10);
}
