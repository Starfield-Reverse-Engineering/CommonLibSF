#include "RE/B/BSSystemFile.h"

#include "REX/W32/KERNEL32.h"

namespace RE
{
	BSSystemFile::BSSystemFile() :
		flags(1),
		file(REX::W32::INVALID_HANDLE_VALUE)
	{}

	BSSystemFile::~BSSystemFile()
	{
		DoClose();
	}

	BSSystemFile::BSSystemFile(
		const char*                    a_path,
		AccessMode                     a_accessMode,
		OpenMode                       a_openMode,
		bool                           a_read,
		[[maybe_unused]] std::uint64_t a_unk1,
		bool                           a_write,
		ShareMode                      a_shareMode) :
		file(REX::W32::INVALID_HANDLE_VALUE)
	{
		flags = 0;
		if (a_read) {
			flags |= REX::W32::GENERIC_READ;
		}
		if (a_write) {
			flags |= REX::W32::GENERIC_WRITE;
		}
		auto ret = DoOpen(a_path, a_accessMode, a_openMode, a_shareMode);
		SetErrorCode(ret);
	}

	BSSystemFile::BSSystemFile(BSSystemFile& a_lhs) :
		flags(a_lhs.flags),
		file(a_lhs.file)
	{
		a_lhs.Invalidate();
	}

	BSSystemFile::BSSystemFile(BSSystemFile&& a_rhs) :
		flags(a_rhs.flags),
		file(a_rhs.file)
	{
		a_rhs.Invalidate();
	}

	BSSystemFile& BSSystemFile::operator=(BSSystemFile& a_lhs)
	{
		// close the file if the handle is valid
		if (file != REX::W32::INVALID_HANDLE_VALUE) {
			DoClose();
		}
		file = a_lhs.file;
		flags = a_lhs.flags;
		a_lhs.Invalidate();
		return *this;
	}

	void BSSystemFile::Flush()
	{
		using func_t = decltype(&BSSystemFile::Flush);
		static REL::Relocation<func_t> func{ ID::BSSystemFile::Flush };
		return func(this);
	}

	void BSSystemFile::Invalidate()
	{
		file = REX::W32::INVALID_HANDLE_VALUE;
		flags = 1;
	}

	BSSystemFile::ErrorCode BSSystemFile::GetSize(std::uint64_t& r_size)
	{
		using func_t = decltype(&BSSystemFile::GetSize);
		static REL::Relocation<func_t> func{ ID::BSSystemFile::GetSize };
		return func(this, r_size);
	}

	BSSystemFile::ErrorCode BSSystemFile::GetErrorCode()
	{
		return static_cast<ErrorCode>(flags & 0x3FFFFFFF);
	}

	BSSystemFile::ErrorCode BSSystemFile::Read(void* a_buffer, std::uint64_t a_toRead, std::uint64_t& r_read)
	{
		using func_t = decltype(&BSSystemFile::Read);
		static REL::Relocation<func_t> func{ ID::BSSystemFile::Read };
		return func(this, a_buffer, a_toRead, r_read);
	}

	BSSystemFile::ErrorCode BSSystemFile::Seek(std::int64_t a_offset, SeekMode a_seekMode, std::uint64_t& r_newPosition)
	{
		// All usages of Seek were inlined
		auto ret = DoSeek(a_offset, a_seekMode, r_newPosition);
		SetErrorCode(ret);
		return ret;
	}

	void BSSystemFile::SetErrorCode(ErrorCode a_errorCode)
	{
		flags &= REX::W32::GENERIC_READ;
		flags |= static_cast<std::uint32_t>(a_errorCode);
	}

	BSSystemFile::ErrorCode BSSystemFile::Truncate(std::uint64_t a_bytesToTruncate)
	{
		using func_t = decltype(&BSSystemFile::Truncate);
		static REL::Relocation<func_t> func{ ID::BSSystemFile::Truncate };
		return func(this, a_bytesToTruncate);
	}

	BSSystemFile::ErrorCode BSSystemFile::Write(const void* a_buffer, std::uint64_t a_toWrite, std::uint64_t& r_written)
	{
		using func_t = decltype(&BSSystemFile::Write);
		static REL::Relocation<func_t> func{ ID::BSSystemFile::Write };
		return func(this, a_buffer, a_toWrite, r_written);
	}

	std::uint32_t BSSystemFile::RenameFile(const char* a_path, const char* a_replace)
	{
		using func_t = decltype(&BSSystemFile::RenameFile);
		static REL::Relocation<func_t> func{ ID::BSSystemFile::RenameFile };
		return func(a_path, a_replace);
	}

	std::uint32_t BSSystemFile::DeleteFileA(const char* a_path)
	{
		using func_t = decltype(&BSSystemFile::DeleteFileA);
		static REL::Relocation<func_t> func{ ID::BSSystemFile::DeleteFileA };  // TODO: ID changed
		return func(a_path);
	}

	void BSSystemFile::DoClose()
	{
		using func_t = decltype(&BSSystemFile::DoClose);
		static REL::Relocation<func_t> func{ ID::BSSystemFile::DoClose };
		return func(this);
	}

	BSSystemFile::ErrorCode BSSystemFile::DoOpen(
		const char* a_path,
		AccessMode  a_accessMode,
		OpenMode    a_openMode,
		ShareMode   a_shareMode)
	{
		using func_t = decltype(&BSSystemFile::DoOpen);
		static REL::Relocation<func_t> func{ ID::BSSystemFile::DoOpen };
		return func(this, a_path, a_accessMode, a_openMode, a_shareMode);
	}

	BSSystemFile::ErrorCode BSSystemFile::DoSeek(std::int64_t a_offset, SeekMode a_seekMode, std::uint64_t& r_newPosition)
	{
		using func_t = decltype(&BSSystemFile::DoSeek);
		static REL::Relocation<func_t> func{ ID::BSSystemFile::DoSeek };
		return func(this, a_offset, a_seekMode, r_newPosition);
	}
}
