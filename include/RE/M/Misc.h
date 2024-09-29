#pragma once

#include "RE/B/BSCoreTypes.h"

namespace RE
{
	template <class T>
	class NiPointer;
	class Setting;
	class TESObjectREFR;

	void DebugNotification(const char* a_notification, const char* a_soundToPlay = nullptr, bool a_cancelIfAlreadyQueued = true, bool a_arg4 = false);
	Setting* GetINISetting(const std::string_view a_name);
	bool LookupReferenceByHandle(const RefHandle& a_handle, NiPointer<TESObjectREFR>& a_refrOut);
	void PlayMenuSound(const char* a_editorID, const char* a_arg3 = nullptr, float a_arg4 = 0.0f);
}
