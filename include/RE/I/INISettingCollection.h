#pragma once

#include "RE/S/Setting.h"
#include "RE/S/SettingCollectionList.h"
#include "RE/S/SettingCollectionMap.h"

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

		std::string ToLowerStrV(std::string_view _sourceStringView)
		{
			std::string _sourceString = "";
			if (_sourceStringView.empty()) {
				return _sourceString;
			}
			_sourceString = { _sourceStringView.begin(), _sourceStringView.end() };
			if (_sourceString.length() <= 0) {
				return "";
			}
			std::transform(_sourceString.begin(), _sourceString.end(), _sourceString.begin(),
				[](unsigned char c) -> char { return static_cast<char>(::tolower(c)); });
			return _sourceString;
		}

		[[nodiscard]] Setting* GetSetting(std::string_view a_name)
		{
			for (auto& setting : settings) {
				if (ToLowerStrV(setting->GetKey()) == ToLowerStrV(a_name)) {
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

	class GameSettingCollection :
		public SettingCollectionMap<Setting>  // 000
	{
	public:
		SF_RTTI_VTABLE(GameSettingCollection);

		virtual ~GameSettingCollection();  // 000


		[[nodiscard]] static GameSettingCollection* GetSingleton()
		{
			REL::Relocation<GameSettingCollection**> singleton{ REL::ID(879099) };
			return *singleton;
		}

	};
}
