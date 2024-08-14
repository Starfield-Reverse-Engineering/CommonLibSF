#pragma once

#include "RE/I/IMovementState.h"

namespace RE
{

	struct ActorState1
	{
	public:
		// members
		std::uint32_t     movingBack: 1;        // 0:00
		std::uint32_t     movingForward: 1;     // 0:01
		std::uint32_t     movingRight: 1;       // 0:02
		std::uint32_t     movingLeft: 1;        // 0:03
		std::uint32_t     unk04: 2;             // 0:04
		std::uint32_t     walking: 1;           // 0:06
		std::uint32_t     running: 1;           // 0:07
		std::uint32_t     sprinting: 1;         // 0:08
		std::uint32_t     sneaking: 1;          // 0:09
		std::uint32_t     swimming: 1;          // 0:10
	};

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
		ActorState1 actorState1;    // 08
		std::uint32_t actorState2;  // 0C
	};
	static_assert(sizeof(ActorState) == 0x10);
}
