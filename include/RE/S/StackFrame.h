#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/S/Stack.h"
#include "RE/V/Variable.h"

namespace RE::BSScript
{
	class IFunction;
	class ObjectTypeInfo;
	class Variable;

	class StackFrame
	{
	public:
		[[nodiscard]] std::uint32_t GetPageForFrame() const
		{
			return parent->GetPageForFrame(this);
		}

		[[nodiscard]] Variable& GetStackFrameVariable(std::uint32_t a_index, std::uint32_t a_pageHint) const
		{
			return parent->GetStackFrameVariable(this, a_index, a_pageHint);
		}

		// members
		Stack*                          parent;             // 00
		StackFrame*                     previousFrame;      // 08
		BSTSmartPointer<IFunction>      owningFunction;     // 10
		BSTSmartPointer<ObjectTypeInfo> owningObjectType;   // 18
		Variable                        self;               // 20
		std::uint32_t                   index;              // 30
		std::uint32_t                   ip;                 // 34
		std::uint32_t                   size;               // 38
		bool                            instructionsValid;  // 3C
	};
	static_assert(sizeof(StackFrame) == 0x40);
}
