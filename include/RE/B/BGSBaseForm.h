#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class BGSBaseForm :
		public TESForm  // 00
	{
	public:
		SF_RTTI(BGSBaseForm);

		~BGSBaseForm() override;  // 00
	};
	static_assert(sizeof(BGSBaseForm) == 0x38);

	template <class T, FormType>
	class BGSBaseFormT :
		public BGSBaseForm  // 00
	{
	public:
		// members
		T* ptr;   // 30
		T  data;  // 38
	};
}
