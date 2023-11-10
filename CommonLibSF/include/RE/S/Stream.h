#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSResourceEnums.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/S/StreamBase.h"

namespace RE
{
	struct BSEventFlag;  // stub

	namespace BSResource
	{
		class AsyncStream;
		class CacheDrive;

		class __declspec(novtable) Stream :
			public StreamBase
		{
		public:
			SF_RTTI_VTABLE(BSResource__Stream);

			Stream();
			Stream(const Stream& a_rhs);
			Stream(Stream&& a_rhs);
			Stream(std::uint32_t a_totalSize, bool writable);
			~Stream() override = default;  // 00

			// add
			virtual void      DoClone(BSTSmartPointer<Stream>& a_result) const = 0;                                                                                                                                                                                     // 05
			virtual ErrorCode DoRead(void* a_buffer, std::uint64_t a_bytes, std::uint64_t& a_read) const = 0;                                                                                                                                                           // 06
			virtual ErrorCode DoReadAt(void* a_buffer, std::uint64_t a_bytes, std::uint64_t a_pos, std::uint64_t& a_read) const;                                                                                                                                        // 07
			virtual ErrorCode DoWrite(const void* a_buffer, std::uint64_t a_bytes, std::uint64_t& a_write) const = 0;                                                                                                                                                   // 08
			virtual ErrorCode DoSeek(std::int64_t a_offset, SeekMode a_seekMode, std::uint64_t& a_pos) const = 0;                                                                                                                                                       // 09
			virtual ErrorCode DoSetEndOfStream();                                                                                                                                                                                                                       // 0A
			virtual ErrorCode DoPrefetchAt(std::uint64_t a_bytes, std::uint64_t a_offset, std::uint32_t a_priority) const;                                                                                                                                              // 0B
			virtual ErrorCode DoStartTaggedPrioritizedRead(void* a_buffer, std::uint64_t a_bytes, std::uint64_t a_offset, std::uint32_t a_priority, volatile std::uint32_t* a_completionTag, std::uint32_t& a_completionTagWaitValue, BSEventFlag* a_eventFlag) const;  // 0C
			virtual ErrorCode DoWaitTags(volatile std::uint32_t* a_completionTag, BSEventFlag* a_eventFlag, std::uint32_t a_completionTagWaitValue) const;                                                                                                              // 0D
			virtual ErrorCode DoPrefetchAll(std::uint32_t a_priority) const;                                                                                                                                                                                            // 0E
			virtual bool      DoGetName(BSFixedString& a_result) const;                                                                                                                                                                                                 // 0F
			virtual ErrorCode DoCreateAsync(BSTSmartPointer<AsyncStream>& a_result) const;                                                                                                                                                                              // 10
			virtual bool      DoQTaggedPrioritizedReadSupported() const;                                                                                                                                                                                                // 11
			virtual bool      Unk_12() const;                                                                                                                                                                                                                           // 12 - { return false; }
			virtual ErrorCode Unk_13() const;                                                                                                                                                                                                                           // 13 - { return ErrorCode::kUnsupported; }
			virtual ErrorCode Unk_14() const;                                                                                                                                                                                                                           // 14 - { return ErrorCode::kUnsupported; }

			// non virtuals
			bool          GetName(BSFixedString& a_dst) const;
			ErrorCode     Open(bool buffered, bool fullReadHint);
			ErrorCode     Read(void* a_buffer, std::uint64_t a_toRead, std::uint64_t& a_read) const;
			ErrorCode     Seek(std::uint64_t a_toSeek, SeekMode a_mode, std::uint64_t& a_sought) const;
			ErrorCode     Write(const void* a_buffer, std::uint64_t a_toWrite, std::uint64_t& a_written) const;
			ErrorCode     ReadAt(void* a_buffer, std::uint64_t a_offset, std::uint64_t a_toRead, std::uint64_t& a_read) const;
			ErrorCode     CreateAsync(BSTSmartPointer<AsyncStream>& a_streamOut) const;
			ErrorCode     PrefetchAll(std::uint32_t a_v) const;
			ErrorCode     PrefetchAt(std::uint64_t a_v, std::uint64_t b_v, std::uint32_t c_v) const;
			std::uint32_t QFullReadHint() const;
			bool          QTaggedPrioritizedReadSupported() const;
			ErrorCode     StartTaggedPrioritizedRead(void* buf, std::uint64_t a_v, std::uint64_t b_v, std::uint32_t c_V, std::uint32_t volatile* d_v, std::uint32_t& e_v, BSEventFlag* event_flag) const;
			ErrorCode     WaitTags(volatile std::uint32_t* a_completionTag, BSEventFlag* a_eventFlag, std::uint32_t a_completionTagWaitValue) const;
			std::uint32_t QBuffered() const;
			ErrorCode     SetEndOfStream();
		};
		static_assert(sizeof(Stream) == 0x10);
	}
}