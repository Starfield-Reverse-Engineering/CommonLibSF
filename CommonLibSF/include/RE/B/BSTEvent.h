#pragma once

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

	template <class Event>
	class BSTEventSource : public BSTEventDetail::SourceBase
	{
	public:
		~BSTEventSource() override = default;  // 00
	};
}
