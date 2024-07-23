#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class TESForm;

	class BaseFormComponent
	{
	public:
		virtual ~BaseFormComponent();  // 00

		// add
		virtual const BSFixedString& GetFormComponentType() const = 0;                            // 01
		virtual void                 InitializeDataComponent() = 0;                               // 02
		virtual void                 ClearDataComponent();                                        // 03
		virtual void                 CopyComponent(BaseFormComponent* a_copy);                    // 04
		virtual void                 CopyComponent(BaseFormComponent* a_copy, TESForm* a_owner);  // 05
		virtual void                 Unk_06();                                                    // 06
		virtual void                 Unk_07();                                                    // 07
		virtual void                 Unk_08();                                                    // 08
		virtual void                 Unk_09();                                                    // 09
		virtual void                 Unk_0A();                                                    // 0A
	};
	static_assert(sizeof(BaseFormComponent) == 0x08);
}
