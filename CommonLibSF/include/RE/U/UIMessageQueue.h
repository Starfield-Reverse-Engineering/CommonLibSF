#pragma once

namespace RE
{
	enum UIMessage : uint32_t
	{
		kShow = 0,
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

		UIMessage type; //08
		//...more?
	};

	enum UI_MESSAGE_RESULT : int64_t
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
			REL::Relocation<UIMessageQueue**> singleton{ REL::ID(878637) };
			return *singleton;
		}

		int64_t AddMessage(const BSFixedString& a_menuName, UIMessage a_message)
		{
			using func_t = decltype(&UIMessageQueue::AddMessage);
			REL::Relocation<func_t> func{ REL::ID(187268) };
			return func(this, a_menuName, a_message);
		}
	};
}
