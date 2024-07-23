#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTEvent.h"
#include "RE/I/ICachedErrorMessage.h"

namespace RE::BSScript
{
	class ICachedErrorMessage;

	struct LogEvent;

	class __declspec(novtable) ErrorLogger :
		public BSTEventSource<LogEvent>  // 08
	{
	public:
		SF_RTTI_VTABLE(BSScript__ErrorLogger);

		enum class Severity
		{
			kInfo,
			kWarning,
			kError,
			kFatal
		};

		struct PerThreadErrorCounts
		{
		public:
			// members
			std::uint32_t fatalCount;    // 0
			std::uint32_t errorCount;    // 4
			std::uint32_t warningCount;  // 8
		};
		static_assert(sizeof(PerThreadErrorCounts) == 0xC);

		virtual ~ErrorLogger();  // 00

		// add
		virtual void PostErrorImpl(const ICachedErrorMessage* a_errMsg, Severity a_severity) = 0;  // 01
		virtual void ResetImpl() { return; }                                                       // 02

		// members
		const BSFixedString                                                        logName;             // 28
		BSSpinLock                                                                 dataLock;            // 30
		/*BSTHashMap<std::uint32_t, ErrorLogger::PerThreadErrorCounts>*/ std::byte threadErrors[0x38];  // 38
	};
	static_assert(sizeof(ErrorLogger) == 0x70);
}
