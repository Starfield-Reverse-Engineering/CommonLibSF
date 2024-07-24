#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/D/DebuggerMessages.h"
#include "RE/I/IRemoteDebugger.h"
#include "RE/I/idTCP.h"

namespace RE::GameScript
{
	class RemoteDebugger : BSScript::IRemoteDebugger
	{
	public:
		struct Breakpoint
		{
			BSFixedString className;
			BSFixedString stateName;
			BSFixedString functionName;
			std::uint32_t instructionPointer;
		};

		enum class StepKind : std::uint8_t
		{
			kNext,
			kStepIn,
			kStepOut
		};

		struct StackFramePointer
		{
			std::uint32_t threadId;
			int           stackFrameIndex;
			std::uint32_t lineNumber;
			int           instructionPointer;
			StepKind      stepKind;
		};

		struct TCPServer
		{
			idTCP                  listenTCP;     // 00
			idTCP                  readWriteTCP;  // 20
			BSNonReentrantSpinLock lock;          // 40
		};
		static_assert(sizeof(TCPServer) == 0x48);

		struct VMRemoteInterfaceStruct
		{
			void*                                 listenThread;           // 00
			BSScript::IVMRemoteDebuggerInterface* VMRemoteDebuggerIface;  // 08
			BSReadWriteLock                       lock;                   // 10
		};
		static_assert(sizeof(VMRemoteInterfaceStruct) == 0x18);

		struct State
		{
			msvc::unique_ptr<DebuggerMessages::ProtocolMessage> PauseResponse;       // 00
			msvc::unique_ptr<DebuggerMessages::ProtocolMessage> ContinueResponse;    // 08
			msvc::unique_ptr<DebuggerMessages::ProtocolMessage> StoppedEvent;        // 10
			std::vector<Breakpoint>                             breakpoints;         // 18 -- TODO: use BSTHeapSTLAllocator
			std::vector<StackFramePointer>                      stackFramePointers;  // 30 -- TODO: use BSTHeapSTLAllocator
			bool                                                paused;              // 48
			BSReadWriteLock                                     lock;                // 50
		};
		static_assert(sizeof(State) == 0x58);

		~RemoteDebugger() = delete;

		// override IRemoteDebugger
		virtual void SetVMRemoteDebuggerInterface(BSScript::IVMRemoteDebuggerInterface* a_interface) override;                              // 00
		virtual bool IsPaused() override;                                                                                                   // 01
		virtual bool CheckForBreakpoint(BSScript::StackFrame& a_frame) override;                                                            // 02
		virtual void EmitThreadEvent(std::uint32_t a_threadId, bool a_exited) override;                                                     // 03
		virtual void EmitOutputEvent(const BSScript::ICachedErrorMessage& a_message, BSScript::ErrorLogger::Severity a_severity) override;  // 04
		virtual void SendQueuedMessage(bool a_isPaused) override;                                                                           // 05

		BSLog* GetLogger();

		void HandleContinueRequest(const DebuggerMessages::ContinueRequest& a_request);
		void HandleDisconnectRequest(const DebuggerMessages::DisconnectRequest& a_request);
		void HandlePauseRequest(const DebuggerMessages::PauseRequest& a_request);
		void HandleSetBreakpointsRequest(const DebuggerMessages::SetBreakpointsRequest& a_request);
		void HandleStackTraceRequest(const DebuggerMessages::StackTraceRequest& a_request);
		void HandleStepRequest(const DebuggerMessages::Request& a_request, uint32_t a_threadid, StepKind a_stepKind);
		void HandleThreadsRequest(const DebuggerMessages::ThreadsRequest& a_request);
		void HandleValueRequest(const DebuggerMessages::ValueRequest& a_request);
		void HandleVariablesRequest(const DebuggerMessages::VariablesRequest& a_request);

	private:
		void ListenLoop(std::uint16_t port);

	public:
		// members
		bool                    active;               // 08
		TCPServer               tcpServer;            // 10
		State                   statestruct;          // 58
		VMRemoteInterfaceStruct VMremoteIfaceStruct;  // B0
		BSLog*                  logger;               // C8
		BSNonReentrantSpinLock  logLock;              // D0
	};
	static_assert(sizeof(RemoteDebugger) == 0xD8);
}
