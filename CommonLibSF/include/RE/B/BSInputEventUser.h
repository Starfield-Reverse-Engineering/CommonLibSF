#pragma once

#include "RE/M/MemoryManager.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	class ButtonEvent;
	class CharacterEvent;
	class CursorMoveEvent;
	class DeviceConnectEvent;
	class InputEvent;
	class KinectEvent;
	class MouseMoveEvent;
	class ThumbstickEvent;

	class InputEvent
	{
	public:
		enum DeviceType : uint32_t
		{
			DeviceKeyboard = 0,
			DeviceMouse,
			DeviceGamepad,
			DeviceKinect,
		};

		enum EventType : uint32_t
		{
			Button = 0,
			MouseMove,
			CursorMove,
			Char,
			Thumbstick,
			DeviceConnect,
			Kinect,
			None,
		};

		enum Status : uint32_t
		{
			Unhandled = 0,
			Continue,
			Stop,
		};

		virtual ~InputEvent() = default;  //00
		virtual bool          Unk01() { return false; }
		virtual BSFixedString GetUserEventOrDisabled() { return ""; }

		uint32_t    deviceType;  //08
		uint32_t    deviceId;
		uint32_t    eventType;  //10
		uint32_t    pad14;
		InputEvent* next;      //18
		uint32_t    timeCode;  //20
		uint32_t    status;
	};

	class IDEvent : public InputEvent
	{
	public:
		virtual ~IDEvent() = default;
		BSFixedString userEvent;  //28
		uint32_t      idCode;     //30
		bool          disabled;   //34
	};

	class ButtonEvent : public IDEvent
	{
	public:
		virtual ~ButtonEvent() = default;
		void* iCanBeDebounced;  //38
		void* iCanBeChorded;    //40
		float value;            //48
		float held;             //4C
		void* unk50;
		void* bsDebounceManager;
	};

	class BSInputEventUser
	{
	public:
		SF_RTTI_VTABLE(BSInputEventUser);

		virtual ~BSInputEventUser() = default;  // 00

		// add
		virtual bool ShouldHandleEvent(const InputEvent*) { return false; }  // 01
		virtual void HandleEvent(const KinectEvent*) { return; }             // 02
		virtual void HandleEvent(const DeviceConnectEvent*) { return; }      // 03
		virtual void HandleEvent(const ThumbstickEvent*) { return; }         // 04
		virtual void HandleEvent(const CursorMoveEvent*) { return; }         // 05
		virtual void HandleEvent(const MouseMoveEvent*) { return; }          // 06
		virtual void HandleEvent(const CharacterEvent*) { return; }          // 07
		virtual void HandleEvent(const ButtonEvent*) { return; }             // 08
		virtual void InputEventUser_Unk_09(const InputEvent* a_event)        // 09
		{
			using func_t = decltype(&BSInputEventUser::InputEventUser_Unk_09);
			REL::Relocation<func_t> func(REL::ID(178899));
			return func(this, a_event); 
		}  

		SF_HEAP_REDEFINE_NEW(BSInputEventUser);

		// members
		std::uint8_t pad08[0x30];                        // 08
		bool         inputEventHandlingEnabled{ true };  // 38
	};
	static_assert(sizeof(BSInputEventUser) == 0x40);
}
