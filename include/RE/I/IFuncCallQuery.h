#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE::BSScript
{
	class StackFrame;
	class Variable;
	class ObjectTypeInfo;
	class Object;

	namespace Internal
	{
		class IFuncCallQuery : public BSIntrusiveRefCounted
		{
		public:
			SF_RTTI_VTABLE(BSScript__Internal__IFuncCallQuery);

			enum class CallType
			{
				kMember,
				kStatic,
				kGetter,
				kSetter
			};
			virtual ~IFuncCallQuery();  // 00

			// add
			virtual bool GetFunctionCallInfo(
				CallType&                           a_callType,
				BSTSmartPointer<ObjectTypeInfo>&    a_objectTypeInfo,
				BSFixedString&                      a_name,
				Variable&                           a_self,
				void* /* BSScrapArray<Variable>& */ a_args) const = 0;    // 01
			virtual BSTSmartPointer<Object> GetSelfAsObject() const = 0;  // 02
		};
		static_assert(sizeof(IFuncCallQuery) == 0x10);
	}
}
