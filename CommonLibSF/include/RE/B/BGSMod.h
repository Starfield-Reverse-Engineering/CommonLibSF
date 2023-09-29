#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	namespace BGSMod
	{
		namespace Template
		{
			class Items :
				public BaseFormComponent  // 00
			{
			public:
				SF_RTTI_VTABLE(BGSMod__Template__Items);

				virtual ~Items();

				// add
				virtual void Unk_0B();  // 0B
				virtual void Unk_0C();  // 0C
				virtual void Unk_0D();  // 0D

				// members
				void* unk08;  // 08
				void* unk10;  // 10
				void* unk18;  // 18
			};
			static_assert(sizeof(Items) == 0x20);
		}
	}
}
