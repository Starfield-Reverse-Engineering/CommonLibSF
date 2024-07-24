#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class BGSEquipSlot;
	class TBO_InstanceData;

	class BGSEquipType : public BaseFormComponent
	{
	public:
		SF_RTTI(BGSEquipType);

		virtual ~BGSEquipType() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSEquipType_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// add
		[[nodiscard]] virtual BGSEquipSlot* GetEquipSlot(const TBO_InstanceData* a_data) const;  // 06
		virtual void                        SetEquipSlot(BGSEquipSlot* a_slot);                  // 07

		// members
		BGSEquipSlot* equipSlot;  // 08
	};
	static_assert(sizeof(BGSEquipType) == 0x10);
}
