#pragma once


namespace RE
{
	namespace detail
	{
		class SinkBase
		{
			virtual ~SinkBase() = 0;
		};
	}

	enum class BSEventNotifyControl : std::int32_t
	{
		kContinue,
		kStop
	};
	using EventResult = BSEventNotifyControl;

	template <class>
	class BSTEventSource;

	// 08
	template <typename Event>
	class BSTEventSink : public detail::SinkBase
	{
	public:
		virtual ~BSTEventSink() {};
		virtual BSEventNotifyControl ProcessEvent(const Event& a_event, [[maybe_unused]] BSTEventSource<Event>* a_source) { return EventResult::kContinue; };  // pure
	};

	template <typename T>
	class BSTEventSource
	{
	public:
		// Sinks go here
	};
}

