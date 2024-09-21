#pragma once

#include "REX/W32/BASE.h"

namespace RE::BSResource
{
	enum class ErrorCode : std::uint32_t
	{
		kNone = 0,
		kNotExist = 1,
		kInvalidPath = 2,
		kFileError = 3,
		kInvalidType = 4,
		kMemoryError = 5,
		kBusy = 6,
		kInvalidParam = 7,
		kUnsupported = 8
	};

	enum class SeekMode
	{
		kSet = 0,
		kCurrent = 1,
		kEnd = 2
	};

	struct FileID
	{
	public:
		[[nodiscard]] bool operator==(const FileID&) const noexcept = default;

		// members
		std::uint32_t file = 0;  // 0
		std::uint32_t ext = 0;   // 4
	};
	static_assert(sizeof(FileID) == 0x8);

	struct ID :
		public FileID  // 0
	{
	public:
		[[nodiscard]] bool operator==(const ID&) const noexcept = default;

		// members
		std::uint32_t dir = 0;  // 8
	};
	static_assert(sizeof(BSResource::ID) == 0xC);

	struct Info
	{
	public:
		// members
		REX::W32::FILETIME modifyTime;  // 00
		REX::W32::FILETIME createTime;  // 08
		std::uint64_t      fileSize;    // 10
	};
	static_assert(sizeof(Info) == 0x18);
}
