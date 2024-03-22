#pragma once

namespace RE
{
	class BGSSaveLoadManager
	{
		static BGSSaveLoadManager* GetSingleton()
		{
			static REL::Relocation<BGSSaveLoadManager**> singleton{ REL::ID(880997) };
			return *singleton;
		}

		bool DeleteSaveFile(const char* a_filename, void* a_unk1, bool a_unk2)
		{
			using func_t = decltype(&BGSSaveLoadManager::DeleteSaveFile);
			REL::Relocation<func_t> func{ REL::ID(147844) };
			return func(this, a_filename, a_unk1, a_unk2);
		}
	};
}
