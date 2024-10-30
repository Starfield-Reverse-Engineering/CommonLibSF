#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	enum class UI_MESSAGE_TYPE : std::uint32_t
	{
		kShow = 0,
		kUpdate = 1,
		kHide = 2
	};

	class IUIMessageData
	{
	public:
		virtual ~IUIMessageData() = default;

		virtual void* GetRTTI() = 0;
	};

	class UIMessageData
	{
	public:
		virtual ~UIMessageData() = default;

		UI_MESSAGE_TYPE type;  // 08
							   //...more?
	};

	enum UI_MESSAGE_RESULT : std::int64_t
	{
		kHandled = 0,
		kIgnore,
		kPassOn
	};

	class UIMessageQueue
	{
	public:
		static UIMessageQueue* GetSingleton()
		{
			static REL::Relocation<UIMessageQueue**> singleton{ ID::UIMessageQueue::Singleton };
			return *singleton;
		}

		std::int64_t AddMessage(const BSFixedString& a_menuName, UI_MESSAGE_TYPE a_type)
		{
			using func_t = decltype(&UIMessageQueue::AddMessage);
			static REL::Relocation<func_t> func{ ID::UIMessageQueue::AddMessage };
			return func(this, a_menuName, a_type);
		}
	};
}
