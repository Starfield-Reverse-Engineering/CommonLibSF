#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	class IStoreAnimationActions : public IMovementInterface
	{
	public:
		SF_RTTI(IStoreAnimationActions);

		~IStoreAnimationActions() override;  // 00

		// add
		virtual void Unk_01();  // 01
		virtual void Unk_02();  // 02
		virtual void Unk_03();  // 03
	};
	static_assert(sizeof(IStoreAnimationActions) == 0x8);
}
