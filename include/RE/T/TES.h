#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	namespace BSResource::Archive2
	{
		class StreamOpenedEvent;
	}

	class TESObjectCELL;

	struct PositionPlayerEvent;

	class TES :
		public BSTEventSink<BSResource::Archive2::StreamOpenedEvent>,  // 000
		public BSTEventSink<PositionPlayerEvent>                       // 008
	{
	public:
		SF_RTTI_VTABLE(TES);

		virtual ~TES();  // 00

		// override (BSTEventSink<BSResource::ArchiveStreamOpenedEvent>)
		BSEventNotifyControl ProcessEvent(const BSResource::Archive2::StreamOpenedEvent& a_event, BSTEventSource<BSResource::Archive2::StreamOpenedEvent>* a_eventSource) override;  // 01 - { return BSEventNotifyControl::kContinue; }

		// override (BSTEventSink<PositionPlayerEvent>)
		BSEventNotifyControl ProcessEvent(const PositionPlayerEvent& a_event, BSTEventSource<PositionPlayerEvent>* a_eventSource) override;  // 01

		[[nodiscard]] static TES* GetSingleton()
		{
			static REL::Relocation<TES**> singleton{ ID::TES::Singleton };
			return *singleton;
		}

		// members
		std::byte      pad[0xD8];     // 010
		TESObjectCELL* interiorCell;  // 0E8
	};
	static_assert(offsetof(TES, interiorCell) == 0xE8);
}
