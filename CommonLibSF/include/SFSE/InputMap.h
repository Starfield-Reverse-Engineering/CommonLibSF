#pragma once

namespace SFSE::InputMap
{
	enum
	{
		// first 256 for keyboard, then 8 mouse buttons, then mouse wheel up, wheel down, then 16 gamepad buttons
		kMacro_KeyboardOffset = 0,  // not actually used, just for self-documentation
		kMacro_NumKeyboardKeys = 256,

		kMacro_MouseButtonOffset = kMacro_NumKeyboardKeys,  // 256
		kMacro_NumMouseButtons = 8,

		kMacro_MouseWheelOffset = kMacro_MouseButtonOffset + kMacro_NumMouseButtons,  // 264
		kMacro_MouseWheelDirections = 2,

		kMacro_GamepadOffset = kMacro_MouseWheelOffset + kMacro_MouseWheelDirections,  // 266
		kMacro_NumGamepadButtons = 16,

		kMaxMacros = kMacro_GamepadOffset + kMacro_NumGamepadButtons  // 282
	};

	enum
	{
		kGamepadButtonOffset_DPAD_UP = kMacro_GamepadOffset,  // 266
		kGamepadButtonOffset_DPAD_DOWN,
		kGamepadButtonOffset_DPAD_LEFT,
		kGamepadButtonOffset_DPAD_RIGHT,
		kGamepadButtonOffset_START,
		kGamepadButtonOffset_BACK,
		kGamepadButtonOffset_LEFT_THUMB,
		kGamepadButtonOffset_RIGHT_THUMB,
		kGamepadButtonOffset_LEFT_SHOULDER,
		kGamepadButtonOffset_RIGHT_SHOULDER,
		kGamepadButtonOffset_A,
		kGamepadButtonOffset_B,
		kGamepadButtonOffset_X,
		kGamepadButtonOffset_Y,
		kGamepadButtonOffset_LT,
		kGamepadButtonOffset_RT  // 281
	};

	std::uint32_t GamepadMaskToKeycode(std::uint32_t a_keyMask);
	std::uint32_t GamepadKeycodeToMask(std::uint32_t a_keyCode);

	std::string GetKeyName(std::uint32_t a_keyCode);
	std::string GetKeyboardKeyName(std::uint32_t a_keyCode);
	std::string GetMouseButtonName(std::uint32_t a_keyCode);
	std::string GetGamepadButtonName(std::uint32_t a_keyCode);
}
