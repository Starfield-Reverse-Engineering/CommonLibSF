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
	class BGSAddonNode;
}

namespace RE::BGSMod
{
	class Container
	{
	public:
		SF_RTTI(BGSMod__Container);
	};

	namespace Attachment
	{
		class __declspec(novtable) Mod :
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
				// members

				enum class IncludesFlag
				{
					kNone = 0,
					kOptional = 1 << 0,
					kDontUseAll = 1 << 1
				};

				struct Include
				{
					BGSMod::Attachment::Mod*                 mod;
					std::uint8_t                             level;
					REX::EnumSet<IncludesFlag, std::uint8_t> flags;
				};

				static_assert(sizeof(Include) == 0x10);

				struct Property
				{
					struct ValueType1Bool
					{
						bool  value1;
						bool  value2;
						void* pad;
					};

					struct ValueType2Float
					{
						float value1;
						float value2;
						void* pad;
					};

					struct ValueType3Int
					{
						std::int32_t value1;
						std::int32_t value2;
						void*        pad;
					};

					struct ValueType4FormFloat
					{
						RE::TESForm* value1;
						float        value2;
					};

					union  // 0
					{
						ValueType1Bool      type1Val;
						ValueType2Float     type2Val;
						ValueType3Int       type3Val;
						ValueType4FormFloat type4Val;
					};

					std::uint8_t  type;        // 10
					std::uint8_t  pad[7];      // 11
					std::uint32_t propertyID;  // 18
					std::uint32_t pad2;        // 18
											   // std::uint64_t pad2;
											   // float         pad2;
											   // float Value1;
											   // float Value2;
				};

				static_assert(sizeof(Property) == 0x20);
				static_assert(offsetof(Property, type) == 0x10);

				BSTArray<Include>  includes;    // 00
				BSTArray<Property> properties;  // 10
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

		static_assert(sizeof(Mod) == 0x108);
	}  // namespace Attachment

	namespace Template
	{
		class __declspec(novtable) Item :
			public TESFullName,       // 00
			public BGSMod::Container  // 10
		{
		public:
			SF_RTTI_VTABLE(BGSMod__Template__Item);
			~Item() override;  // 00
		};
		class __declspec(novtable) Items :
			public BaseFormComponent  // 00
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
			BSTArray<Item*> items;  // 08
			BSFixedString   unk18;  // 18
		};
		static_assert(sizeof(Items) == 0x20);
	}
}
