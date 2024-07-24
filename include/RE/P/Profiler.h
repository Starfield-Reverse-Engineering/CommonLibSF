#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/B/BSTimer.h"
#include "RE/I/IFuncCallQuery.h"
#include "RE/I/IProfilePolicy.h"

namespace RE
{
	class BSLog;

	namespace GameScript
	{
		class __declspec(novtable) Profiler :
			public BSScript::IProfilePolicy  // 000
		{
		public:
			static constexpr auto RTTI{ RTTI::GameScript__Profiler };
			static constexpr auto VTABLE{ VTABLE::GameScript__Profiler };

			// override (BSScript::IProfilePolicy)
			void StackFramePushQueued(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const BSTSmartPointer<BSScript::Internal::IFuncCallQuery>& a_funcCallQuery) override;                                                                 // 01
			void StackFramePushed(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const BSScript::Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_stateName, const BSFixedString& a_functionName) override;     // 02
			void StackFramePopQueued(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const BSScript::Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_stateName, const BSFixedString& a_functionName) override;  // 03
			void StackFramePopped(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const BSScript::Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_stateName, const BSFixedString& a_functionName) override;     // 04
			void GuardPending(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const BSScript::Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_guardName) override;                                              // 05
			void GuardTaken(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const BSScript::Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_guardName) override;                                                // 05
			void GuardReleased(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const BSScript::Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_guardName) override;                                             // 05

			// members
			BSSpinLock                                      dataLock;              // 008
			BSLog*                                          globalProfilingLog;    // 010
			/*BSTHashMap<std::uint32_t, BSLog*>*/ std::byte watchedStacks[0x38];   // 018
			/*BSTHashMap<BSFixedString, BSLog*>*/ std::byte watchedScripts[0x38];  // 050
			/*BSTHashMap<std::size_t, BSLog*>  */ std::byte watchedObjects[0x38];  // 088
			BSTArray<BSTTuple<BSFixedString, std::size_t>>  watchedStackRoots;     // 0C0
			BSTimer                                         timer;                 // 0D0
		};
		static_assert(sizeof(Profiler) == 0x130);
	}
}
