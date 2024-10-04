#pragma once

#include "RE/S/Setting.h"
#include "RE/S/SettingCollectionMap.h"

namespace RE
{
	class GameSettingCollection :
		public SettingCollectionMap<Setting>  // 000
	{
	public:
		SF_RTTI_VTABLE(GameSettingCollection);

		virtual ~GameSettingCollection();  // 000

		[[nodiscard]] static GameSettingCollection* GetSingleton()
		{
			REL::Relocation<GameSettingCollection**> singleton{ ID::GameSettingCollection::Singleton };
			return *singleton;
		}

		[[nodiscard]] Setting* GetSetting(const char* a_name)
		{
			using func_t = Setting* (*)(GameSettingCollection*, const char*);
			static REL::Relocation<func_t> func{ ID::GameSettingCollection::GetSetting };
			return func(this, a_name);
		}

		template <class T>
		T GetSetting(const std::string_view a_name, T a_fallback, const bool a_default = false)
		{
			if (const auto setting = GetSetting(a_name.data())) {
				return setting->GetValue(a_fallback, a_default);
			}

			return a_fallback;
		}

		template <class T>
		bool SetSetting(const std::string_view a_name, T a_value)
		{
			if (const auto setting = GetSetting(a_name.data())) {
				return setting->SetValue(a_value);
			}

			return false;
		}
	};
}
