#pragma once

#include "RE/I/INISettingCollection.h"

namespace RE
{
	class INIPrefSettingCollection :
		public INISettingCollection  // 000
	{
	public:
		SF_RTTI_VTABLE(INIPrefSettingCollection);

		virtual ~INIPrefSettingCollection();  // 000

		[[nodiscard]] static INIPrefSettingCollection* GetSingleton()
		{
			static REL::Relocation<INIPrefSettingCollection**> singleton{ ID::INIPrefSettingCollection::Singleton };
			return *singleton;
		}
	};
}
