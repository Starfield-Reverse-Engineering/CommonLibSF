#pragma once

#include "RE/S/SettingCollectionList.h"

namespace RE
{
	class INISettingCollection : public SettingCollectionList<Setting>
	{
	public:
		SF_RTTI_VTABLE(INISettingCollection);

		[[nodiscard]] static INISettingCollection* GetSingleton()
		{
			REL::Relocation<INISettingCollection**> singleton{ REL::Offset(0x05913B98) };
			return *singleton;
		}

		virtual ~INISettingCollection();
	};
	static_assert(sizeof(INISettingCollection) == 0x160);
}
