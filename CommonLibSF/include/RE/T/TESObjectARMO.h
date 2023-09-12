#pragma once

#include "RE/T/TESBoundObject.h"

namespace RE
{
	class TESObjectARMO :
		public TESBoundObject
	{
	public:
		SF_RTTI_VTABLE(TESObjectARMO);
		SF_FORMTYPE(ARMO);
	};
}
