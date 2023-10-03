#pragma once

#include "RE/S/SettingCollectionList.h"

namespace RE
{
	class INISettingCollection :
		public SettingCollectionList<Setting>  // 000
	{
	public:
		SF_RTTI_VTABLE(INISettingCollection);

		virtual ~INISettingCollection();  // 000

		[[nodiscard]] static INISettingCollection* GetSingleton()
		{
			REL::Relocation<INISettingCollection**> singleton{ REL::ID(885862) };
			return *singleton;
		}

		[[nodiscard]] Setting* GetSetting(const std::string_view a_name)
		{
			for (auto& setting : settings) {
				if (setting->GetKey() == a_name) {
					return setting;
				}
			}

			return nullptr;
		}
	};
}
