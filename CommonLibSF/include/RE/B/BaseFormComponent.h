#pragma once

#include "RE/T/TESFormRefCount.h"

namespace RE
{
	class BaseFormComponent
	{
	public:
		virtual ~BaseFormComponent();  // 00

		// add
		virtual void InitializeDataComponent();                // 01
		virtual void ClearDataComponent();                     // 02
		virtual void CopyComponent(BaseFormComponent* a_rhs);  // 03 - { return; }
		virtual void Unk_04();                                 // 04
		virtual void Unk_05();                                 // 05
		virtual void Unk_06();                                 // 06
		virtual void Unk_07();                                 // 07
	};
	static_assert(sizeof(BaseFormComponent) == 0x08);
}
