#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class TESHandleForm :
		public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESHandleForm);

		~TESHandleForm() override;  // 00
	};
	static_assert(sizeof(TESHandleForm) == 0x38);
}
