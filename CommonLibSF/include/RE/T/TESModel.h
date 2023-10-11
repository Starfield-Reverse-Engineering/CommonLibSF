#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSModelMaterialSwap;

	class TESModel : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESModel);

		~TESModel() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESModel_Component"; }
		void                 InitializeDataComponent() override;     // 02

		// add
		virtual void                  Unk_0B();                  // 0B
		virtual void                  Unk_0C();                  // 0C
		virtual BGSModelMaterialSwap* GetAsModelMaterialSwap();  // 0E

		// members
		BSFixedString model;  // 08
		std::uint64_t unk10;  // 10
		std::uint32_t unk18;  // 18
		std::uint16_t unk1C;  // 1C
		std::uint16_t pad1E;  // 1E
	};
	static_assert(sizeof(TESModel) == 0x20);
}
