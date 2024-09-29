#include "RE/M/Misc.h"

#include "RE/I/INIPrefSettingCollection.h"
#include "RE/I/INISettingCollection.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/S/Setting.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	void DebugNotification(const char* a_notification, const char* a_soundToPlay, bool a_cancelIfAlreadyQueued, bool a_arg4)
	{
		using func_t = decltype(&DebugNotification);
		static REL::Relocation<func_t> func{ ID::Misc::DebugNotification };
		return func(a_notification, a_soundToPlay, a_cancelIfAlreadyQueued, a_arg4);
	}

	Setting* GetINISetting(const std::string_view a_name)
	{
		const auto iniPrefs = INIPrefSettingCollection::GetSingleton();
		auto setting = iniPrefs ? iniPrefs->GetSetting(a_name) : nullptr;
		if (!setting) {
			const auto ini = INISettingCollection::GetSingleton();
			setting = ini ? ini->GetSetting(a_name) : nullptr;
		}

		return setting;
	}

	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		using func_t = decltype(&LookupReferenceByHandle);
		static REL::Relocation<func_t> func{ ID::Misc::LookupReferenceByHandle };
		return func(a_handle, a_refrOut);
	}

	void PlayMenuSound(const char* a_editorID, const char* a_arg3, float a_arg4)
	{
		std::uint32_t arg1 = 0;

		using func_t = void(std::uint32_t&, const char*, const char*, float);
		static REL::Relocation<func_t> func{ ID::Misc::PlayMenuSound };
		return func(arg1, a_editorID, a_arg3, a_arg4);
	}
}
