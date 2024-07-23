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
			REL::Relocation<INIPrefSettingCollection**> singleton{ REL::ID(885866) };
			return *singleton;
		}
	};
}
