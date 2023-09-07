#pragma once

// TODO: This should probably be behind some sort of pragma that allows linking with xinput
namespace RE::XInput
{
	struct __XINPUT_GAMEPAD
	{
		std::uint16_t wButtons;
		std::byte     bLeftTrigger;
		std::byte     bRightTrigger;
		std::int16_t  sThumbLX;
		std::int16_t  sThumbLY;
		std::int16_t  sThumbRX;
		std::int16_t  sThumbRY;
	};
	using XINPUT_GAMEPAD = __XINPUT_GAMEPAD;
	struct __XINPUT_STATE
	{
		std::uint32_t    dwPacketNumber;
		__XINPUT_GAMEPAD Gamepad;
	};
	using XINPUT_STATE = __XINPUT_STATE;
	struct __XINPUT_KEYSTROKE
	{
		std::uint16_t VirtualKey;
		std::uint16_t Unicode;
		std::uint16_t Flags;
		std::uint8_t  UserIndex;
		std::uint8_t  HidCode;
	};
	using XINPUT_KEYSTROKE = __XINPUT_KEYSTROKE;
	struct __XINPUT_VIBRATION
	{
		std::uint16_t wLeftMotorSpeed;
		std::uint16_t wRightMotorSpeed;
	};
	using XINPUT_VIBRATION = __XINPUT_VIBRATION;

	struct __XINPUT_CAPABILITIES
	{
		std::uint8_t     Type;
		std::uint8_t     SubType;
		std::uint16_t    Flags;
		XINPUT_GAMEPAD   Gamepad;
		XINPUT_VIBRATION Vibration;
	};
	using XINPUT_CAPABILITIES = __XINPUT_CAPABILITIES;

	enum XInputButton : std::uint16_t
	{
		XINPUT_GAMEPAD_DPAD_UP = 0x0001,
		XINPUT_GAMEPAD_DPAD_DOWN = 0x0002,
		XINPUT_GAMEPAD_DPAD_LEFT = 0x0004,
		XINPUT_GAMEPAD_DPAD_RIGHT = 0x0008,
		XINPUT_GAMEPAD_START = 0x0010,
		XINPUT_GAMEPAD_BACK = 0x0020,
		XINPUT_GAMEPAD_LEFT_THUMB = 0x0040,
		XINPUT_GAMEPAD_RIGHT_THUMB = 0x0080,
		XINPUT_GAMEPAD_LEFT_SHOULDER = 0x0100,
		XINPUT_GAMEPAD_RIGHT_SHOULDER = 0x0200,
		XINPUT_GAMEPAD_A = 0x1000,
		XINPUT_GAMEPAD_B = 0x2000,
		XINPUT_GAMEPAD_X = 0x4000,
		XINPUT_GAMEPAD_Y = 0x8000
	};
	static constexpr std::uint16_t XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE = 7849;
	static constexpr std::uint16_t XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE = 8689;
	static constexpr std::uint8_t  XINPUT_GAMEPAD_TRIGGER_THRESHOLD = 30;

	static constexpr std::uint16_t XINPUT_BUTTON_MASK = XINPUT_GAMEPAD_DPAD_UP |
	                                                    XINPUT_GAMEPAD_DPAD_DOWN |
	                                                    XINPUT_GAMEPAD_DPAD_LEFT |
	                                                    XINPUT_GAMEPAD_DPAD_RIGHT |
	                                                    XINPUT_GAMEPAD_START |
	                                                    XINPUT_GAMEPAD_BACK |
	                                                    XINPUT_GAMEPAD_LEFT_THUMB |
	                                                    XINPUT_GAMEPAD_RIGHT_THUMB |
	                                                    XINPUT_GAMEPAD_LEFT_SHOULDER |
	                                                    XINPUT_GAMEPAD_RIGHT_SHOULDER |
	                                                    XINPUT_GAMEPAD_A |
	                                                    XINPUT_GAMEPAD_B |
	                                                    XINPUT_GAMEPAD_X |
	                                                    XINPUT_GAMEPAD_Y;
}
