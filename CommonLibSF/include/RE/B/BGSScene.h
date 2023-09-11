#pragma once

#include "RE/T/TESForm.h"
#include "RE/I/IKeywordFormBase.h"

namespace RE
{
	class BGSScene :
		public TESForm,          // 00
		public IKeywordFormBase  // 20
	{
	public:
		TES_RTTI_VTABLE(BGSScene);

		// 
	};
}

