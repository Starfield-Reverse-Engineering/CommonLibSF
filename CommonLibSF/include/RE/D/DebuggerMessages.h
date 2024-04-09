#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSLog.h"
#include "RE/F/FormTypes.h"

static_assert(sizeof(std::string) == 0x20);  // If this fails, _ITERATOR_DEBUG_LEVEL is greater than 0
static_assert(sizeof(std::vector<int>) == 0x18);
static_assert(sizeof(std::vector<std::string>) == 0x18);

namespace Json
{
	class Value;
}

namespace RE::GameScript
{
	class RemoteDebugger;

	namespace DebuggerMessages
	{
		// base messages
		struct __declspec(novtable) ProtocolMessage
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__ProtocolMessage);

			~ProtocolMessage() = default;  // 00

			virtual void Serialize(const Json::Value& a_val) = 0;                               // 01
			virtual void HandleMessage(const RemoteDebugger& a_debugger, const BSLog& logger);  // 02

			int           seq;    // 08
			std::uint32_t gap_C;  // 0C
			std::string   type;   // 10 - "request", "response", "event"
		};
		static_assert(sizeof(ProtocolMessage) == 0x30);

		struct Request : public ProtocolMessage
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__Request);

			~Request();                                                 // 00
																		// override ProtocolMessage
			virtual void Serialize(const Json::Value& a_val) override;  // 01

			// start Request
			virtual void SerializeBody(Json::Value& r_val);                               // 03 - { r_val.Value(0); return; }
			virtual void DeserializeArgs(const Json::Value& a_val, const BSLog& logger);  // 04

			// members
			std::string command;  // 30
		};
		static_assert(sizeof(Request) == 0x50);

		struct Response : public ProtocolMessage
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__Response);

			~Response();                                                // 00
																		// override ProtocolMessage
			virtual void Serialize(const Json::Value& a_val) override;  // 01

			//  start Response
			virtual void SerializeBody(Json::Value& r_val);  // 03 - { r_val.Value(0); return; }

			// members
			std::string command;      // 30
			std::string message;      // 50
			int         request_seq;  // 70
			bool        success;      // 74
		};
		static_assert(sizeof(Response) == 0x78);

		struct Event : public ProtocolMessage
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__Event);

			~Event();  // 00

			// override ProtocolMessage
			virtual void Serialize(const Json::Value& a_val) override;  // 01

			// start Event
			virtual void SerializeBody(Json::Value& r_val);  // 03 - { r_val.Value(0); return; }

			// members
			std::string event;  // 30
		};
		static_assert(sizeof(Event) == 0x50);

		// request messages

		struct SetBreakpointsRequest : public Request
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__SetBreakpointsRequest);

			~SetBreakpointsRequest();  // 00

			// override Request
			virtual void HandleMessage(const RemoteDebugger& a_debugger, const BSLog& logger) override;  // 02
			virtual void DeserializeArgs(const Json::Value& a_val, const BSLog& logger) override;        // 04

			// members
			std::string      source;  // 50
			std::vector<int> lines;   // 70
		};
		static_assert(sizeof(SetBreakpointsRequest) == 0x88);

		struct ThreadsRequest : public Request
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__ThreadsRequest);

			// override Request
			virtual void HandleMessage(const RemoteDebugger& a_debugger, const BSLog& logger) override;  // 02
		};
		static_assert(sizeof(ThreadsRequest) == 0x50);

		struct StepInRequest : public Request
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__StepInRequest);

			// override Request
			virtual void HandleMessage(const RemoteDebugger& a_debugger, const BSLog& logger) override;  // 02
			virtual void DeserializeArgs(const Json::Value& a_val, const BSLog& logger) override;        // 04
			// members
			std::uint32_t threadId;  // 50
		};
		static_assert(sizeof(StepInRequest) == 0x58);

		struct StepOutRequest : public Request
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__StepOutRequest);

			// override Request
			virtual void HandleMessage(const RemoteDebugger& a_debugger, const BSLog& logger) override;  // 02
			virtual void DeserializeArgs(const Json::Value& a_val, const BSLog& logger) override;        // 04
			// members
			std::uint32_t threadId;  // 50
		};
		static_assert(sizeof(StepOutRequest) == 0x58);

		struct NextRequest : public Request
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__NextRequest);

			// override Request
			virtual void HandleMessage(const RemoteDebugger& a_debugger, const BSLog& logger) override;  // 02
			virtual void DeserializeArgs(const Json::Value& a_val, const BSLog& logger) override;        // 04
			// members
			std::uint32_t threadId;  // 50
		};
		static_assert(sizeof(NextRequest) == 0x58);

		struct ContinueRequest : public Request
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__ContinueRequest);

			// override Request
			virtual void HandleMessage(const RemoteDebugger& a_debugger, const BSLog& logger) override;  // 02
		};
		static_assert(sizeof(ContinueRequest) == 0x50);

		struct PauseRequest : public Request
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__PauseRequest);

			// override Request
			virtual void HandleMessage(const RemoteDebugger& a_debugger, const BSLog& logger) override;  // 02
		};
		static_assert(sizeof(PauseRequest) == 0x50);

		struct DisconnectRequest : public Request
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__DisconnectRequest);

			// override Request
			virtual void HandleMessage(const RemoteDebugger& a_debugger, const BSLog& logger) override;  // 02
		};
		static_assert(sizeof(DisconnectRequest) == 0x50);

		struct StackTraceRequest : public Request
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__StackTraceRequest);

			~StackTraceRequest();  // 00

			// override Request
			virtual void HandleMessage(const RemoteDebugger& a_debugger, const BSLog& logger) override;  // 02
			virtual void DeserializeArgs(const Json::Value& a_val, const BSLog& logger) override;        // 04

			// members
			int threadId;
		};
		static_assert(sizeof(StackTraceRequest) == 0x58);

		struct Root
		{
			enum class RootType
			{
				kUnknown = 0,
				kStackFrame = 1,
				kValue = 2,
			};

			stl::enumeration<FormType, std::uint64_t> valuetype;        // 00
			unsigned int                              threadId;         // 08
			int                                       stackFrameIndex;  // 0C
			stl::enumeration<RootType, std::uint8_t>  rootType;         // 10
		};
		static_assert(sizeof(Root) == 0x18);

		struct Variable
		{
			std::string name;      // 00
			std::string value;     // 20
			std::string type;      // 40
			bool        compound;  // 60
		};
		static_assert(sizeof(Variable) == 0x68);

		struct ValueRequest : public Request
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__ValueRequest);

			~ValueRequest();  // 00

			// override Request
			virtual void HandleMessage(const RemoteDebugger& a_debugger, const BSLog& logger) override;  // 02
			virtual void DeserializeArgs(const Json::Value& a_val, const BSLog& logger) override;        // 04

			// members
			std::vector<std::string> path;  // 50
			Root                     root;  // 68
		};
		static_assert(sizeof(ValueRequest) == 0x80);

		struct VariablesRequest : public Request
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__VariablesRequest);

			~VariablesRequest();  // 00

			// override Request
			virtual void HandleMessage(const RemoteDebugger& a_debugger, const BSLog& logger) override;  // 02
			virtual void DeserializeArgs(const Json::Value& a_val, const BSLog& logger) override;        // 04

			// members
			std::vector<std::string> path;  // 50
			Root                     root;  // 68
		};
		static_assert(sizeof(VariablesRequest) == 0x80);

		// response messages

		struct SetBreakpointsResponse : public Response
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__SetBreakpointsResponse);

			~SetBreakpointsResponse();  // 00

			// override Response
			virtual void SerializeBody(Json::Value& r_val) override;  // 03

			struct Breakpoint
			{
				std::string source;
				int         line;
				bool        verified;
			};

			// members
			std::vector<Breakpoint> breakpoints;  // 78
		};
		static_assert(sizeof(SetBreakpointsResponse) == 0x90);

		struct StackTraceResponse : public Response
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__StackTraceResponse);
			struct StackFrame
			{
				std::string name;
				std::string object;
				std::string source;
				int         line;
			};

			~StackTraceResponse();  // 00

			// override Response
			virtual void SerializeBody(Json::Value& r_val) override;  // 03

			// members
			std::vector<StackFrame> stackFrames;
		};
		static_assert(sizeof(StackTraceResponse) == 0x90);

		struct ThreadsResponse : public Response
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__ThreadsResponse);

			~ThreadsResponse();  // 00

			struct Thread
			{
				std::string name;
				int         id;
			};

			// override Response
			virtual void SerializeBody(Json::Value& r_val) override;  // 03

			// members
			std::vector<Thread> threads;  // 78
		};
		static_assert(sizeof(ThreadsResponse) == 0x90);

		struct ValueResponse : public Response
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__ValueResponse);

			~ValueResponse();  // 00

			// override Response
			virtual void SerializeBody(Json::Value& r_val) override;  // 03

			// members
			std::string value;     // 78
			std::string type;      // 98
			bool        compound;  // B8
		};
		static_assert(sizeof(ValueResponse) == 0xC0);

		struct VariablesResponse : public Response
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__VariablesResponse);

			~VariablesResponse();  // 00

			// override Response
			virtual void SerializeBody(Json::Value& r_val) override;  // 03

			// members
			std::vector<Variable> variables;  // 78
		};
		static_assert(sizeof(VariablesResponse) == 0x90);

		// event messages

		struct OutputEvent : public Event
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__OutputEvent);

			~OutputEvent();  // 00

			// override Event
			virtual void SerializeBody(Json::Value& r_val) override;  // 03

			// members
			BSFixedString channel;   // 50
			BSFixedString output;    // 58
			BSFixedString severity;  // 60
		};
		static_assert(sizeof(OutputEvent) == 0x68);

		struct StoppedEvent : public Event
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__StoppedEvent);

			~StoppedEvent();  // 00

			// override Event
			virtual void SerializeBody(Json::Value& r_val) override;  // 03

			// members
			int threadId;  // 50
			int stepped;   // 54
		};
		static_assert(sizeof(StoppedEvent) == 0x58);

		struct ThreadEvent : public Event
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__ThreadEvent);

			~ThreadEvent();  // 00

			// override Event
			virtual void SerializeBody(Json::Value& r_val) override;  // 03

			// members
			int  threadId;
			bool exited;
		};
		static_assert(sizeof(ThreadEvent) == 0x58);

		struct VersionEvent : public Event
		{
			SF_RTTI_VTABLE(GameScript__DebuggerMessages__VersionEvent);

			~VersionEvent();  // 00

			// override Event
			virtual void SerializeBody(Json::Value& r_val) override;  // 03
		};
		static_assert(sizeof(VersionEvent) == 0x50);
	}
}
