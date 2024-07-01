#pragma once

namespace RE
{
	class BSStorage;

	namespace BSScript
	{
		struct __declspec(novtable) IHandleReaderWriter
		{
		public:
			inline static constexpr auto RTTI = { RTTI::BSScript__IHandleReaderWriter };
			inline static constexpr auto VTABLE = { VTABLE::BSScript__IHandleReaderWriter };

			virtual ~IHandleReaderWriter();  // 0

			// add
			virtual std::uint16_t GetHandleVersion() const = 0;                                           // 142D8E390
			virtual bool          WriteHandle(BSStorage& storage, std::uint64_t) const = 0;               // 142D8E398
			virtual bool          ReadHandle(BSStorage const& storage, std::uint64_t&) const = 0;         // 142D8E3A0
			virtual bool          ReadHandleNoRemap(BSStorage const& storage, std::uint64_t&) const = 0;  // 142D8E3A8
		};
		static_assert(sizeof(IHandleReaderWriter) == 0x8);
	}
}
