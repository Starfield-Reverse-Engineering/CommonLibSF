#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/N/NiObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiTimeController;

	class __declspec(novtable) NiObjectNET :
		public NiObject
	{
	public:
		SF_RTTI_VTABLE(NiObjectNET);

		virtual ~NiObjectNET() = default;

		// members
		BSFixedString               name;        // 010
		NiPointer<NiTimeController> controller;  // 018
		void*                       unk020;      // 020 - NiExtraDataContainer*
		void*                       unk028;      // 028
		void*                       unk030;      // 030
	};
	static_assert(sizeof(NiObjectNET) == 0x38);
	static_assert(offsetof(NiObjectNET, name) == 0x10);
	static_assert(offsetof(NiObjectNET, controller) == 0x18);
}
