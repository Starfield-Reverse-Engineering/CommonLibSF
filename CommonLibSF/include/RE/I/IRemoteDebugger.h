#pragma once

#include "RE/E/ErrorLogger.h"
namespace RE::BSScript
{
	class IVMRemoteDebuggerInterface;
	class StackFrame;
	class __declspec(novtable) IRemoteDebugger
	{
	public:
		~IRemoteDebugger() = delete;

		virtual void SetVMRemoteDebuggerInterface(IVMRemoteDebuggerInterface* a_interface) = 0;                    // 00
		virtual bool IsPaused() = 0;                                                                               // 01
		virtual bool CheckForBreakpoint(StackFrame& a_frame) = 0;                                                  // 02
		virtual void EmitThreadEvent(std::uint32_t a_threadId, bool a_exited) = 0;                                 // 03
		virtual void EmitOutputEvent(const ICachedErrorMessage& a_message, ErrorLogger::Severity a_severity) = 0;  // 04
		virtual void SendQueuedMessage(bool isPaused) = 0;                                                         // 05
	};
}