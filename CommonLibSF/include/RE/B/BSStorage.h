#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSStorageDefs
	{
		enum class ErrorCode
		{
			kOK = 0,
			kError = 1,
			kNotImplemented = 2,
		};
		enum class SeekMode;
		struct StreamBuffer
		{
			void Reset()
			{
				ptrCur = buffer.GetPtr();
			}

			StreamBuffer() = delete;
			StreamBuffer(std::size_t a_size) :
				size(a_size),
				buffer(a_size, 8),
				ptrCur(buffer.GetPtr())
			{
			}

			std::size_t                    size;
			MemoryManager::AutoScrapBuffer buffer;
			void*                          ptrCur;
		};
	}

	class __declspec(novtable) BSStorage :
		public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = { RTTI::BSStorage };
		inline static constexpr auto VTABLE = { VTABLE::BSStorage };

		virtual ~BSStorage() = default;  // 00

		virtual std::size_t              GetSize() const = 0;                                                       // 01
		virtual std::size_t              GetPosition() const = 0;                                                   // 02
		virtual BSStorageDefs::ErrorCode Seek(std::size_t a_offset, BSStorageDefs::SeekMode a_seekMode) const = 0;  // 03
		virtual BSStorageDefs::ErrorCode Read(std::size_t a_numBytes, std::byte* a_bytes) const = 0;                // 04
		virtual BSStorageDefs::ErrorCode Write(std::size_t a_numBytes, const std::byte* a_bytes) = 0;               // 05

		template <typename T>
		BSStorageDefs::ErrorCode Write(T a_value)
			requires(std::is_arithmetic_v<T>)
		{
			if (usingStreambuffer && buf && PrepareStreamBuffer(sizeof(T)) == BSStorageDefs::ErrorCode::kOK) {
				*reinterpret_cast<T*>(buf->ptrCur) = a_value;
				buf->ptrCur = reinterpret_cast<std::byte*>(buf->ptrCur) + sizeof(T);
				return BSStorageDefs::ErrorCode::kOK;
			}
			return Write(sizeof(T), reinterpret_cast<const std::byte*>(&a_value));
		}

		template <typename T>
		BSStorageDefs::ErrorCode Write(const T& a_value)
			requires(!std::is_arithmetic_v<T>)
		{
			return Write(sizeof(T), reinterpret_cast<const std::byte*>(&a_value));
		}

		template <typename T>
		BSStorageDefs::ErrorCode Read(T& a_value)
		{
			return Read(sizeof(T), reinterpret_cast<std::byte*>(&a_value));
		}

		BSStorageDefs::ErrorCode WriteString(const char* a_string, bool use32bitLength)
		{
			using func_t = decltype(&BSStorage::WriteString);
			REL::Relocation<func_t> func{ ID::BSStorage::WriteString };
			return func(this, a_string, use32bitLength);
		}

		BSStorageDefs::ErrorCode PrepareStreamBuffer(std::size_t a_size)
		{
			using func_t = decltype(&BSStorage::PrepareStreamBuffer);
			REL::Relocation<func_t> func{ ID::BSStorage::PrepareStreamBuffer };
			return func(this, a_size);
		}

		BSStorageDefs::ErrorCode FlushStreamBuffer()
		{
			using func_t = decltype(&BSStorage::FlushStreamBuffer);
			REL::Relocation<func_t> func{ ID::BSStorage::FlushStreamBuffer };
			return func(this);
		}

		// members
		msvc::unique_ptr<BSStorageDefs::StreamBuffer> buf{ nullptr };          // 10
		bool                                          usingStreambuffer{ 0 };  // 18
	};
	static_assert(sizeof(BSStorage) == 0x20);
}
