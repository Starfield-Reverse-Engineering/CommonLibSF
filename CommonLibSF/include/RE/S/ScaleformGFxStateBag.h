#pragma once

#include "RE/S/ScaleformGFxFileTypeConstants.h"
#include "RE/S/ScaleformGFxState.h"

namespace RE::Scaleform::GFx
{
	class StateBag :
		public FileTypeConstants  // 00
	{
	protected:
		// add
		virtual StateBag* GetStateBagImpl() const { return nullptr; }  // 00

	public:
		SF_RTTI_VTABLE(Scaleform__GFx__StateBag);

		virtual ~StateBag() = default;  // 01

		// add
		virtual void   SetState(State::StateType a_stateType, State* a_state);                                                // 02
		virtual State* GetStateAddRef(State::StateType a_stateType) const;                                                    // 03
		virtual void   GetStatesAddRef(State** a_states, const State::StateType* a_stateTypes, std::uint32_t a_count) const;  // 04
	};
	//static_assert(sizeof(StateBag) == 0x8);
}
