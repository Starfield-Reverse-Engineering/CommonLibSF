#pragma once

#include "RE/I/IMovementState.h"

namespace RE
{
	class ActorState : public IMovementState
	{
	public:
		SF_RTTI(ActorState);

		~ActorState() override;  // 00

		// add
		virtual void Unk_31();  // 31
		virtual void Unk_32();  // 32
		virtual void Unk_33();  // 33
		virtual void Unk_34();  // 34

		// members
		std::uint32_t actorState1;  // 08
		std::uint32_t actorState2;  // 0C
	};
	static_assert(sizeof(ActorState) == 0x10);
}
