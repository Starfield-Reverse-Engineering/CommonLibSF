#pragma once

#include "RE/B/BSTList.h"
#include "RE/S/Settings.h"

namespace RE
{
	template <typename T>
	class SettingCollection
	{
	public:
		virtual ~SettingCollection();

		// add
		virtual void Add(T* a_setting) = 0;           // 01
		virtual void Remove(T* a_setting) = 0;        // 02
		virtual void Unk_03() = 0;                    // 03
		virtual void WriteSetting(T& a_setting) = 0;  // 04
		virtual void ReadSetting(T& a_setting) = 0;   // 05
		virtual bool Open();                          // 06
		virtual bool Close();                         // 07
		virtual bool ReadSettingsFromProfile();       // 08
		virtual void Unk_09();                        // 09
		virtual bool WriteSettings();                 // 0A
		virtual bool ReadSettings();                  // 0B

		// members
		char            settingFile[260];  // 008
		std::uint32_t   pad10C;            // 10C
		void*           handle;            // 110
		BSSimpleList<T> settings;          // 118
		std::uint64_t   unk128;            // 128
		std::uint64_t   unk130;            // 130
	};
	extern template class SettingCollection<Setting>;
}
