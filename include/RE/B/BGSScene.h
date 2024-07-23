#pragma once

#include "RE/I/IKeywordFormBase.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSScene :
		public TESForm,          // 00
		public IKeywordFormBase  // 30
	{
	public:
		SF_RTTI_VTABLE(BGSScene);
		SF_FORMTYPE(SCEN);

		//
	};
}
