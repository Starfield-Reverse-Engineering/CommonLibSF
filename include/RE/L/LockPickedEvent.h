#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/E/ExtraLock.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESObjectREFR;
	class BGSTerminalMenu;

	struct LockPickedEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<LockPickedEvent>* GetEventSource()
		{
			using func_t = decltype(&LockPickedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::LockPickedEvent::GetEventSource };
			return func();
		}

		static void Notify(const NiPointer<TESObjectREFR>& a_actionRef, const NiPointer<TESObjectREFR>& a_lock, bool a_succeeded, bool a_isOffLimits, LOCK_LEVEL lockLevel, std::uint32_t a_numDigiPicksUsed, float a_arg7 = 0.0f, float a_arg8 = 0.0f, BGSTerminalMenu* a_terminalMenu = nullptr, std::int32_t a_arg10 = -1)
		{
			using func_t = decltype(&LockPickedEvent::Notify);
			static REL::Relocation<func_t> func{ ID::LockPickedEvent::Notify };
			return func(a_actionRef, a_lock, a_succeeded, a_isOffLimits, lockLevel, a_numDigiPicksUsed, a_arg7, a_arg8, a_terminalMenu, a_arg10);
		}

		// members
		NiPointer<TESObjectREFR>             actionRef;         // 00
		NiPointer<TESObjectREFR>             lock;              // 08
		BGSTerminalMenu*                     terminalMenu;      // 10
		std::int32_t                         unk18;             // 14 - terminalMenu related
		std::uint32_t                        numDigiPicksUsed;  // 18
		float                                unk20;             // 20 - 0.0f
		float                                unk24;             // 24 - 0.0f
		REX::Enum<LOCK_LEVEL, std::uint32_t> lockLevel;         // 28
		bool                                 succeeded;         // 2C
		bool                                 isOffLimits;       // 2D
	};
	static_assert(sizeof(LockPickedEvent) == 0x30);
}
