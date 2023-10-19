#include "RE/M/Misc.h"

namespace RE
{
	void DebugNotification(const char* a_notification, const char* a_soundToPlay, bool a_cancelIfAlreadyQueued, bool a_arg4)
	{
		using func_t = decltype(&DebugNotification);
		REL::Relocation<func_t> func{ REL::ID(138728) };
		return func(a_notification, a_soundToPlay, a_cancelIfAlreadyQueued, a_arg4);
	}

	void PlayMenuSound(const char* a_editorID, const char* a_arg3, float a_arg4)
	{
		std::uint32_t arg1 = 0;

		using func_t = void(std::uint32_t&, const char*, const char*, float);
		REL::Relocation<func_t> func{ REL::ID(167344) };
		return func(arg1, a_editorID, a_arg3, a_arg4);
	}
}
