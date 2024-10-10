#pragma once

#include "RE/S/Setting.h"
#include "RE/S/SettingCollectionList.h"

namespace RE
{
	class RegSettingCollection :
		public SettingCollectionList<Setting>  // 000
	{
	public:
		SF_RTTI_VTABLE(RegSettingCollection);

		virtual ~RegSettingCollection();  // 000

		[[nodiscard]] static RegSettingCollection* GetSingleton()
		{
			static REL::Relocation<RegSettingCollection**> singleton{ ID::RegSettingCollection::Singleton };
			return *singleton;
		}

		[[nodiscard]] Setting* GetSetting(const std::string_view a_name)
		{
			for (const auto& setting : settings) {
				if (setting->GetKey() == a_name) {
					return setting;
				}
			}

			return nullptr;
		}

		template <class T>
		T GetSetting(const std::string_view a_name, T a_fallback, const bool a_default = false)
		{
			if (const auto setting = GetSetting(a_name)) {
				return setting->GetValue(a_fallback, a_default);
			}

			return a_fallback;
		}

		template <class T>
		bool SetSetting(const std::string_view a_name, T a_value)
		{
			if (const auto setting = GetSetting(a_name)) {
				return setting->SetValue(a_value);
			}

			return false;
		}
	};
}
