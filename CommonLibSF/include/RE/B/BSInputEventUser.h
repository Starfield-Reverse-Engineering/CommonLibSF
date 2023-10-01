#pragma once

namespace RE
{
	class BSInputEventUser
	{
	public:
		SF_RTTI_VTABLE(BSInputEventUser);

		virtual ~BSInputEventUser() = default;  // 00

		// add
		virtual void Unk_01(void);  // 01
		virtual void Unk_02(void);  // 02
		virtual void Unk_03(void);  // 03
		virtual void Unk_04(void);  // 04
		virtual void Unk_05(void);  // 05
		virtual void Unk_06(void);  // 06
		virtual void Unk_07(void);  // 07
		virtual void Unk_08(void);  // 08
		virtual void Unk_09(void);  // 09

		// members
		std::uint8_t pad08[0x30];                        // 08
		bool         inputEventHandlingEnabled{ true };  // 38
	};
	static_assert(sizeof(BSInputEventUser) == 0x40);
}
