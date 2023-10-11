#include "SFSE/InputMap.h"

#include "SFSE/Impl/XInputAPI.h"

namespace SFSE
{
	std::uint32_t InputMap::GamepadMaskToKeycode(const std::uint32_t a_keyMask)
	{
		using XInputButton = RE::XInput::XInputButton;
		switch (a_keyMask) {
		case XInputButton::XINPUT_GAMEPAD_DPAD_UP:
			return kGamepadButtonOffset_DPAD_UP;
		case XInputButton::XINPUT_GAMEPAD_DPAD_DOWN:
			return kGamepadButtonOffset_DPAD_DOWN;
		case XInputButton::XINPUT_GAMEPAD_DPAD_LEFT:
			return kGamepadButtonOffset_DPAD_LEFT;
		case XInputButton::XINPUT_GAMEPAD_DPAD_RIGHT:
			return kGamepadButtonOffset_DPAD_RIGHT;
		case XInputButton::XINPUT_GAMEPAD_START:
			return kGamepadButtonOffset_START;
		case XInputButton::XINPUT_GAMEPAD_BACK:
			return kGamepadButtonOffset_BACK;
		case XInputButton::XINPUT_GAMEPAD_LEFT_THUMB:
			return kGamepadButtonOffset_LEFT_THUMB;
		case XInputButton::XINPUT_GAMEPAD_RIGHT_THUMB:
			return kGamepadButtonOffset_RIGHT_THUMB;
		case XInputButton::XINPUT_GAMEPAD_LEFT_SHOULDER:
			return kGamepadButtonOffset_LEFT_SHOULDER;
		case XInputButton::XINPUT_GAMEPAD_RIGHT_SHOULDER:
			return kGamepadButtonOffset_RIGHT_SHOULDER;
		case XInputButton::XINPUT_GAMEPAD_A:
			return kGamepadButtonOffset_A;
		case XInputButton::XINPUT_GAMEPAD_B:
			return kGamepadButtonOffset_B;
		case XInputButton::XINPUT_GAMEPAD_X:
			return kGamepadButtonOffset_X;
		case XInputButton::XINPUT_GAMEPAD_Y:
			return kGamepadButtonOffset_Y;
		case 0x9:  // Left Trigger game-defined ID
			return kGamepadButtonOffset_LT;
		case 0xA:  // Right Trigger game-defined ID
			return kGamepadButtonOffset_RT;
		default:
			return kMaxMacros;  // Invalid
		}
	}

	std::uint32_t InputMap::GamepadKeycodeToMask(const std::uint32_t a_keyCode)
	{
		using XInputButton = RE::XInput::XInputButton;

		switch (a_keyCode) {
		case kGamepadButtonOffset_DPAD_UP:
			return XInputButton::XINPUT_GAMEPAD_DPAD_UP;
		case kGamepadButtonOffset_DPAD_DOWN:
			return XInputButton::XINPUT_GAMEPAD_DPAD_DOWN;
		case kGamepadButtonOffset_DPAD_LEFT:
			return XInputButton::XINPUT_GAMEPAD_DPAD_LEFT;
		case kGamepadButtonOffset_DPAD_RIGHT:
			return XInputButton::XINPUT_GAMEPAD_DPAD_RIGHT;
		case kGamepadButtonOffset_START:
			return XInputButton::XINPUT_GAMEPAD_START;
		case kGamepadButtonOffset_BACK:
			return XInputButton::XINPUT_GAMEPAD_BACK;
		case kGamepadButtonOffset_LEFT_THUMB:
			return XInputButton::XINPUT_GAMEPAD_LEFT_THUMB;
		case kGamepadButtonOffset_RIGHT_THUMB:
			return XInputButton::XINPUT_GAMEPAD_RIGHT_THUMB;
		case kGamepadButtonOffset_LEFT_SHOULDER:
			return XInputButton::XINPUT_GAMEPAD_LEFT_SHOULDER;
		case kGamepadButtonOffset_RIGHT_SHOULDER:
			return XInputButton::XINPUT_GAMEPAD_RIGHT_SHOULDER;
		case kGamepadButtonOffset_A:
			return XInputButton::XINPUT_GAMEPAD_A;
		case kGamepadButtonOffset_B:
			return XInputButton::XINPUT_GAMEPAD_B;
		case kGamepadButtonOffset_X:
			return XInputButton::XINPUT_GAMEPAD_X;
		case kGamepadButtonOffset_Y:
			return XInputButton::XINPUT_GAMEPAD_Y;
		case kGamepadButtonOffset_LT:
			return 0x9;  // Left Trigger game-defined ID
		case kGamepadButtonOffset_RT:
			return 0xA;  // Right Trigger game-defined ID
		default:
			return 0xFF;  // Invalid
		}
	}

	std::string InputMap::GetKeyName(const std::uint32_t a_keyCode)
	{
		if (a_keyCode >= kMacro_MouseButtonOffset && a_keyCode < kMacro_GamepadOffset) {
			return GetMouseButtonName(a_keyCode);
		}
		if (a_keyCode >= kMacro_GamepadOffset && a_keyCode < kMaxMacros) {
			return GetGamepadButtonName(a_keyCode);
		}
		return GetKeyboardKeyName(a_keyCode);
	}

	std::string InputMap::GetKeyboardKeyName(const std::uint32_t a_keyCode)
	{
		std::int32_t scancode = static_cast<std::int32_t>(a_keyCode & 0xFF);

		using DIKey = RE::DirectInput8::DIKey;

		switch (scancode) {
		case DIKey::DIK_NUMPADENTER:  // Numpad Enter
			scancode = 0x11C;
			break;
		case DIKey::DIK_RCONTROL:  // Right Control
			scancode = 0x11D;
			break;
		case DIKey::DIK_DIVIDE:  // Numpad /
			scancode = 0x135;
			break;
		case DIKey::DIK_RALT:  // Right Alt
			scancode = 0x138;
			break;
		case DIKey::DIK_HOME:  // Home
			scancode = 0x147;
			break;
		case DIKey::DIK_UPARROW:  // Up Arrow
			scancode = 0x148;
			break;
		case DIKey::DIK_PGUP:  // Page Up
			scancode = 0x149;
			break;
		case DIKey::DIK_LEFTARROW:  // Left Arrow
			scancode = 0x14B;
			break;
		case DIKey::DIK_RIGHTARROW:  // Right Arrow
			scancode = 0x14D;
			break;
		case DIKey::DIK_END:  // End
			scancode = 0x14F;
			break;
		case DIKey::DIK_DOWNARROW:  // Down Arrow
			scancode = 0x150;
			break;
		case DIKey::DIK_PGDN:  // Page Down
			scancode = 0x151;
			break;
		case DIKey::DIK_INSERT:  // Insert
			scancode = 0x152;
			break;
		case DIKey::DIK_DELETE:  // Delete
			scancode = 0x153;
			break;
		}

		std::int32_t lParam = scancode << 16;

		if (scancode == 0x45) {
			lParam |= (0x1 << 24);
		}

		wchar_t            buffer[WinAPI::MAX_PATH];
		const auto         length = WinAPI::GetKeyNameText(lParam, buffer, WinAPI::MAX_PATH);
		const std::wstring keyNameW{ buffer, static_cast<std::size_t>(length) };

		return stl::utf16_to_utf8(keyNameW).value_or(""s);
	}

	std::string InputMap::GetMouseButtonName(const std::uint32_t a_keyCode)
	{
		switch (a_keyCode) {
		case 256:
			return "Left Mouse Button"s;
		case 257:
			return "Right Mouse Button"s;
		case 258:
			return "Middle Mouse Button"s;
		case 259:
			return "Mouse Button 3"s;
		case 260:
			return "Mouse Button 4"s;
		case 261:
			return "Mouse Button 5"s;
		case 262:
			return "Mouse Button 6"s;
		case 263:
			return "Mouse Button 7"s;
		case 264:
			return "Mouse Wheel Up"s;
		case 265:
			return "Mouse Wheel Down"s;
		default:
			return ""s;
		}
	}

	std::string InputMap::GetGamepadButtonName(const std::uint32_t a_keyCode)
	{
		switch (a_keyCode) {
		case kGamepadButtonOffset_DPAD_UP:
			return "Gamepad DPad Up"s;
		case kGamepadButtonOffset_DPAD_DOWN:
			return "Gamepad DPad Down"s;
		case kGamepadButtonOffset_DPAD_LEFT:
			return "Gamepad DPad Left"s;
		case kGamepadButtonOffset_DPAD_RIGHT:
			return "Gamepad DPad Right"s;
		case kGamepadButtonOffset_START:
			return "Gamepad Start"s;
		case kGamepadButtonOffset_BACK:
			return "Gamepad Back"s;
		case kGamepadButtonOffset_LEFT_THUMB:
			return "Gamepad Left Thumb"s;
		case kGamepadButtonOffset_RIGHT_THUMB:
			return "Gamepad Right Thumb"s;
		case kGamepadButtonOffset_LEFT_SHOULDER:
			return "Gamepad Left Shoulder"s;
		case kGamepadButtonOffset_RIGHT_SHOULDER:
			return "Gamepad Right Shoulder"s;
		case kGamepadButtonOffset_A:
			return "Gamepad A"s;
		case kGamepadButtonOffset_B:
			return "Gamepad B"s;
		case kGamepadButtonOffset_X:
			return "Gamepad X"s;
		case kGamepadButtonOffset_Y:
			return "Gamepad Y"s;
		case kGamepadButtonOffset_LT:
			return "Gamepad LT"s;
		case kGamepadButtonOffset_RT:
			return "Gamepad RT"s;
		default:
			return ""s;
		}
	}
}
