#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/M/MemoryManager.h"

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
		SF_RTTI(InputEvent);

		enum class DeviceType : std::uint32_t
		{
			kNone = static_cast<std::underlying_type_t<DeviceType>>(-1),

			kKeyboard = 0,
			kMouse,
			kGamepad,
			kKinect,
		};

		enum class EventType : std::uint32_t
		{
			kButton = 0,
			kMouseMove,
			kCursorMove,
			kChar,
			kThumbstick,
			kDeviceConnect,
			kKinect,
			kNone,
		};

		enum class Status : std::uint32_t
		{
			kUnhandled = 0,
			kContinue,
			kStop,
		};

		virtual ~InputEvent() = default;  // 00

		// add
		virtual bool                HasIDCode() const { return false; }
		virtual const BSFixedString QUserEvent() const { return ""; }

		// members
		DeviceType    deviceType{ DeviceType::kNone };             // 08
		std::uint32_t deviceID{ 0 };                               // 0C
		EventType     eventType{ EventType::kNone };               // 10
		std::uint32_t pad14;                                       // 14
		InputEvent*   next{ nullptr };                             // 18
		std::uint32_t timeCode{ static_cast<std::uint32_t>(-1) };  // 20
		Status        status{ Status::kUnhandled };                // 24
	};
	static_assert(sizeof(InputEvent) == 0x28);

	class IDEvent :
		public InputEvent
	{
	public:
		SF_RTTI_VTABLE(IDEvent);

		virtual ~IDEvent() = default;  // 00

		// override (InputEvent)
		virtual bool HasIDCode() const override { return true; }

		virtual const BSFixedString QUserEvent() const override
		{
			return disabled ? "DISABLED" : strUserEvent;
		}

		// members
		BSFixedString strUserEvent;       // 28
		std::int32_t  idCode{ -1 };       // 30
		bool          disabled{ false };  // 34
	};
	static_assert(sizeof(IDEvent) == 0x38);

	class ICanBeChorded
	{
	public:
		SF_RTTI(ICanBeChorded);

		// members
		std::uint64_t pad00;
	};

	class ICanBeDebounced :
		public ICanBeChorded
	{
	public:
		SF_RTTI(ICanBeDebounced);

		// members
		std::uint64_t pad00;
	};

	class ButtonEvent :
		public IDEvent,
		public ICanBeDebounced
	{
	public:
		SF_RTTI_VTABLE(ButtonEvent);

		virtual ~ButtonEvent() = default;  // 00

		// members
		float value{ 0.0f };         // 48
		float heldDownSecs{ 0.0f };  // 4C
		void* unk50;                 // 50
		void* debounceManager;       // 58
	};
	static_assert(sizeof(ButtonEvent) == 0x60);

	class BSInputEventUser
	{
	public:
		SF_RTTI_VTABLE(BSInputEventUser);

		virtual ~BSInputEventUser() = default;  // 00

		// add
		virtual bool ShouldHandleEvent(const InputEvent*) { return false; }       // 01
		virtual void OnKinectEvent(const KinectEvent*) { return; }                // 02
		virtual void OnDeviceConnectEvent(const DeviceConnectEvent*) { return; }  // 03
		virtual void OnThumbstickEvent(const ThumbstickEvent*) { return; }        // 04
		virtual void OnCursorMoveEvent(const CursorMoveEvent*) { return; }        // 05
		virtual void OnMouseMoveEvent(const MouseMoveEvent*) { return; }          // 06
		virtual void OnCharacterEvent(const CharacterEvent*) { return; }          // 07
		virtual void OnButtonEvent(const ButtonEvent*) { return; }                // 08

		virtual void InputEventUser_Unk09(const InputEvent* a_event)  // 09
		{
			using func_t = decltype(&BSInputEventUser::InputEventUser_Unk09);
			static REL::Relocation<func_t> func(REL::ID(178899));
			return func(this, a_event);
		}

		SF_HEAP_REDEFINE_NEW(BSInputEventUser);

		// members
		std::uint8_t pad08[0x30];                        // 08
		bool         inputEventHandlingEnabled{ true };  // 38
	};
	static_assert(sizeof(BSInputEventUser) == 0x40);
}
