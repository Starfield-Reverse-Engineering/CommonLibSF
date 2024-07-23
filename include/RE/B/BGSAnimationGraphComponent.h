#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class IAnimationGraphComponent
	{
	public:
		virtual ~IAnimationGraphComponent();  // 00

		// add
		virtual void Unk_01();  // 01
		virtual void Unk_02();  // 02
	};
	static_assert(sizeof(IAnimationGraphComponent) == 0x08);

	class BGSAnimationGraphComponent :
		public BaseFormComponent,        // 00
		public IAnimationGraphComponent  // 08
	{
	public:
		SF_RTTI_VTABLE(BGSAnimationGraphComponent);

		~BGSAnimationGraphComponent() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSAnimationGraph_Component"; }
		void                 InitializeDataComponent() override;     // 02

		// members
		BSFixedString unk10;  // 10
		BSFixedString unk18;  // 18
		BSFixedString unk20;  // 20
		BSFixedString unk28;  // 28
		void*         unk30;  // 30 - smart ptr
		std::uint8_t  unk38;  // 38
	};
	static_assert(sizeof(BGSAnimationGraphComponent) == 0x40);
}
