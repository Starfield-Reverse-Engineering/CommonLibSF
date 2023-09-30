#pragma once

#include "REL/Relocation.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
    class BSInputDevice;

    class BSInputDeviceManager :
        public BSTSingletonSDM<BSInputDeviceManager>  // 00
    {
    public:
        enum class BS_DEVICES
        {
            kKeyboard,
            kMouse,
            kGamepad,
            kDebugGamepad,
            kVirtualKeyboard,

            kTotal
        };

        static BSInputDeviceManager* GetSingleton()
        {
            REL::Relocation<BSInputDeviceManager**> singleton{ REL::Offset(0x56F44B8) };//REL::ID(878418) };
            return *singleton;
        }

        BSInputDevice* GetGamepad() const noexcept
        {
            return devices[stl::to_underlying(INPUT_DEVICE::kGamepad)];
        }

        bool IsGamepadConnected() const
        {
            const auto gamepad = GetGamepad();
            return gamepad && gamepad->IsConnected();
        }

        // members
        BSInputDevice* devices[stl::to_underlying(INPUT_DEVICE::kTotal)];  // 08
        bool deviceLightStates[3];                                         // 30
        bool queuedGamepadEnableValue;                                     // 33
        bool valueQueued;                                                  // 34
        bool pollingEnabled;                                               // 35
    };
    static_assert(sizeof(BSInputDeviceManager) == 0x38);
}
