#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/V/Variable.h"

namespace RE
{
	namespace BSScript
	{
		class IProfilePolicy;
		class IStackCallbackFunctor;
		class MemoryPage;  // stub
		class Object;
		class StackFrame;

		struct IMemoryPagePolicy;

		namespace Internal
		{
			class CodeTasklet;
		}

		namespace UnlinkedTypes
		{
			struct Object;  // stub
		}

		class Stack :
			public BSIntrusiveRefCounted  // 00
		{
		public:
			enum class StackType
			{
				kNormal,
				kPropInit,
				kInitEvent
			};

			enum class FreezeState
			{
				kUnfrozen,
				kFreezing,
				kFrozen
			};

			enum class State
			{
				kRunning,
				kFinished,
				kWaitingOnMemory,
				kWaitingOnLatentFunction,
				kWaitingInOtherStackForCall,
				kWaitingInOtherStackForReturn,
				kWaitingInOtherStackForReturnNoPop,
				kRetryReturnNoPop,
				kRetryCall,
				kWaitingOnGuard,
				kWaitingOnOtherStackForGuard,
			};

			struct MemoryPageData
			{
			public:
				// members
				BSTAutoPointer<MemoryPage> page;                    // 00
				std::uint32_t              availableMemoryInBytes;  // 08
			};
			static_assert(sizeof(MemoryPageData) == 0x10);

			[[nodiscard]] std::uint32_t GetPageForFrame(const StackFrame* a_frame) const
			{
				using func_t = decltype(&Stack::GetPageForFrame);
				REL::Relocation<func_t> func{ ID::BSScript::Stack::GetPageForFrame };
				return func(this, a_frame);
			}

			[[nodiscard]] Variable& GetStackFrameVariable(const StackFrame* a_frame, std::uint32_t a_index, std::uint32_t a_pageHint)
			{
				using func_t = decltype(&Stack::GetStackFrameVariable);
				REL::Relocation<func_t> func{ ID::BSScript::Stack::GetStackFrameVariable };
				return func(this, a_frame, a_index, a_pageHint);
			}

			// members
			IMemoryPagePolicy*                          policy;         // 08
			void*                                       unk10;          // 10 -- something to do with guards, guardPolicy maybe?
			IProfilePolicy*                             profilePolicy;  // 18
			void*                                       unk20;          // 20
			/*BSTSmallArray<MemoryPageData, 3>*/ char   pages[0x40];    // 28
			StackFrame*                                 top;            // 68
			BSTSmartPointer<Internal::CodeTasklet>      owningTasklet;  // 70
			BSTSmartPointer<IStackCallbackFunctor>      callback;       // 78
			BSTSmartPointer<Object>                     objToUnbind;    // 80
			BSTSmartPointer<Stack>                      nextStack;      // 88
			Variable                                    returnValue;    // 90
			std::uint64_t                               unk98;          // A0
			std::uint64_t                               unkA0;          // A8
			std::uint32_t                               frames;         // B0
			std::uint32_t                               stackID;        // B4
			stl::enumeration<State, std::int32_t>       state;          // B8
			stl::enumeration<FreezeState, std::int32_t> freezeState;    // BC
			stl::enumeration<StackType, std::int32_t>   stackType;      // C0
		};
		static_assert(sizeof(Stack) == 0xC8);
	}
}
