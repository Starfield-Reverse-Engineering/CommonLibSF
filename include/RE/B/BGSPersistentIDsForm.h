#pragma once

#include "RE/T/TESForm.h"

namespace RE::TESDataHandlerPersistentCreatedUtil
{
	class BGSPersistentIDsForm : public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESDataHandlerPersistentCreatedUtil__BGSPersistentIDsForm);
		SF_FORMTYPE(PERS);

		~BGSPersistentIDsForm() override;  // 00

		// members
		std::uint64_t unk30;  // 30
		std::uint64_t unk38;  // 38
	};
	static_assert(sizeof(BGSPersistentIDsForm) == 0x48);
}
