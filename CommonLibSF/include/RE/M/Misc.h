#pragma once

namespace RE
{
	void DebugNotification(const char* a_notification, const char* a_soundToPlay = nullptr, bool a_cancelIfAlreadyQueued = true, bool a_arg4 = false);
	void PlayMenuSound(const char* a_editorID, const char* a_arg3 = nullptr, float a_arg4 = 0.0f);
}
