#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	class IMovementPlayerControlsFilter : public IMovementInterface
	{
	public:
		SF_RTTI(IMovementPlayerControlsFilter);

		~IMovementPlayerControlsFilter() override;  // 00

		// add
		virtual void Unk_01();  // 01
		virtual void Unk_02();  // 02
		virtual void Unk_03();  // 03
		virtual void Unk_04();  // 04
		virtual void Unk_05();  // 05
		virtual void Unk_06();  // 06
		virtual void Unk_07();  // 07
		virtual void Unk_08();  // 08
		virtual void Unk_09();  // 09
		virtual void Unk_0A();  // 0A
		virtual void Unk_0B();  // 0B
		virtual void Unk_0C();  // 0C
	};
	static_assert(sizeof(IMovementPlayerControlsFilter) == 0x8);
}
