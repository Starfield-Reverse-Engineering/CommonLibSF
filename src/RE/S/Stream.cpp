#include "RE/S/Stream.h"

namespace RE::BSResource
{
	Stream::Stream() :
		Stream(0, false)
	{}

	Stream::Stream(std::uint32_t a_totalSize, bool writable) :
		StreamBase(a_totalSize, writable)
	{}

	Stream::Stream(const Stream& a_rhs) :
		StreamBase(a_rhs)
	{}

	Stream::Stream(Stream&& a_rhs) :
		StreamBase(std::move(a_rhs))
	{}

	ErrorCode Stream::DoSetEndOfStream()
	{
		return ErrorCode::kUnsupported;
	}

	ErrorCode Stream::DoPrefetchAt([[maybe_unused]] std::uint64_t a_v, [[maybe_unused]] std::uint64_t b_v, [[maybe_unused]] std::uint32_t c_v) const
	{
		return ErrorCode::kUnsupported;
	}

	ErrorCode Stream::DoPrefetchAll([[maybe_unused]] std::uint32_t a_v) const
	{
		return ErrorCode::kUnsupported;
	}

	ErrorCode Stream::DoStartTaggedPrioritizedRead([[maybe_unused]] void* a_buf,
		[[maybe_unused]] std::uint64_t                                    a_v,
		[[maybe_unused]] std::uint64_t                                    b_v,
		[[maybe_unused]] std::uint32_t                                    c_v,
		[[maybe_unused]] std::uint32_t volatile*                          d_v,
		[[maybe_unused]] std::uint32_t&                                   e_v,
		[[maybe_unused]] BSEventFlag*                                     event_flag) const
	{
		return ErrorCode::kUnsupported;
	}

	bool Stream::DoGetName(BSFixedString& a_dst) const
	{
		a_dst = "";
		return false;
	}

	ErrorCode Stream::DoCreateAsync(BSTSmartPointer<BSResource::AsyncStream>&) const
	{
		return ErrorCode::kUnsupported;
	}

	ErrorCode Stream::DoWaitTags([[maybe_unused]] volatile std::uint32_t* a_completionTag,
		[[maybe_unused]] BSEventFlag*                                     a_eventFlag,
		[[maybe_unused]] std::uint32_t                                    a_completionTagWaitValue) const
	{
		return ErrorCode::kUnsupported;
	}

	bool Stream::DoQTaggedPrioritizedReadSupported() const
	{
		return false;
	}

	ErrorCode Stream::DoReadAt([[maybe_unused]] void* a_buffer,
		[[maybe_unused]] std::uint64_t                a_offset,
		[[maybe_unused]] std::uint64_t                a_toRead,
		[[maybe_unused]] std::uint64_t&               a_read) const
	{
		return ErrorCode::kUnsupported;
	}

	// interface functions
	ErrorCode Stream::Read(void* a_buffer, std::uint64_t a_toRead, std::uint64_t& a_read) const
	{
		if ((flags & kWritable) != 0) {
			return ErrorCode::kUnsupported;
		}
		return DoRead(a_buffer, a_toRead, a_read);
	}

	ErrorCode Stream::ReadAt(void* a_buffer, std::uint64_t a_offset, std::uint64_t a_toRead, std::uint64_t& a_read) const
	{
		if ((flags & kWritable) != 0) {
			return ErrorCode::kUnsupported;
		}
		return DoReadAt(a_buffer, a_offset, a_toRead, a_read);
	}

	bool Stream::GetName(BSFixedString& a_dst) const
	{
		return DoGetName(a_dst);
	}

	ErrorCode Stream::Open(bool buffered, bool readFullHint)
	{
		uint32_t _flags = kUnk3;
		if (buffered) {
			_flags |= kBuffered;
		}
		if (readFullHint) {
			_flags |= kBuffered | kFullReadHint;
		}
		static std::atomic_ref myflags{ flags };
		uint32_t               old_flags = flags;
		while (!myflags.compare_exchange_strong(old_flags, (old_flags | _flags))) {
			old_flags = flags;
		}
		return DoOpen();
	}

	ErrorCode Stream::Seek(std::uint64_t a_toSeek, SeekMode a_mode, std::uint64_t& a_sought) const
	{
		return DoSeek(a_toSeek, a_mode, a_sought);
	}

	ErrorCode Stream::Write(const void* a_buffer, std::uint64_t a_toWrite, std::uint64_t& a_written) const
	{
		if ((flags & kWritable) != 0) {
			return DoWrite(a_buffer, a_toWrite, a_written);
		}
		return ErrorCode::kUnsupported;
	}

	ErrorCode Stream::CreateAsync(BSTSmartPointer<AsyncStream>& a_streamOut) const
	{
		return DoCreateAsync(a_streamOut);
	}

	ErrorCode Stream::PrefetchAll(std::uint32_t a_v) const
	{
		if ((flags & kWritable) != 0) {
			return ErrorCode::kUnsupported;
		}
		return DoPrefetchAll(a_v);
	}

	ErrorCode Stream::PrefetchAt(std::uint64_t a_v, std::uint64_t b_v, std::uint32_t c_v) const
	{
		if ((flags & kWritable) != 0) {
			return ErrorCode::kUnsupported;
		}
		return DoPrefetchAt(a_v, b_v, c_v);
	}

	std::uint32_t Stream::QFullReadHint() const
	{
		return flags & kFullReadHint;
	}

	bool Stream::QTaggedPrioritizedReadSupported() const
	{
		return DoQTaggedPrioritizedReadSupported();
	}

	ErrorCode Stream::StartTaggedPrioritizedRead(void* buf, std::uint64_t a_v, std::uint64_t b_v, std::uint32_t c_V, std::uint32_t volatile* d_v, std::uint32_t& e_v, BSEventFlag* event_flag) const
	{
		if ((flags & kWritable) != 0) {
			return ErrorCode::kUnsupported;
		}
		return DoStartTaggedPrioritizedRead(buf, a_v, b_v, c_V, d_v, e_v, event_flag);
	}

	ErrorCode Stream::WaitTags(volatile std::uint32_t* a_completionTag, BSEventFlag* a_eventFlag, std::uint32_t a_completionTagWaitValue) const
	{
		return DoWaitTags(a_completionTag, a_eventFlag, a_completionTagWaitValue);
	}

	std::uint32_t Stream::QBuffered() const
	{
		return flags & kBuffered;
	}

	ErrorCode Stream::SetEndOfStream()
	{
		return DoSetEndOfStream();
	}
}
