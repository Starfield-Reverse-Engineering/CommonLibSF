#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	struct IMovementStateStore : public IMovementInterface
	{
	public:
		SF_RTTI(IMovementStateStore);

		~IMovementStateStore() override;  // 00

		// add
		virtual void Unk_01();  // 01
	};
	static_assert(sizeof(IMovementStateStore) == 0x8);
}
