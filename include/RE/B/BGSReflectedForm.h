#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class BGSReflectedForm : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSReflectedForm);

		~BGSReflectedForm() override;  // 00

		// add
		virtual void Unk_62();  // 62
		virtual void Unk_63();  // 63
		virtual void Unk_64();  // 64
		virtual void Unk_65();  // 65
		virtual void Unk_66();  // 66
		virtual void Unk_67();  // 67
		virtual void Unk_68();  // 68
		virtual void Unk_69();  // 69
		virtual void Unk_6A();  // 6A
		virtual void Unk_6B();  // 6B
	};
	static_assert(sizeof(BGSReflectedForm) == 0x38);
}
