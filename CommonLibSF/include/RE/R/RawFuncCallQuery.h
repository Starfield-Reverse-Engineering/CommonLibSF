#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IFuncCallQuery.h"
#include "RE/V/Variable.h"

namespace RE::BSScript
{
	class StackFrame;
	class Variable;
	class ObjectTypeInfo;

	namespace Internal
	{
		class RawFuncCallQuery :
			public IFuncCallQuery  // 00
		{
		public:
			SF_RTTI_VTABLE(BSScript__Internal__RawFuncCallQuery);

			virtual ~RawFuncCallQuery();  // 00

			// override (IFuncCallQuery)
			virtual bool GetFunctionCallInfo(
				CallType&                           a_callType,
				BSTSmartPointer<ObjectTypeInfo>&    a_objectTypeInfo,
				BSFixedString&                      a_name,
				Variable&                           a_self,
				void* /* BSScrapArray<Variable>& */ a_args) const override;  // 01

			virtual BSTSmartPointer<Object> GetSelfAsObject() const override;  // 02 -- just calls get<BSTSmartPointer<Object>>()

			// members
			CallType                        callType;  // 10
			std::uint32_t                   pad14;     // 14
			BSTSmartPointer<ObjectTypeInfo> objType;   // 18
			BSFixedString                   name;      // 20
			Variable                        self;      // 28
			BSTArray<Variable>              args;      // 38
		};
		static_assert(sizeof(RawFuncCallQuery) == 0x48);
	}
}
