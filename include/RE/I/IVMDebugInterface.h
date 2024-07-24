#pragma once

#include "RE/B/BSFixedString.h"

namespace RE::BSScript
{
	class __declspec(novtable) IVMDebugInterface
	{
	public:
		SF_RTTI_VTABLE(BSScript__IVMDebugInterface);

		virtual ~IVMDebugInterface();  // 00

		virtual void DumpRunningStacksToLog() = 0;                                                                                // 01
		virtual void DumpStackFrameToLog(unsigned int a_v, unsigned int b_v, bool a_flag) = 0;                                    // 02
		virtual void GetStackFrame(unsigned int a_v, unsigned int b_v, bool a_flag, BSFixedString& a_identifier) = 0;             // 03
		virtual void DumpPersistenceInformationToLog(char const* logfile, uint64_t a_v) const = 0;                                // 04
		virtual void DumpEventRelayInformationToLog(char const* logfile, uint64_t a_v, BSFixedString const& a_string) const = 0;  // 05
	};
	static_assert(sizeof(IVMDebugInterface) == 0x8);
}
