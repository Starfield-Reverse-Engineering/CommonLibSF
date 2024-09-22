#pragma once

#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class BSExtraData
	{
	public:
		SF_RTTI_VTABLE(BSExtraData);
		SF_EXTRADATATYPE(None);

		virtual ~BSExtraData();  // 00

		// add
		virtual void Unk_01();  // 01
		virtual void Unk_02();  // 02
		virtual void Unk_03();  // 03
		virtual void Unk_04();  // 04
		virtual void Unk_05();  // 05
		virtual void Unk_06();  // 06

		// members
		BSExtraData*                           next;   // 08
		std::uint16_t                          flags;  // 10
		REX::Enum<ExtraDataType, std::uint8_t> type;   // 12
	};
	static_assert(sizeof(BSExtraData) == 0x18);
}
