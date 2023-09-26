#pragma once

namespace RE
{
	class ConsoleLog
	{
	public:
		SF_RTTI_VTABLE(ConsoleLog);

		// BSTSDM
		[[nodiscard]] static ConsoleLog* GetSingleton()
		{
			static REL::Relocation<ConsoleLog**> singleton{ REL::ID(879277) };
			return *singleton;
		}

		void Print(const char* a_fmt, ...)
		{
			std::va_list args;
			va_start(args, a_fmt);
			VPrint(a_fmt, args);
			va_end(args);
		}

		void VPrint(const char* a_fmt, std::va_list a_args)
		{
			using func_t = decltype(&ConsoleLog::VPrint);
			REL::Relocation<func_t> func{ REL::ID(166358) };
			func(this, a_fmt, a_args);
		}
	};
}
