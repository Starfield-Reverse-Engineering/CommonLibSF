#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSStorage.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class __declspec(novtable) IStore : public BSStorage
		{
		public:
			SF_RTTI_VTABLE(BSScript__IStore);

			virtual ~IStore() = default;  // 00

			// override (BSStorage)
			BSStorageDefs::ErrorCode Write([[maybe_unused]] std::size_t a_numBytes, [[maybe_unused]] const std::byte* a_bytes) override  // 05
			{
				return BSStorageDefs::ErrorCode::kNotImplemented;
			};

			// add
			virtual bool                 Open(const char* a_fileName) = 0;  // 06
			virtual bool                 Close() = 0;                       // 07
			virtual const BSFixedString& StoreName() const = 0;             // 08
			virtual bool                 GetIsOpen() const = 0;             // 09
			virtual bool                 GetIsGood() const = 0;             // 0A
			virtual bool                 GetIsEOS() const = 0;              // 0B
		};
		static_assert(sizeof(IStore) == 0x20);
	}
}
