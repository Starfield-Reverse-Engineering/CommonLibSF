#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESBoundObject;
	struct ContainerItemExtra;

	struct ContainerObject
	{
	public:
		SF_HEAP_REDEFINE_NEW(ContainerObject);

		// members
		std::int32_t        count;      // 00
		TESBoundObject*     obj;        // 08
		ContainerItemExtra* itemExtra;  // 10 - COED
	};
	static_assert(sizeof(ContainerObject) == 0x18);

	class TESContainer : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESContainer);

		~TESContainer() override;

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESContainer_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		void AddObjectToContainer(TESForm* a_owner, TESBoundObject* a_obj, std::int32_t a_count, ContainerItemExtra* a_itemExtra)
		{
			using func_t = decltype(&TESContainer::AddObjectToContainer);
			static REL::Relocation<func_t> func{ ID::TESContainer::AddObjectToContainer };
			return func(this, a_owner, a_obj, a_count, a_itemExtra);
		}

		// members
		BSTArray<ContainerObject> containerObjects;  // 08
	};
	static_assert(sizeof(TESContainer) == 0x18);
}
