#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSPropertySheet : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(BGSPropertySheet);

		// members
		std::uint64_t /* BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* */ unk08;
	};
	static_assert(sizeof(BGSPropertySheet) == 0x10);
}
