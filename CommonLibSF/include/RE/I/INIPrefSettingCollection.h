#pragma once

#include "RE/I/INISettingCollection.h"

namespace RE
{
	class INIPrefSettingCollection : public INISettingCollection
	{
	public:
		SF_RTTI_VTABLE(INIPrefSettingCollection);

		[[nodiscard]] static INIPrefSettingCollection* GetSingleton()
		{
			REL::Relocation<INIPrefSettingCollection**> singleton{ REL::ID(885866) };
			return *singleton;
		}

		virtual ~INIPrefSettingCollection();
	};
	static_assert(sizeof(INIPrefSettingCollection) == 0x160);
}
