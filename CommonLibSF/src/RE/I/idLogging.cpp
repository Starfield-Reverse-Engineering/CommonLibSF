#include "RE/I/idLogging.h"

namespace RE::idLogging
{
	ILogger* GetLoggerSingleton()
	{
		REL::Relocation<ILogger**> singleton{ ID::idLogging::singleton };
		return *singleton;
	}
}
