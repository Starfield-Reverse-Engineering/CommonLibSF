#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	enum class BSEventNotifyControl : std::uint32_t
	{
		kContinue,
		kStop
	};
	using EventResult = BSEventNotifyControl;

	namespace BSTEventDetail
	{
		class SinkBase
		{
		public:
			virtual ~SinkBase() = 0;
		};

		class SourceBase
		{
		public:
			virtual ~SourceBase() = 0;
		};

		inline SinkBase::~SinkBase() = default;
		inline SourceBase::~SourceBase() = default;
	}

	template <class>
	class BSTEventSource;

	template <class Event>
	class BSTEventSink : public BSTEventDetail::SinkBase
	{
	public:
		~BSTEventSink() override = default;  // 00

		// add
		virtual BSEventNotifyControl ProcessEvent(const Event& a_event, BSTEventSource<Event>* a_source) = 0;  // 01
	};
	static_assert(sizeof(BSTEventSink<void*>) == 0x8);

	template <class Event>
	class BSTEventSource : public BSTEventDetail::SourceBase
	{
	public:
		~BSTEventSource() override = default;  // 00

		void Notify(void* a_event)
		{
			using func_t = decltype(&BSTEventSource::Notify);
			REL::Relocation<func_t> func{ ID::BSTEventSource::Notify };
			return func(this, a_event);
		}
		void RegisterSink(BSTEventSink<Event>* a_sink)
		{
			using func_t = decltype(&BSTEventSource::RegisterSink);
			REL::Relocation<func_t> func{ ID::BSTEventSource::RegisterSink };
			return func(this, a_sink);
		}
		void UnregisterSink(BSTEventSink<Event>* a_sink)
		{
			using func_t = decltype(&BSTEventSource::UnregisterSink);
			REL::Relocation<func_t> func{ ID::BSTEventSource::UnregisterSink };
			return func(this, a_sink);
		}

		// members
		BSTArray<BSTEventSink<Event>> sinks;  // 08
		std::uint32_t                 unk18;  // 18
		std::uint32_t                 unk1C;  // 1C
		std::uint32_t                 unk20;  // 20
		std::uint32_t                 unk24;  // 24
	};
	static_assert(sizeof(BSTEventSource<void*>) == 0x28);

	class BSTGlobalEvent
	{
	public:
		template <class Event>
		class EventSource :
			public BSTSingletonImplicit<EventSource<Event>>,
			public BSTEventSource<Event>
		{
		public:
			~EventSource() override;  // 00

			virtual BSEventNotifyControl ProcessEvent(const Event& a_event, BSTEventSource<Event>* a_source);  // 01
		};

		virtual ~BSTGlobalEvent();  // 00
	};
	static_assert(sizeof(BSTGlobalEvent) == 0x08);

	template <class Event>
	class BSTEventSourceLazyInit
	{
	public:
		// members
		BSTEventSource<Event>* eventSource;  // 00
	};
	static_assert(sizeof(BSTEventSourceLazyInit<void*>) == 0x8);
}
