#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class ActorValueInfo;
	class MagicItem;

	class BGSDamageType :
		public TESForm,     // 00
		public TESFullName  // 30
	{
	public:
		SF_RTTI_VTABLE(BGSDamageType);
		SF_FORMTYPE(DMGT);

		~BGSDamageType() override;  // 00

		struct Data
		{
		public:
			// members
			ActorValueInfo* resistance;  // 00
			MagicItem*      spell;       // 08
		};
		static_assert(sizeof(Data) == 0x10);

		// members
		Data data;  // 40
	};
	static_assert(sizeof(BGSDamageType) == 0x58);
}
