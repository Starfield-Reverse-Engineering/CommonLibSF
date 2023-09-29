#pragma once

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
		virtual void Unk_08();                                 // 08
		virtual void Unk_09();                                 // 09
		virtual void Unk_0A();                                 // 0A
	};
	static_assert(sizeof(BaseFormComponent) == 0x08);
}
