#pragma once

namespace RE
{
	class BSSystemFile
	{
	public:
		enum class ErrorCode : std::uint32_t
		{
			kOk = 0,
			kUnknownError = 1,
			kFileNotFound = 2,
			kAlreadyExists = 3,
			kPathNotFound = 4,
			kAccessDenied = 5,
			kOtherFileError = 6
		};

		enum class AccessMode : std::uint32_t
		{
			kRead = 0,
			kReadWrite = 1,
			kWriteOnly = 2
		};

		enum class OpenMode : std::uint32_t
		{
			kOpenExisting = 0,
			kOpenAlways = 1,
			kCreateAlways = 2,
			kTruncateExisting = 3,
			kCreateIfNotExist = 4
		};

		enum class ShareMode : std::uint32_t
		{
			kExclusive = 0,
			kShareRead = 1,
			kShareWrite = 2,
			kShareReadWrite = 3
		};

		enum class SeekMode : std::uint32_t
		{
			kBegin = 0,
			kCurrent = 1,
			kEnd = 2
		};

		~BSSystemFile();

		BSSystemFile();

		BSSystemFile(
			const char*                    a_path,
			AccessMode                     a_accessMode,
			OpenMode                       a_openMode,
			bool                           a_read,
			[[maybe_unused]] std::uint64_t a_unk1,
			bool                           a_write,
			ShareMode                      a_shareMode);

		explicit BSSystemFile(BSSystemFile& a_lhs);
		explicit BSSystemFile(BSSystemFile&& a_rhs);

		BSSystemFile& operator=(BSSystemFile& a_lhs);

		void      Flush();
		void      Invalidate();
		ErrorCode GetSize(std::uint64_t& r_size);
		ErrorCode GetErrorCode();
		ErrorCode Read(void* a_buffer, std::uint64_t a_toRead, std::uint64_t& r_read);
		ErrorCode Seek(std::int64_t a_offset, SeekMode a_seekMode, std::uint64_t& r_newPosition);
		void      SetErrorCode(ErrorCode a_errorCode);
		ErrorCode Truncate(std::uint64_t a_bytesToTruncate);
		ErrorCode Write(const void* a_buffer, std::uint64_t a_toWrite, std::uint64_t& r_written);

		static std::uint32_t RenameFile(const char* a_path, const char* a_replace);
		static std::uint32_t DeleteFileA(const char* a_path);

	private:
		void      DoClose();
		ErrorCode DoOpen(const char* a_path, AccessMode a_accessMode, OpenMode a_openMode, ShareMode a_shareMode);
		ErrorCode DoSeek(std::int64_t a_offset, SeekMode a_seekMode, std::uint64_t& r_newPosition);

		std::uint32_t flags;  // 00
		void*         file;   // 08
	};
	static_assert(sizeof(BSSystemFile) == 0x10);
}
