#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	namespace BSResource::Archive2
	{
		class StreamOpenedEvent;
	}

	class Sky;
	class TESActorBase;
	class TESObjectCELL;

	struct PositionPlayerEvent;

	class __declspec(novtable) TES :
		public BSTEventSink<BSResource::Archive2::StreamOpenedEvent>,  // 000
		public BSTEventSink<PositionPlayerEvent>                       // 008
	{
	public:
		SF_RTTI_VTABLE(TES);

		virtual ~TES();  // 00

		// override (BSTEventSink<BSResource::Archive2::StreamOpenedEvent>)
		BSEventNotifyControl ProcessEvent(const BSResource::Archive2::StreamOpenedEvent& a_event, BSTEventSource<BSResource::Archive2::StreamOpenedEvent>* a_eventSource) override;  // 01 - { return BSEventNotifyControl::kContinue; }

		// override (BSTEventSink<PositionPlayerEvent>)
		BSEventNotifyControl ProcessEvent(const PositionPlayerEvent& a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;  // 01

		[[nodiscard]] static TES* GetSingleton()
		{
			static REL::Relocation<TES**> singleton{ ID::TES::Singleton };
			return *singleton;
		}

		std::uint16_t GetDeadCount(TESActorBase* a_actorBase)
		{
			using func_t = decltype(&TES::GetDeadCount);
			static REL::Relocation<func_t> func{ ID::TES::GetDeadCount };
			return func(this, a_actorBase);
		}

		// members
		std::byte      pad010[0x18];  // 010
		Sky*           sky;           // 028
		std::byte      pad030[0xB8];  // 030
		TESObjectCELL* interiorCell;  // 0E8
	};
	static_assert(offsetof(TES, sky) == 0x28);
	static_assert(offsetof(TES, interiorCell) == 0xE8);
}
