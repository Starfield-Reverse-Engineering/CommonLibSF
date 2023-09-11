#pragma once

namespace RE
{
	class ConsoleLog
	{
	public:
		TES_RTTI_VTABLE(ConsoleLog);

		// BSTSDM
		[[nodiscard]] static ConsoleLog* GetSingleton()
		{
			static REL::Relocation<ConsoleLog**> singleton{ REL::Offset(0x058F6C50) };
			return *singleton;
		}

		void Print(const char* a_fmt, std::va_list a_args)
		{
			using func_t = decltype(&ConsoleLog::Print);
			REL::Relocation<func_t> func{ REL::Offset(0x02883B48) };
			func(this, a_fmt, a_args);
		}
	};
}
