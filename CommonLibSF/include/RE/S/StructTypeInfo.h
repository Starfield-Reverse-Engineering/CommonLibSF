#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IComplexType.h"
#include "RE/M/MemoryManager.h"
#include "RE/T/TypeInfo.h"
#include "RE/V/Variable.h"

namespace RE
{
	namespace BSScript
	{
		class IComplexType;
		class ObjectTypeInfo;
		class TypeInfo;
		class Variable;

		class __declspec(novtable) StructTypeInfo :
			public IComplexType  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__StructTypeInfo };
			static constexpr auto VTABLE{ VTABLE::BSScript__StructTypeInfo };

			enum class LinkValidState
			{
				kNotLinked,
				kCurrentlyLinking,
				kLinkedInvalid,
				kLinkedValid
			};

			struct StructVar
			{
			public:
				// members
				Variable      initialValue;  // 00
				TypeInfo      varType;       // 10
				BSFixedString docString;     // 18
				std::uint32_t userFlags;     // 20
				bool          isConst;       // 24
			};
			static_assert(sizeof(StructVar) == 0x28);

			const char* GetName() const
			{
				return name.c_str();
			}

			// override (IComplexType)
			virtual TypeInfo::RawType GetRawType() const override { return TypeInfo::RawType::kStruct; }  // 01

			// members
			BSFixedString                                     name;                   // 10
			BSTSmartPointer<ObjectTypeInfo>                   containingObjTypeInfo;  // 18
			BSTArray<StructVar>                               variables;              // 20
			/*BSTHashMap<BSFixedString, std::uint32_t>*/ char varNameIndexMap[0x38];  // 30
			stl::enumeration<LinkValidState, std::int32_t>    linkedValid;            // 68
		};
		static_assert(sizeof(StructTypeInfo) == 0x70);
	}
}
