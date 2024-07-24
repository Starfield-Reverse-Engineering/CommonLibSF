#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSSystemFile.h"

namespace RE
{
	class BSLog
	{
		~BSLog();

		BSLog() = delete;

		BSLog(const BSLog&) = delete;
		BSLog(BSLog&&) = delete;

		BSLog(
			const char*   a_logName,
			const char*   a_logFolderPath,
			bool          a_timeStamped,
			std::uint32_t a_logNumber,
			std::uint32_t a_bufferSize,
			std::uint32_t a_blocks_allocated);

		void CycleLog();
		void FlushBuffer(bool a_forceFlush);
		void FlushBufferToFile(bool a_forceFlush);
		void WriteEntry(const char* a_string, bool a_shouldFlush);
		void WriteData(char* data, std::uint32_t size, bool a_shouldFlush);

		static void MakeLogFilename(char* a_name, const char* a_dir, std::uint32_t a_logNumber, BSFixedString& r_fileName, bool a_appendLogNumber);
		static void GenerateTimeStamp(char* a_buffer);

	private:
		BSLog* ctor(
			const char*   a_logName,
			const char*   a_logFolderPath,
			bool          a_timeStamped,
			std::uint32_t a_logNumber,
			std::uint32_t a_bufferSize,
			std::uint32_t a_blocks_allocated);

		void dtor();

	public:
		// members
		BSFixedString logName;         // 00
		BSFixedString logFolderPath;   // 08
		uint32_t      logNumber;       // 10
		uint32_t      bytesAllocated;  // 14
		BSSpinLock    writeLock;       // 18
		BSSystemFile  sysfile;         // 20
		std::uint64_t unk30;           // 30
		std::uint64_t unk38;           // 38
		std::byte     unk40[448];      // 40 -- likely a scrapheap
		bool          isAllocated;     // 200
		std::uint8_t  pad201;          // 201
		std::uint16_t pad202;          // 202
		std::uint32_t pad204;          // 204
		std::byte     unk208[0x32];    // 208
		int           unk240;          // 240
		bool          isInUse;         // 244
		bool          isActive;        // 245
		bool          timestamped;     // 246
		bool          unk247;          // 247
		std::byte     unk248[0x38];    // 248
	};
	static_assert(sizeof(BSLog) == 0x280);
}
