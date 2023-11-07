#include "RE/R/RemoteDebugger.h"
namespace RE::GameScript
{
	void RemoteDebugger::HandleContinueRequest(const DebuggerMessages::ContinueRequest& a_request)
	{
		using func_t = decltype(&RemoteDebugger::HandleContinueRequest);
		REL::Relocation<func_t> func{ ID::GameScript::RemoteDebugger::HandleContinueRequest };
		return func(this, a_request);
	}
	void RemoteDebugger::HandleDisconnectRequest(const DebuggerMessages::DisconnectRequest& a_request)
	{
		using func_t = decltype(&RemoteDebugger::HandleDisconnectRequest);
		REL::Relocation<func_t> func{ ID::GameScript::RemoteDebugger::HandleDisconnectRequest };
		return func(this, a_request);
	}
	void RemoteDebugger::HandlePauseRequest(const DebuggerMessages::PauseRequest& a_request)
	{
		using func_t = decltype(&RemoteDebugger::HandlePauseRequest);
		REL::Relocation<func_t> func{ ID::GameScript::RemoteDebugger::HandlePauseRequest };
		return func(this, a_request);
	}
	void RemoteDebugger::HandleSetBreakpointsRequest(const DebuggerMessages::SetBreakpointsRequest& a_request)
	{
		using func_t = decltype(&RemoteDebugger::HandleSetBreakpointsRequest);
		REL::Relocation<func_t> func{ ID::GameScript::RemoteDebugger::HandleSetBreakpointsRequest };
		return func(this, a_request);
	}
	void RemoteDebugger::HandleStackTraceRequest(const DebuggerMessages::StackTraceRequest& a_request)
	{
		using func_t = decltype(&RemoteDebugger::HandleStackTraceRequest);
		REL::Relocation<func_t> func{ ID::GameScript::RemoteDebugger::HandleStackTraceRequest };
		return func(this, a_request);
	}
	void RemoteDebugger::HandleStepRequest(const DebuggerMessages::Request& a_request, uint32_t a_threadid, StepKind a_stepKind)
	{
		using func_t = decltype(&RemoteDebugger::HandleStepRequest);
		REL::Relocation<func_t> func{ ID::GameScript::RemoteDebugger::HandleStepRequest };
		return func(this, a_request, a_threadid, a_stepKind);
	}
	void RemoteDebugger::HandleVariablesRequest(const DebuggerMessages::VariablesRequest& a_request)
	{
		using func_t = decltype(&RemoteDebugger::HandleVariablesRequest);
		REL::Relocation<func_t> func{ ID::GameScript::RemoteDebugger::HandleVariablesRequest };
		return func(this, a_request);
	}
	void RemoteDebugger::HandleValueRequest(const DebuggerMessages::ValueRequest& a_request)
	{
		using func_t = decltype(&RemoteDebugger::HandleValueRequest);
		REL::Relocation<func_t> func{ ID::GameScript::RemoteDebugger::HandleValueRequest };
		return func(this, a_request);
	}

}
