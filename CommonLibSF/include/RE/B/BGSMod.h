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
				TES_RTTI_VTABLE(BGSMod__Template__Items);

				virtual ~Items();

				// add
				virtual void Unk_08();  // 08
				virtual void Unk_09();  // 09
				virtual void Unk_0A();  // 0A

				// members
				void* unk08;  // 08
				void* unk10;  // 10
				void* unk18;  // 18
			};
			static_assert(sizeof(Items) == 0x20);
		}
	}
}
