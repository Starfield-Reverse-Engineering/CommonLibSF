#pragma once

#include "RE/B/BSStringT.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	struct ConsoleLogAddEvent;

	class __declspec(novtable) ConsoleLog :
		public BSTSingletonSDM<ConsoleLog>,
		public BSTEventSource<ConsoleLogAddEvent>
	{
	public:
		SF_RTTI_VTABLE(ConsoleLog);

		virtual ~ConsoleLog();  // 00

		[[nodiscard]] static ConsoleLog* GetSingleton()
		{
			static REL::Relocation<ConsoleLog**> singleton{ ID::ConsoleLog::Singleton };
			return *singleton;
		}

		void AddString(const char* a_str)
		{
			using func_t = decltype(&ConsoleLog::AddString);
			static REL::Relocation<func_t> func{ ID::ConsoleLog::AddString };
			func(this, a_str);
		}

		// std::format rules, has compile time checking
		template <class... Args>
		void Log(const std::format_string<Args...> a_fmt, Args&&... a_args)
		{
			auto str = std::vformat(a_fmt.get(), std::make_format_args(a_args...));
			str += '\n';
			AddString(str.c_str());
		}

		void Print(const char* a_fmt, std::va_list a_args)
		{
			using func_t = decltype(&ConsoleLog::Print);
			static REL::Relocation<func_t> func{ ID::ConsoleLog::Print };
			func(this, a_fmt, a_args);
		}

		// std::printf rules, no compile time checking
		void PrintLine(const char* a_fmt, ...)
		{
			std::va_list args;
			va_start(args, a_fmt);
			Print(a_fmt, args);
			va_end(args);
		}

		void SetUseConsoleOverlay(bool a_value)
		{
			useConsoleOverlay = a_value;
		}

		// members
		BSStringT<char> buffer;             // 38
		bool            useConsoleOverlay;  // 48
	};
	static_assert(sizeof(ConsoleLog) == 0x48);
}
