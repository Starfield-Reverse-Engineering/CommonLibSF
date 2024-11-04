#pragma once

#include "REX/W32/KERNEL32.h"

namespace RE
{
	namespace idLogging
	{
		enum class Severity : std::uint8_t
		{
			Trace = 0,
			Debug = 1,
			Info = 2,
			WARN = 3,
			ERROR = 4,
			FATAL = 5
		};

		struct ILogger
		{
			SF_RTTI_VTABLE(idLogging__ILogger);

			~ILogger() = default;  // 00

			virtual bool ShouldLog(Severity severity) = 0;                                                        // 01
			virtual void Log(const char* a_fileName, int a_line_number, Severity severity, const char* msg) = 0;  // 02

			void Printf(const char* a_fileName, int a_line_number, Severity severity, const char* a_fmt, ...)
			{
				va_list args;
				va_start(args, a_fmt);
				char buffer[1064];
				vsnprintf(buffer, 1024, a_fmt, args);
				va_end(args);
				Log(a_fileName, a_line_number, severity, buffer);
			}
		};

		[[nodiscard]] inline ILogger* GetLoggerSingleton()
		{
			static REL::Relocation<ILogger**> singleton{ ID::idLogging::Singleton };
			return *singleton;
		}
	}

	// in an anonymous namespace in the exe
	struct NetSocketLogger : public idLogging::ILogger
	{
		SF_RTTI_VTABLE(__NetSocketLogger);

		~NetSocketLogger() = default;  // 00

		// override idLogging::ILogger
		bool ShouldLog([[maybe_unused]] idLogging::Severity severity) override { return false; }  // 01

		void Log(const char* a_fileName, int a_line_number, idLogging::Severity severity, const char* msg) override  // 02
		{
			const char* severitystr;
			char        outputString[1032];
			switch (severity)  // Trace, Debug, Info, WARN, ERROR, FATAL, UNKNOWN
			{
			case idLogging::Severity::Trace:
				severitystr = "Trace";
				break;
			case idLogging::Severity::Debug:

				severitystr = "Debug";
				break;
			case idLogging::Severity::Info:
				severitystr = "Info";
				break;
			case idLogging::Severity::WARN:
				severitystr = "WARN";
				break;
			case idLogging::Severity::ERROR:
				severitystr = "ERROR";
				break;
			case idLogging::Severity::FATAL:
				severitystr = "FATAL";
				break;
			default:
				severitystr = "UNKNOWN";
				break;
			}
			snprintf(outputString, 1024, "%s: %s - [%s (%d)]\n", severitystr, msg, a_fileName, a_line_number);
			REX::W32::OutputDebugStringA(outputString);
		}
	};
}
