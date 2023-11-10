#pragma once

#include "RE/E/ErrorLogger.h"
#include "RE/I/IRemoteDebugger.h"

namespace RE::GameScript
{
	class BSLog;

	class __declspec(novtable) Logger :
		public BSScript::ErrorLogger  // 00
	{
	public:
		SF_RTTI_VTABLE(GameScript__Logger);

		// override (BSScript::ErrorLogger)
		void PostErrorImpl(const BSScript::ICachedErrorMessage* a_errMsg, Severity a_severity) override;  // 01

		// members
		BSFixedString              logFolder;       // 70
		BSLog*                     log;             // 78
		BSScript::IRemoteDebugger* remoteDebugger;  // 80
	};
	static_assert(sizeof(Logger) == 0x88);
}
