#pragma once

#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSKeyword;
	class BGSMorphableObject;
}

namespace RE::BGSMod
{
	namespace Attachment
	{
		class Mod :
			public TESForm,              // 00
			public TESFullName,          // 30
			public TESDescription,       // 40
			public BGSModelMaterialSwap  // 58
		{
		public:
			SF_RTTI_VTABLE(BGSMod__Attachment__Mod);
			SF_FORMTYPE(OMOD);

			struct Data
			{
			public:
				enum class IncludesFlag
				{
					kNone = 0,
					kOptional = 1 << 0,
					kDontUseAll = 1 << 1
				};

				struct Include
				{
					RE::BGSMod::Attachment::Mod*                 mod;
					std::uint8_t                                 level;
					stl::enumeration<IncludesFlag, std::uint8_t> flags;
				};
				static_assert(sizeof(Include) == 0x10);

				// members
				BSTArray<Include> includes;    // 00
				BSTArray<void*>   properties;  // 10
			};
			static_assert(sizeof(Data) == 0x20);

			~Mod() override;  // 00

			// members
			Data                 data;           // 80
			BGSAttachParentArray attachParents;  // A0
			std::uint64_t        unkC0;          // C0 - std::vector<BGSKeyword*>?
			std::uint64_t        unkC8;          // C8
			std::uint64_t        unkD0;          // D0
			BGSKeyword*          attachPoint;    // D8
			BGSMorphableObject*  unkE0;          // E0
			BGSMorphableObject*  unkE8;          // E8
			BSFixedString        name;           // F0
			std::uint8_t         unkF8;          // F8
			std::uint8_t         unkF9;          // F9
			std::uint8_t         priority;       // FA
			std::uint8_t         unkFB;          // FB
			std::uint8_t         unkFC;          // FC
		};
		static_assert(sizeof(Mod) == 0x100);
	}

	namespace Template
	{
		class Items : public BaseFormComponent
		{
		public:
			SF_RTTI_VTABLE(BGSMod__Template__Items);

			~Items() override;  // 00

			// override (BaseFormComponent)
			const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSMod_Template_Component"; }
			void                 InitializeDataComponent() override;     // 02

			// add
			virtual void Unk_0B();  // 0B
			virtual void Unk_0C();  // 0C
			virtual void Unk_0D();  // 0D

			// members
			BSTArray<void*> unk08;  // 08
			BSFixedString   unk18;  // 18
		};
		static_assert(sizeof(Items) == 0x20);
	}
}
