#include "RE/B/BSLog.h"

namespace RE
{
	BSLog::BSLog(
		const char*   a_logName,
		const char*   a_logFolderPath,
		bool          a_timeStamped,
		std::uint32_t a_logNumber,
		std::uint32_t a_bufferSize,
		std::uint32_t a_blocks_allocated)
	{
		ctor(a_logName, a_logFolderPath, a_timeStamped, a_logNumber, a_bufferSize, a_blocks_allocated);
	}

	BSLog::~BSLog()
	{
		dtor();
	}

	BSLog* BSLog::ctor(const char* a_logName, const char* a_logFolderPath, bool a_timeStamped, std::uint32_t a_logNumber, std::uint32_t a_bufferSize, std::uint32_t a_blocks_allocated)
	{
		using func_t = decltype(&BSLog::ctor);
		static REL::Relocation<func_t> func{ ID::BSLog::ctor };
		return func(this, a_logName, a_logFolderPath, a_timeStamped, a_logNumber, a_bufferSize, a_blocks_allocated);
	}

	void BSLog::dtor()
	{
		using func_t = decltype(&BSLog::dtor);
		static REL::Relocation<func_t> func{ ID::BSLog::dtor };
		return func(this);
	}

	void BSLog::CycleLog()
	{
		using func_t = decltype(&BSLog::CycleLog);
		static REL::Relocation<func_t> func{ ID::BSLog::CycleLog };
		return func(this);
	}

	void BSLog::FlushBuffer(bool forceFlush)
	{
		using func_t = decltype(&BSLog::FlushBuffer);
		static REL::Relocation<func_t> func{ ID::BSLog::FlushBuffer };
		return func(this, forceFlush);
	}

	void BSLog::FlushBufferToFile(bool forceFlush)
	{
		using func_t = decltype(&BSLog::FlushBufferToFile);
		static REL::Relocation<func_t> func{ ID::BSLog::FlushBufferToFile };
		return func(this, forceFlush);
	}

	void BSLog::WriteEntry(const char* a_string, bool shouldFlush)
	{
		using func_t = decltype(&BSLog::WriteEntry);
		static REL::Relocation<func_t> func{ ID::BSLog::WriteEntry };
		return func(this, a_string, shouldFlush);
	}

	void BSLog::WriteData(char* data, std::uint32_t size, bool shouldFlush)
	{
		using func_t = decltype(&BSLog::WriteData);
		static REL::Relocation<func_t> func{ ID::BSLog::WriteData };
		return func(this, data, size, shouldFlush);
	}

	void BSLog::MakeLogFilename(char* a_name, const char* a_dir, std::uint32_t a_logNumber, BSFixedString& r_fileName, bool a_appendLogNumber)
	{
		using func_t = decltype(&BSLog::MakeLogFilename);
		static REL::Relocation<func_t> func{ ID::BSLog::MakeLogFilename };
		return func(a_name, a_dir, a_logNumber, r_fileName, a_appendLogNumber);
	}

	void BSLog::GenerateTimeStamp(char* a_buffer)
	{
		using func_t = decltype(&BSLog::GenerateTimeStamp);
		static REL::Relocation<func_t> func{ ID::BSLog::GenerateTimeStamp };
		return func(a_buffer);
	}
}
