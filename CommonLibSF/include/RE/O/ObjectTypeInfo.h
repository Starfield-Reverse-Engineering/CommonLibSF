#pragma once

#include "RE/B/BSContainer.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IComplexType.h"
#include "RE/I/IFunction.h"
#include "RE/P/PropertyGroupInfo.h"
#include "RE/V/Variable.h"

namespace RE
{
	namespace BSScript
	{
		class IFunction;

		class ObjectTypeInfo :
			public IComplexType  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__ObjectTypeInfo };
			static constexpr auto VTABLE{ VTABLE::BSScript__ObjectTypeInfo };

			enum class LinkValidState : std::uint8_t
			{
				kNotLinked,
				kCurrentlyLinking,
				kLinkedInvalid,
				kLinkedValid
			};

			// TODO: the rest of this
			// CopyFromLinkedData() is located at REL::ID(196219) if someone wants to figure this out
			/***
             * This likely has:
             * userFlagCount
             * variableCount
             * guardCount
             * propertyCount
             * staticFunctionCount
             * emptyStateMemberFunctionCount
             * namedStateCount
             * initialValueCount
             * 
             * But it's not clear which is which.
             * Also it's not clear if they keep track of variableUserFlagCount or initialState anymore.
            */
			struct CountData
			{
				uint16_t unk00;
				uint16_t variableCount;
				uint16_t unk04;
				uint16_t unk06;
				uint16_t unk08;
				uint16_t unk0A;
				uint16_t unk0C;
				uint16_t unk0E;
			};

			// override (IComplexType)
			virtual TypeInfo::RawType GetRawType() const override { return TypeInfo::RawType::kObject; }  // 01

			// members
			BSFixedString                                name;            // 10
			BSTSmartPointer<ObjectTypeInfo>              parentTypeInfo;  // 18
			BSFixedString                                docString;       // 20
			BSTArray<BSTSmartPointer<PropertyGroupInfo>> propertyGroups;  // 28
			CountData                                    countData;       // 38
			uint64_t                                     unk48;           // 48
			void*                                        data;            // 50
			uint32_t                                     unk58;           // 58
			uint16_t                                     unk5C;           // 5C
			LinkValidState                               linkedValid;     // 5E
			uint8_t                                      unk5F;           // 5F
			bool                                         loaded;          // 60
		};

		static_assert(sizeof(ObjectTypeInfo) == 0x68);
	}
}
