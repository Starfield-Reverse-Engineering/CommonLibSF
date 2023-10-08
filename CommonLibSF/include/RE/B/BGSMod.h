#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	namespace BGSMod
	{
		namespace Template
		{
			class Items : public BaseFormComponent
			{
			public:
				SF_RTTI_VTABLE(BGSMod__Template__Items);

				virtual ~Items() override;

				// override (BaseFormComponent)
				const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSMod_Template_Component"; }
				void                 InitializeDataComponent() override;     // 02

				// add
				virtual void Unk_0B();  // 0B
				virtual void Unk_0C();  // 0C
				virtual void Unk_0D();  // 0D

				// members
				BSTArray<void*> unk08;  // 08
				BSFixedString   unk18;  // 18
			};
			static_assert(sizeof(Items) == 0x20);
		}
	}
}
