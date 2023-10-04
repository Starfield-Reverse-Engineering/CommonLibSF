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
			REL::Relocation<RegSettingCollection**> singleton{ REL::ID(885510) };
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
	};
}
