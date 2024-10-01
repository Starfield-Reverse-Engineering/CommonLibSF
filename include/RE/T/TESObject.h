#pragma once

#include "RE/B/BGSSnapTemplateComponent.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class TESObject : public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESObject);

		~TESObject() override;

		// add
		virtual void Unk_62();                      // 62
		virtual void Unk_63();                      // 63
		virtual bool IsAutoCalc() const;            // 64
		virtual void SetAutoCalc(bool a_autoCalc);  // 65
		virtual void Unk_66();                      // 66
		virtual void Unk_67();                      // 67
		virtual bool IsMarker();                    // 68
		virtual void Unk_69();                      // 69
		virtual void Unk_6A();                      // 6A
		virtual void Unk_6B();                      // 6B

		// members
		BGSSnapTemplateComponent snapTemplate;  // 030
	};
	static_assert(sizeof(TESObject) == 0x50);
}
