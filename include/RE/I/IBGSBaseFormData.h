#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class TESFile;
	class TESForm;

	class IBGSBaseFormData
	{
	public:
		SF_RTTI_VTABLE(IBGSBaseFormData);

		virtual ~IBGSBaseFormData();  // 00

		// add
		virtual void                 InitializeFormData();                                                 // 01
		virtual void                 InitData();                                                           // 02
		virtual void                 Load(std::uint64_t a_arg2, std::uint32_t a_id, TESFile* a_file) = 0;  // 03
		virtual bool                 Compare(IBGSBaseFormData* a_data) = 0;                                // 04
		virtual void                 Copy(IBGSBaseFormData* a_data, TESForm* a_owner) = 0;                 // 05
		virtual const BSFixedString& GetFormDataType() = 0;                                                // 06
	};
	static_assert(sizeof(IBGSBaseFormData) == 0x8);
}
