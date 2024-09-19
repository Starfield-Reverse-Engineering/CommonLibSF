#include "RE/I/idLogging.h"

namespace RE::idLogging
{
	ILogger* GetLoggerSingleton()
	{
		static REL::Relocation<ILogger**> singleton{ ID::idLogging::singleton };
		return *singleton;
	}
}
