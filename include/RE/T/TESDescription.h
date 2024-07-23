#pragma once

#include "RE/B/BGSLocalizedStringDL.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESDescription : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESDescription);

		~TESDescription() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESDescription_Component"; }
		void                 InitializeDataComponent() override;     // 02

		// members
		std::uint32_t        fileOffset;       // 08
		std::uint32_t        chunkOffset;      // 0C
		BGSLocalizedStringDL descriptionText;  // 10
	};
	static_assert(sizeof(TESDescription) == 0x18);
}
