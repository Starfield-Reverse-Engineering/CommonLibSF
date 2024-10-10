#pragma once

namespace RE
{
	class BGSSaveLoadManager
	{
	public:
		static BGSSaveLoadManager* GetSingleton()
		{
			static REL::Relocation<BGSSaveLoadManager**> singleton{ ID::BGSSaveLoadManager::Singleton };
			return *singleton;
		}

		bool DeleteSaveFile(const char* a_filename, void* a_unk1, bool a_unk2)
		{
			using func_t = decltype(&BGSSaveLoadManager::DeleteSaveFile);
			static REL::Relocation<func_t> func{ ID::BGSSaveLoadManager::DeleteSaveFile };
			return func(this, a_filename, a_unk1, a_unk2);
		}
	};
}
